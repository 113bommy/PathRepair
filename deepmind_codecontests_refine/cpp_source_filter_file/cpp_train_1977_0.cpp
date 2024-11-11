#include <iostream>
#include <string>
using namespace std;

//x -> "ABC"
string operate(string &s, char x) {
	string t;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == x) { t += "ABC"; }
		else { t += s[i]; }
	}
	return t;
}

//"ABC" -> x
string inverse(string &s, char x) {
	string t;
	for (int i = 0; i < s.length(); ) {
		if (i + 2 < s.length() && s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
			t += x;
			i += 3;
		}
		else {
			t += s[i];
			i++;
		}
	}
	return t;
}

//is all char appeared?
bool check(string &s) {
	int cnt[3] = {0};
	for (int i = 0; i < s.length(); i++) {
		cnt[s[i] - 'A']++;
	}
	return (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0);
}

int main() {
	string s;
	cin >> s;
	
	while (true) {
		if (!check(s)) { break; }
		if (s == "ABC") { cout << "Yes" << endl; return 0; }
		
		char last = 'z';
		for (char x = 'A'; x <= 'C'; x++) {
			if (operate(inverse(s, x), x) == s) {
				last = x;
				break;
			}
		}
		if (last == 'z') break;
		
		s = inverse(s, last);
	}
	
	cout << "No" << endl;
	return 0;
}