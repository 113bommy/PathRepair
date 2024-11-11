#include <iostream>
using namespace std;
int main() {
	int M, D;
	scanf("2019/%d/%d", &M, &D);
	cout << (M < 4 || (M == 4 && D <= 30) ? "Heisei" : "TBD") << endl;
}