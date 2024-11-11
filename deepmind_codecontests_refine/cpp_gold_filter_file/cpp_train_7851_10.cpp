#include <bits/stdc++.h>
using namespace std;
const long long ha = 1e9 + 7, N = 1e5 + 10;
long long n, m;
long long a[N], sum[N][102], l, r, k, pre[N][102];
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  pre[1][0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= 101; j++)
      pre[i][j] = (pre[i - 1][j] + pre[i][j - 1]) % ha;
  }
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld%lld", &l, &r, &k);
    sum[l][k + 1]++;
    for (long long j = 0; j <= k; j++)
      (sum[r + 1][k + 1 - j] += ha - pre[r - l + 1][j + 1]) %= ha;
  }
  for (long long i = 101; i; i--) {
    for (long long j = 1; j <= n; j++)
      sum[j][i] = (sum[j][i] + sum[j - 1][i]) % ha,
      sum[j][i - 1] = (sum[j][i - 1] + sum[j][i]) % ha;
  }
  for (long long i = 1; i <= n; i++) printf("%lld ", (a[i] + sum[i][0]) % ha);
  return 0;
}
