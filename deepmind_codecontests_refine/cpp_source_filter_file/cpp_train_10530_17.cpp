#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long M = 1e9 + 7;
long long n, m, k;
long long dp[N][20][1 << 4];
int main() {
  scanf("%lld%lld%lld", &n, &k, &m);
  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int mask = 0; mask < 1 << m; ++mask) {
        long long MASK = (mask << 1) % (1 << m);
        (dp[i + 1][j][mask] += dp[i][j][mask]) %= M;
        long long num = __builtin_popcount(mask) + 1;
        (dp[i + 1][j + 1][MASK | 1] += dp[i][j][mask] * num) %= M;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < 1 << m; ++i) {
    (ans += dp[n][k][i]) %= M;
  }
  printf("%lld", ans);
  return 0;
}
