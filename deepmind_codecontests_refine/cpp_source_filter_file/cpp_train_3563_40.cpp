#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  char ch = getchar();
  x = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
const long long N = 88, K = 12;
long long n, k, res = 1e18, a[N][N], co[N], d[N][K];
mt19937 qwq(time(0));
void work() {
  for (long long i = 1; i <= n; ++i) co[i] = qwq() & 1;
  memset(d, 0x3f, sizeof(d));
  d[1][0] = 0;
  for (long long t = 1; t <= k; ++t)
    for (long long i = 1; i <= n; ++i)
      for (long long j = 1; j <= n; ++j)
        if (co[i] ^ co[j]) d[i][t] = min(d[i][t], d[j][t - 1] + a[j][i]);
  res = min(res, d[1][k]);
}
signed main() {
  read(n), read(k);
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= n; ++j) read(a[i][j]);
  for (long long i = 1; i <= 300; ++i) work();
  return printf("%lld\n", res), 0;
}
