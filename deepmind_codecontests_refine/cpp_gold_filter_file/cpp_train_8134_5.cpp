#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long n, m, k, a[N], y[2005], dp[2005];
signed main() {
  long long i, j, u, v, ans = 0;
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; i++) a[i] += a[i - 1];
  for (i = 1; i <= m; i++)
    scanf("%I64d%I64d", &u, &v), u <= 2000 ? y[u] = max(y[u], v) : 0;
  for (i = 1; i <= 2000; i++) y[i] = i - y[i];
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for (i = 0; i <= k - 1; i++) {
    for (j = 1; j <= 2000; j++)
      if (i + j <= 2000) {
        dp[i + j] = min(dp[i + j], dp[i] + a[i + j] - a[i + j - y[j]]);
      }
  }
  printf("%I64d", dp[k]);
  return 0;
}
