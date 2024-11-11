#include <iostream>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int w, h;
string s[70];
string dp[70][70];

bool check(int i, int j, string &prev) {
	if (i >= h || j >= w) return false;
	if (prev.length() > 0) {
		return '0' <= s[i][j] && s[i][j] <= '9';
	}
	return '1' <= s[i][j] && s[i][j] <= '9';
}

string Max(string &a, string &b) {
	if (a.length() > b.length()) return a;
	if (b.length() > a.length()) return b;
	return max(a, b);
}

int main() {
	int i, j;
	
	while (cin >> w >> h) {
		if (!w) break;
		rep(i, h) cin >> s[i];
		rep(i, h) {
			rep(j, w) {
				if ('1' <= s[i][j] && s[i][j] <= '9') dp[i][j] = s[i][j];
				else dp[i][j] = "";
			}
		}
		
		rep(i, h) {
			rep(j, w) {
				if (check(i + 1, j, dp[i][j])) dp[i + 1][j] = Max(dp[i + 1][j], dp[i][j] + s[i + 1][j]);
				if (check(i, j + 1, dp[i][j])) dp[i][j + 1] = Max(dp[i][j + 1], dp[i][j] + s[i][j + 1]);
			}
		}
		
		string ans = "";
		rep(i, h) {
			rep(j, w) {
				ans = Max(ans, dp[i][j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
