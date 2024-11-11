#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
const long long inf = 1e9;
long long n, m, k;
long long a[maxn], x[maxn], y[maxn];
long long dp[maxn], sum[maxn];
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  for (long long i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (long long i = 1; i <= m; i++) scanf("%I64d%I64d", &x[i], &y[i]);
  sort(a + 1, a + n + 1);
  sum[0] = 0;
  for (long long i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  for (long long i = 0; i <= n; i++) dp[i] = 0;
  for (long long i = 1; i <= k; i++) {
    for (long long j = 1; j <= m; j++) {
      if (i > x[j])
        dp[i] = max(dp[i], dp[i - x[j]] + sum[i - x[j] + y[j]] - sum[i - x[j]]);
    }
  }
  long long ans = inf;
  for (long long i = 1; i <= k; i++) ans = min(ans, sum[k] - dp[i]);
  printf("%I64d\n", ans);
  return 0;
}
