#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int dp[110][110][2];
int main() {
  ios::sync_with_stdio(false);
  int n, m, d;
  while (cin >> n >> m >> d) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 1; k <= m; k++) {
          if (j + k > n) break;
          if (k < d)
            dp[i + 1][j + k][0] = (dp[i + 1][j + k][0] + dp[i][j][0]) % MOD;
          else
            dp[i + 1][j + k][1] = (dp[i + 1][j + k][1] + dp[i][j][0]) % MOD;
          dp[i + 1][j + k][1] = (dp[i + 1][j + k][1] + dp[i][j][1]) % MOD;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = (ans + dp[i][n][1]) % MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
