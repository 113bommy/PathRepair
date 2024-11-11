#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int dp[2][maxn][maxn][11];
string s;
string t;
int n;
int m;
int k;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  cin >> s >> t;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int w = 1; w <= k; w++) {
        dp[0][i][j][w] =
            max(max(dp[1][i - 1][j - 1][w], dp[0][i - 1][j - 1][w]),
                max(max(dp[0][i][j - 1][w], dp[1][i][j - 1][w]),
                    max(dp[1][i - 1][j][w], dp[0][i - 1][j][w])));
        if (s[i - 1] == t[j - 1]) {
          dp[1][i][j][w] = max(
              dp[1][i - 1][j - 1][w - 1] + 1,
              max(dp[0][i - 1][j - 1][w - 1] + 1, dp[1][i - 1][j - 1][w] + 1));
        }
      }
    }
  }
  cout << max(dp[0][n][m][k], dp[1][n][m][k]);
  return 0;
}
