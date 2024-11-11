#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	cout << (s == string(s.size(), s[0]) ? "No\n" : "Yes\n");
}
