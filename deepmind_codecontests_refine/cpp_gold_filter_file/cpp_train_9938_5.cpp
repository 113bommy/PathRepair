#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
long long dp[N][N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  int x = abs(a - b);
  for (int i = a; i <= n; i++) dp[0][i] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i][j - 1];
      if (j == b) continue;
      int z = abs(j - b);
      if (z & 1)
        z >>= 1;
      else
        z = (z >> 1) - 1;
      if (b < j) {
        dp[i][j] += dp[i - 1][n] - dp[i - 1][j - z - 1];
        dp[i][j] += 1000000007;
        dp[i][j] %= 1000000007;
      } else {
        dp[i][j] += dp[i - 1][j + z] - dp[i - 1][0];
        dp[i][j] += 1000000007;
        dp[i][j] %= 1000000007;
      }
      dp[i][j] -= dp[i - 1][j] - dp[i - 1][j - 1];
      dp[i][j] += 1000000007;
      dp[i][j] %= 1000000007;
    }
  }
  cout << dp[k][n];
  return 0;
}
