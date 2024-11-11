#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5010;
long long dp[maxn], n, mp[maxn], a[maxn], sum[maxn], cnt;
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]), mp[i] = a[i];
  sort(mp + 1, mp + n + 1);
  long long cnt = unique(mp + 1, mp + n + 1) - mp - 1;
  sum[0] = sum[cnt + 1] = 1e13;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= cnt; j++) {
      dp[j] = sum[j] + abs(mp[j] - a[i]);
      sum[j] = min(sum[j - 1], dp[j]);
    }
  printf("%lld\n", sum[cnt]);
  return 0;
}
