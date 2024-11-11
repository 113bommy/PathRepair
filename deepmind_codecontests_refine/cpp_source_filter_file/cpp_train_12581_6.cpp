#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	string s;
	cin >> s;
	a = s.find("A");
	b = rfind("Z");
	cout << a - b << endl;
	return 0;
}