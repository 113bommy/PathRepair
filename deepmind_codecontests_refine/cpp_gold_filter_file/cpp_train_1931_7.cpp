#include <bits/stdc++.h>
using namespace std;
int n, m, k;
string s, t;
int dp[1001][1001][11][2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  string s, t;
  cin >> s >> t;
  for (int i = 1; i <= k; i++)
    dp[1][0][i][0] = -1, dp[1][0][i][1] = -1, dp[0][1][i][0] = -1,
    dp[0][1][i][1] = -1, dp[0][0][i][0] = -1, dp[0][0][i][1] = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int h = 1; h <= k; h++) {
        dp[i][j][h][0] = max(dp[i - 1][j][h][0],
                             max(dp[i - 1][j][h][1],
                                 max(dp[i][j - 1][h][0], dp[i][j - 1][h][1])));
        if (s[i - 1] == t[j - 1]) {
          if (dp[i - 1][j - 1][h][1] != -1)
            dp[i][j][h][1] = dp[i - 1][j - 1][h][1] + 1;
          if (dp[i - 1][j - 1][h - 1][0] != -1 ||
              dp[i - 1][j - 1][h - 1][1] != -1)
            dp[i][j][h][1] = max(
                dp[i - 1][j - 1][h][1] + 1,
                max(dp[i - 1][j - 1][h - 1][0], dp[i - 1][j - 1][h - 1][1]) +
                    1);
        }
      }
    }
  }
  cout << max(dp[n][m][k][0], dp[n][m][k][1]);
}
