#include<iostream>
#include<string>
#include<vector>

using namespace std;

void split(string s, vector<string> &v) {
	s += '"';
	string buf = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '"') {
			v.push_back(buf);
			buf = "";
		}
		else buf += s[i];
	}
}

int main() {

	while (1) {
		string S1, S2;
		cin >> S1;
		if (S1 == ".")break;
		cin >> S2;
		//すでに完全に一致ならば
		if (S1 == S2) {
			cout << "IDENTICAL" << endl;
			continue;
		}
		vector<string> v1, v2;
		split(S1, v1), split(S2, v2);

		if (v1.size() != v2.size()) {
			cout << "DIFFERENT" << endl;
			continue;
		}
		
		int cnt = 0;
		for (int i = 0; i < v1.size(); i++) {
			if (i % 2 == 0) {
				if (v1[i] != v2[i]) {
					cout << "DIFFERENT" << endl;
					goto next;
				}
			}
			else {
				if (v1[i] != v2[i]) {
					cnt++;
				}
			}
		}
		if (cnt > 1) {
			cout << "DIFFERENT" << endl;
		}
		else {
			cout << "CLOSE" << endl;
		}
	next:;
	}
	
	return 0;
}
