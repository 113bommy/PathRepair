#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
const int STATES = 4;
const int MOD = 998244353;
long long dp[MAX + 1][2 * MAX + 1][STATES];
void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long count(int n, int k) {
  dp[1][1][0] = dp[1][2][1] = dp[1][2][2] = dp[1][1][3] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] +
                     dp[i - 1][j - 1][3]) %
                    MOD;
      dp[i][j][1] =
          (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j - 1][3]) % MOD;
      dp[i][j][2] =
          (dp[i - 1][j - 1][0] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % MOD;
      dp[i][j][3] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j][2] +
                     dp[i - 1][j][3]) %
                    MOD;
      if (j - 2 >= 0) {
        dp[i][j][1] += dp[i - 1][j - 2][2], dp[i][j][1] %= MOD;
        dp[i][j][2] += dp[i - 1][j - 2][1], dp[i][j][2] %= MOD;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= STATES; i++) ans += dp[n][k][i];
  return (ans % MOD);
}
int main() {
  fast_io();
  int n, k;
  cin >> n >> k;
  cout << count(n, k) << '\n';
  return 0;
}
