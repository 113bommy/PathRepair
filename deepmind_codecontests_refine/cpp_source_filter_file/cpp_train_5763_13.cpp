#include <bits/stdc++.h>
using namespace std;
const long long N = 1000;
long long a[N + 3][N + 3], si[N + 3], sj[N + 3], n, m, ansi, ansj;
long long fi[N + 3], fj[N + 3], ans;
long long sqr(long long x) { return x * x; }
long long Calc(long long x, long long y) {
  return sqr(x * 4 - ((y - 1) * 4 + 2));
}
int main() {
  scanf("%I64d%I64d", &n, &m);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) scanf("%I64d", &a[i][j]);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) si[i] += a[i][j], sj[j] += a[i][j];
  for (long long i = 0; i <= n; i++)
    for (long long j = 1; j <= n; j++) fi[i] += Calc(i, j) * si[j];
  for (long long i = 0; i <= m; i++)
    for (long long j = 1; j <= m; j++) fj[i] += Calc(i, j) * sj[j];
  ans = 2e16;
  for (long long i = 0; i <= n; i++)
    for (long long j = 0; j <= m; j++)
      if (fi[i] + fj[j] < ans) ans = fi[i] + fj[j], ansi = i, ansj = j;
  printf("%I64d\n%I64d %I64d", ans, ansi, ansj);
}
