#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	string s;
	while (cin >> n, n) {
		cin >> s;
		
		for (int x = 0;x < n;x++) {
			s += '@';
			string sg="";

			char now = s[0];
			int ko = 0;

			for (int i = 0;i < s.size();i++) {
				if (s[i] == now)ko++;
				else {
					string sa = to_string(ko);
					sg += sa;
					sg.push_back(now);
					now = s[i];
					ko = 1;
				}
			}
			s = sg;
		}

		cout << s << endl;

	}
	return 0;
}