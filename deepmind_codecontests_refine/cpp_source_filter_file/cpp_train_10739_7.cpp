#include <bits/stdc++.h>
using namespace std;
long long n, m, a[505], mod = 998244353, dp[505][505], g[505][505];
int main() {
  scanf("%lld%lld", &n, &m);
  for (register int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (register int i = 1; i <= n; i++) {
    dp[i][i] = g[i][i] = dp[i][i - 1] = g[i][i - 1] = 1;
  }
  for (register int len = 2; len <= n; len++) {
    for (register int i = 1; i + len - 1 <= n; i++) {
      long long k, Min = 1ll << 60;
      for (register int j = i; j <= i + len - 1; j++) {
        if (a[j] < Min) {
          Min = a[j];
          k = j;
        }
      }
      dp[i][i + len - 1] = g[i][i + len - 1] =
          dp[i][k - 1] * dp[k + 1][i + len - 1] % mod;
      for (register int j = i; j < i + len - 1; j++) {
        dp[i][i + len - 1] =
            (dp[i][i + len - 1] + g[i][j] * dp[j + 1][i + len - 1] % mod) % mod;
      }
    }
  }
  printf("%lld\n", dp[1][n]);
  return 0;
}
