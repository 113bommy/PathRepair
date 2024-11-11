#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int m, h, i;

	while (cin >> str, str != "-") {
		cin >> m;
		for (i = 0; i<m; i++) {
			cin >> h;
			str = str.substr(h, str.size() - h) + str.substr(0,h)
		}
		cout << str << endl;
	}
}