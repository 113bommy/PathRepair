#include <bits/stdc++.h>
using namespace std;
long long dp[2][1005][105];
int main() {
  int n, k, mod;
  scanf("%d%d%d", &n, &k, &mod);
  memset(dp, 0, sizeof(dp));
  for (int i = (n == 1); i <= 9; i++) {
    int t = i % k;
    if (t == 0 && i)
      dp[1][1][t] += 1;
    else
      dp[0][1][t] += 1;
  }
  int ten = 1;
  for (int i = 1; i < n; i++) {
    ten *= 10;
    ten %= k;
    for (int j = 0; j < k; j++) {
      for (int a = (i == n - 1); a <= 9; a++) {
        int t = (a * ten + j) % k;
        if (t == 0 && a > 0) {
          dp[1][i + 1][t] = (dp[1][i + 1][t] + dp[1][i][j] + dp[0][i][j]) % mod;
        } else {
          dp[0][i + 1][t] = (dp[0][i + 1][t] + dp[0][i][j]) % mod;
          dp[1][i + 1][t] = (dp[1][i + 1][t] + dp[1][i][j]) % mod;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < k; i++) ans = (ans + dp[1][n][i]) % mod;
  cout << ans << endl;
  return 0;
}
