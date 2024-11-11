#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, k;
int dp[1005][1005][5] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  dp[1][1][0] = dp[1][1][1] = 1;
  dp[1][2][3] = dp[1][2][2] = 1;
  cin >> n >> k;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j][0] = (dp[i - 1][j - 1][1] + dp[i - 1][j][0] + dp[i - 1][j][2] +
                     dp[i - 1][j][3]) %
                    mod;
      dp[i][j][1] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j][2] +
                     dp[i - 1][j][3]) %
                    mod;
      if (j >= 2)
        dp[i][j][2] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] +
                       dp[i - 1][j][2] + dp[i - 1][j - 2][3]) %
                      mod;
      else
        dp[i][j][2] = 0;
      if (j >= 2)
        dp[i][j][3] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] +
                       dp[i - 1][j - 2][2] + dp[i - 1][j][3]) %
                      mod;
      else
        dp[i][j][3] = 0;
    }
  }
  cout << (dp[n][k][1] + dp[n][k][2] + dp[n][k][3] + dp[n][k][0]) % mod;
  return 0;
}
