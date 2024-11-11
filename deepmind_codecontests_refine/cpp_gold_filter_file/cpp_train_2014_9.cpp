#include <bits/stdc++.h>
using namespace std;
long long x, n, m, Mod, ten, t;
long long f[2005], a[2005], b[2005];
long long add(long long x, long long y) {
  x += y;
  if (x >= Mod) x -= Mod;
  return x;
}
long long mul(long long x, long long y) {
  long long s = 0;
  while (y) {
    if (y & 1) s = add(s, x);
    y >>= 1;
    x = add(x, x);
  }
  return s;
}
struct mat {
  long long g[3][3];
  int n, m;
  mat operator*(const mat &o) {
    mat c;
    c.n = n;
    c.m = o.m;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= o.m; ++j) {
        c.g[i][j] = 0;
        for (int k = 1; k <= m; ++k)
          c.g[i][j] = add(c.g[i][j], mul(g[i][k], o.g[k][j]));
      }
    return c;
  }
} c, y;
long long get(long long k) {
  c.n = 1;
  c.m = 2;
  c.g[1][1] = 0;
  c.g[1][2] = 1;
  y.n = 2;
  y.m = 2;
  y.g[1][1] = 0;
  y.g[1][2] = 1;
  y.g[2][1] = 1;
  y.g[2][2] = 1;
  while (k) {
    if (k & 1) c = c * y;
    k >>= 1;
    y = y * y;
  }
  return c.g[1][1];
}
int main() {
  cin >> x;
  f[0] = 0;
  f[1] = 1;
  Mod = 1000;
  for (int i = 2; i <= 1500; ++i) f[i] = add(f[i - 1], f[i - 2]);
  for (int i = 0; i <= 1499; ++i) {
    if (f[i] % 1000 == x % 1000) a[++n] = i;
  }
  t = 1500;
  for (int k = 4; k <= 13; ++k) {
    Mod *= 10;
    for (int i = 1; i <= n; ++i) b[i] = a[i];
    m = n;
    n = 0;
    for (int i = 1; i <= m; ++i) {
      long long j = b[i], tmp;
      for (int z = 1; z <= 10; ++z) {
        tmp = get(j);
        if (tmp == x % Mod) a[++n] = j;
        j += t;
      }
    }
    t *= 10;
  }
  if (n == 0)
    puts("-1");
  else {
    sort(a + 1, a + 1 + n);
    printf("%I64d\n", a[1]);
  }
  return 0;
}
