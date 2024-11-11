#include <bits/stdc++.h>
using namespace std;
long long mo, n, m, k, ff[510 * 510], po[510 * 510], c1, c2;
char s[510][510];
long long fd(long long x) { return !ff[x] ? x : ff[x] = fd(ff[x]); }
long long id(long long x, long long y) { return (x - 1) * (n + 1) + y; }
long long qp(long long x, long long y) {
  long long r = 1;
  for (; y; y >>= 1, x = x * x % mo)
    if (y & 1) r = r * x % mo;
  return r;
}
struct no {
  long long a[510][510];
  void ad(long long x, long long y) {
    a[x][x] = (a[x][x] + 1) % mo;
    a[y][y] = (a[y][y] + 1) % mo;
    a[x][y] = (a[x][y] + mo - 1) % mo;
    a[y][x] = (a[y][x] + mo - 1) % mo;
  }
  long long gs(long long n) {
    long long ans = 1;
    for (long long i = 1; i < n; i++) {
      long long p = i;
      if (!a[i][i]) {
        for (long long j = i + 1; j < n; j++)
          if (a[j][i]) {
            p = j;
            break;
          }
      }
      if (p != i) {
        swap(a[p], a[i]);
        ans = mo - ans;
      }
      for (long long j = 1 + i; j < n; j++) {
        long long va = a[j][i] * qp(a[i][i], mo - 2) % mo;
        for (long long k = i; k < n; k++)
          a[j][k] = (a[j][k] - a[i][k] * va % mo + mo) % mo;
      }
    }
    for (long long i = 1; i < n; i++) ans = ans * a[i][i] % mo;
    return ans;
  }
} g[2];
signed main() {
  scanf("%lld%lld%lld", &n, &m, &mo);
  for (long long i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      if (s[i][j] == '/') {
        long long xx = fd(id(i + 1, j)), yy = fd(id(i, j + 1));
        if (xx != yy) ff[xx] = yy;
      } else if (s[i][j] == '\\') {
        long long xx = fd(id(i + 1, j + 1)), yy = fd(id(i, j));
        if (xx != yy) ff[xx] = yy;
      }
    }
  for (long long i = 1; i <= n + 1; i++)
    for (long long j = 1; j <= m + 1; j++)
      if (fd(id(i, j)) == id(i, j)) {
        if ((i + j) & 1)
          po[id(i, j)] = ++c2;
        else
          po[id(i, j)] = ++c1;
      }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++)
      if (s[i][j] == '*') {
        g[(i + j) & 1].ad(po[fd(id(i, j))], po[fd(id(i + 1, j + 1))]);
        g[(i + j + 1) & 1].ad(po[fd(id(i, j + 1))], po[fd(id(i + 1, j))]);
      }
  printf("%lld", (g[0].gs(c1) + g[1].gs(c2)) % mo);
}
