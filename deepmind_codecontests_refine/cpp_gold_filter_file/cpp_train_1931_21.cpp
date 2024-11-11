#include <bits/stdc++.h>
using namespace std;
const short int M = 1005;
short int last[2][M][M];
short int dp[2][M][M];
int32_t main() {
  int n, m, k;
  cin >> n >> m >> k;
  string s, t;
  cin >> s >> t;
  s = " " + s, t = " " + t;
  for (int p = 1; p <= k; p++) {
    for (int f = 0; f <= 1; f++)
      for (int i = 1; i < s.size(); i++)
        for (int j = 1; j < t.size(); j++) last[f][i][j] = dp[f][i][j];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i < s.size(); i++)
      for (int j = 1; j < t.size(); j++) {
        ((dp[0][i][j]) = max((dp[0][i][j]), (dp[0][i - 1][j])));
        ((dp[0][i][j]) = max((dp[0][i][j]), (dp[0][i][j - 1])));
        ((dp[0][i][j]) = max((dp[0][i][j]), (dp[1][i - 1][j])));
        ((dp[0][i][j]) = max((dp[0][i][j]), (dp[1][i][j - 1])));
        if (s[i] == t[j]) {
          ((dp[1][i][j]) =
               max((dp[1][i][j]), ((short int)(dp[1][i - 1][j - 1] + 1))));
          ((dp[1][i][j]) =
               max((dp[1][i][j]), ((short int)(last[0][i - 1][j - 1] + 1))));
          ((dp[0][i][j]) =
               max((dp[0][i][j]), ((short int)(last[1][i - 1][j - 1] + 1))));
          ((dp[0][i][j]) =
               max((dp[0][i][j]), ((short int)(last[0][i - 1][j - 1] + 1))));
        }
      }
  }
  return cout << max(dp[1][n][m], dp[0][n][m]) << endl, 0;
}
