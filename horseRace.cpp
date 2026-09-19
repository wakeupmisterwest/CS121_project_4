#include <iostream>
#include <random>

std::random_device rd;
std::uniform_int_distribution<int> dist(0, 1);

const int TRACK_LENGTH = 15;
const int MAX_HORSES = 5;

void advance(int horseNum, int* horses);
void printLane(int horseNum, int* horses);
bool isWinner(int horseNum, int* horses);

int main() {
	int position[MAX_HORSES] = {0};
	bool keepGoing = true;

	while (keepGoing) {

		for (int i = 0; i < MAX_HORSES; i++) {
			advance(i, position);
			printLane(i, position);

			if (isWinner(i, position)) {
				std::cout << "Horse " << i << " WINS!!!" << std::endl;
				keepGoing = false;
				break;
			}
		}

		std::cout << "Press enter for another turn";
		std::cin.get();
	}
	return 0;
}

void advance(int horseNum, int* horses) {
	int coin = dist(rd);
	horses[horseNum] += coin;
}

void printLane(int horseNum, int* horses){
	for (int i = 0; i < TRACK_LENGTH; i++) {
		if (i == horses[horseNum]) {
			std::cout << horseNum;
		} else {
			std::cout << ".";
		}
	}
	std::cout << std::endl;
}

bool isWinner(int horseNum, int* horses){
	return horses[horseNum] >= (TRACK_LENGTH);
}
