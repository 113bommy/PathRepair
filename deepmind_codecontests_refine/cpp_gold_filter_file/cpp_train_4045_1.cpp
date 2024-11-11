#include<bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	set<char> sc;
	for (auto c : s) sc.insert(c);
	puts(s.size() == sc.size() ? "yes" : "no");
}