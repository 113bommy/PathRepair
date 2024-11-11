#include<iostream>
using namespace std;
int main() {
	float syo, dai, c;
	dai = -1;
	syo = 1999999;
	while (cin >> c) {
		if (dai <= c) {
			dai = c;
		}
		if (syo >= c) {
			syo = c;
		}
	}
	cout << dai - syo << endl;
}
