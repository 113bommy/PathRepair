#include <string>
#include <iostream>
using namespace std;
string s; int c;
int main() {
	while(cin >> s) {
		if(c++) printf("\n");
		while(s.size() != 5) s = "0" + s;
		for(int i = 0; i < 5; i++) printf("%c", s[i] < '5' ? '*' : ' '); printf("\n");
		for(int i = 0; i < 5; i++) printf("%c", s[i] > '4' ? '*' : ' '); printf("\n");
		printf("=====\n");
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) printf("%c", (s[i] - 48) % 5 == i ? ' ' : '*'); pritf("\n");
		}
	}
}