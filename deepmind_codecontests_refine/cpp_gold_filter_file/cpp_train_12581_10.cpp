#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	string s;
	cin >> s;
	a = s.find("A");
	b = s.rfind("Z");
	cout << b - a + 1<< endl;
	return 0;
}