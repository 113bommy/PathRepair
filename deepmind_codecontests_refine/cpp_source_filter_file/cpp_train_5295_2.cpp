#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	cout << ((s.size() & 1) ^ (s[0] == s.back()) ? "First\n" : "Second\n")
}