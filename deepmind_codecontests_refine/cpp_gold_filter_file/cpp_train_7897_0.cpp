#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string s; vector<vector<int> > v; int t[100][100], dp[100][100];
vector<int> parse(string s) {
	vector<int> ret; int v = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == ',') ret.push_back(v), v = 0;
		else v = v * 10 + s[i] - 48;
	}
	ret.push_back(v);
	return ret;
}
int main() {
	while(cin >> s) v.push_back(parse(s));
	int n = v.size() / 2 + 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < v[i].size(); j++) {
			t[i - j][j] = v[i][j];
		}
	}
	for(int i = n; i < v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
			t[i - (j + n - v[i].size())][j + n - v[i].size()] = v[i][j];
		}
	}
	dp[0][0] = t[0][0];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i) dp[i][j] = dp[i - 1][j] + t[i][j];
			if(j) dp[i][j] = max(dp[i][j], dp[i][j - 1] + t[i][j]);
		}
	}
	cout << dp[n - 1][n - 1] << endl;
}