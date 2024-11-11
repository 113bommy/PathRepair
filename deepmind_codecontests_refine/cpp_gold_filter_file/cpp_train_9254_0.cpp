#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> e;
	string s;
	while (getline(cin, s), s != "END_OF_TEXT") {
		e.push_back(s);
	}
	int y = 0, x = 0;
	string buffer = "";
	char c;
	while (cin >> c, c != '-') {
		switch (c) {
			case 'a':
				x = 0;
				break;
			case 'e':
				x = e[y].size();
				break;
			case 'p':
				x = 0;
				y = max(0, y-1);
				break;
			case 'n':
				x = 0;
				y = min((int)e.size()-1, y+1);
				break;
			case 'f':
				if (x < e[y].size()) {
					++x;
				} else if (y+1 < e.size()) {
					x = 0;
					++y;
				}
				break;
			case 'b':
				if (0 < x) {
					--x;
				} else if (0 <= y-1) {
					x = e[y-1].size();
					--y;
				}
				break;
			case 'd':
				if (x < e[y].size()) {
					e[y] = e[y].substr(0,x) + e[y].substr(x+1);
				} else if (y+1 < e.size()) {
					e[y] += e[y+1];
					e.erase(e.begin()+y+1);
				}
				break;
			case 'k':
				if (x < e[y].size()) {
					buffer = e[y].substr(x);
					e[y] = e[y].substr(0,x);
					x = e[y].size();
				} else if (y+1 < e.size()) {
					buffer = "\n";
					e[y] += e[y+1];
					e.erase(e.begin()+y+1);
				}
				break;
			case 'y':
				if (buffer != "") {
					if (buffer == "\n") {
						e.insert(e.begin()+y+1, e[y].substr(x));
						e[y] = e[y].substr(0,x);
						x = 0;
						++y;
					} else {
						e[y] = e[y].substr(0,x) + buffer + e[y].substr(x);
						x += buffer.size();
					}
				}
				break;
		}
	}
	for (int i=0; i<e.size(); ++i) {
		cout << e[i] << endl;
	}
	return 0;
}