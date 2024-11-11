#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], b[200005], f[200005][20], t, ans[200005], c[200005],
    d[200005], mat[200005];
long long get(long long l, long long r) {
  long long cur = log2(r - l + 1);
  return min(f[l][cur], f[r - (1 << cur) + 1][cur]);
}
signed main() {
  scanf("%lld", &n);
  t = log2(n) + 1;
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i + n] = a[i];
  for (long long i = 1; i <= n; i++) scanf("%lld", &b[i]), b[i + n] = b[i];
  d[1] = b[n];
  for (long long i = 2; i <= n; i++) d[i] = b[n - i + 1];
  c[1] = a[1];
  for (long long i = 2; i <= n; i++) c[i] = a[n - i + 2];
  mat[1] = 1;
  for (long long i = 2; i <= n; i++) mat[i] = n - i + 2;
  for (long long i = 1; i <= 2 * n; i++)
    a[i] += a[i - 1], b[i] += b[i - 1], f[i][0] = a[i] - b[i];
  for (long long j = 1; j <= t; j++)
    for (long long i = 1; i <= 2 * n - (1 << j) + 1; i++)
      f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
  for (long long i = 1; i <= n; i++)
    if (get(i, i + n - 1) - a[i - 1] + b[i - 1] >= 0) ans[i] = 1;
  for (long long i = 1; i <= n; i++) c[i + n] = c[i], d[i + n] = d[i];
  for (long long i = 1; i <= 2 * n; i++)
    c[i] += c[i - 1], d[i] += d[i - 1], f[i][0] = c[i] - d[i];
  for (long long j = 1; j <= t; j++)
    for (long long i = 1; i <= 2 * n - (1 << j) + 1; i++)
      f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
  for (long long i = 1; i <= n; i++)
    if (get(i, i + n - 1) - c[i - 1] + d[i - 1] >= 0) ans[mat[i]] = 1;
  long long sum = 0;
  for (long long i = 1; i <= n; i++) sum += ans[i];
  printf("%lld\n", sum);
  for (long long i = 1; i <= n; i++)
    if (ans[i]) printf("%lld ", i);
  return 0;
}
