#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 1e3 + 7;
int dp[2][N][N];
int main() {
  int n, m, x;
  scanf("%d%d%d", &n, &m, &x);
  if (n > m) {
    puts("0");
    return 0;
  }
  dp[0][0][0] = 1;
  for (int i = int(0); i <= int(m - 1); ++i) {
    int cur = i & 1, nx = cur ^ 1;
    for (int j = int(0); j <= int(n); ++j)
      for (int k = int(0); k <= int(n - j); ++k) dp[nx][j][k] = 0;
    for (int j = int(0); j <= int(n); ++j)
      for (int k = int(0); k <= int(n - j); ++k)
        if (dp[cur][j][k]) {
          if (i + 1 != x) (dp[nx][j][k] += dp[cur][j][k]) %= MOD;
          (dp[nx][j + 1][k] += dp[cur][j][k]) %= MOD;
          if (j && i + 1 != x) (dp[nx][j - 1][k + 1] += dp[cur][j][k]) %= MOD;
          (dp[nx][j][k + 1] += dp[cur][j][k]) %= MOD;
        }
  }
  long long ans = (long long)dp[m & 1][0][n];
  for (int i = int(1); i <= int(n); ++i) ans = ans * i % MOD;
  cout << ans << endl;
}
