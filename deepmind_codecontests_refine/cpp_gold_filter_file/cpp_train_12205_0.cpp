#include <bits/stdc++.h>
using namespace std;
string s;
int n, m;
int dp[105][55][2] = {0};
int main() {
  int i, j, k;
  cin >> s >> m;
  n = s.size();
  memset(dp, 200, sizeof(dp));
  dp[0][0][0] = dp[0][0][1] = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j <= m; j++)
      for (k = 0; k < 2; k++) {
        dp[i + 1][j + (s[i] != 'F')][k] =
            max(dp[i + 1][j + (s[i] != 'F')][k], dp[i][j][k] + (k ? 1 : -1));
        dp[i + 1][j + (s[i] != 'T')][!k] =
            max(dp[i + 1][j + (s[i] != 'T')][!k], dp[i][j][k]);
      }
  int res = 0;
  for (i = m; i >= 0; i -= 2) {
    res = max(res, max(dp[n][i][0], dp[n][i][1]));
  }
  cout << res;
  return 0;
}
