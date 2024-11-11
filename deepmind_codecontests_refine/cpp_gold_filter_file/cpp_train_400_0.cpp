/*
	0127:Pocket Pager Input
*/
#include	<iostream>
#include	<string>

using namespace std;

const char WORDS[] = "abcdefghijklmnopqrstuvwxyz.?! ";

int main(void) {
	char WORDSET[6][5];
	int w = 0;
	
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 5; j++) {
			WORDSET[i][j] = WORDS[w];
			w++;
		}
	}
	
	while(1) {
		string str;
		string ans;
		bool fl = true;
		
		cin >> str;
		
		if( cin.eof() ) { break; }
			else if( (int)str.size() % 2 != 0 ) { cout << "NA" << endl; continue; }
		string::iterator it = str.begin();
		while( it != str.end() ) {
			int a, b;
			
			a = *it - '0' - 1;
			it++;
			b = *it - '0' - 1;
			it++;
			
			if(0 <= a && a < 6 && 0 <= b && b < 5) {
				ans += WORDSET[a][b];
			} else {
				fl = false;
				break;
			}
		}
		if(fl) {
			cout << ans << endl;
		} else {
			cout << "NA" << endl;
		}
	}
	return 0;
}