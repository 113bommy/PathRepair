#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		a = log10(a + b) + 1;
		cout << a << endl;
	}
	return 0;
}