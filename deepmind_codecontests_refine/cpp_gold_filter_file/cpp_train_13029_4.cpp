#include <bits/stdc++.h>
int f[3010][3010], a[200010], w[200010], inv[3010 << 1], n, m, i, j, x, y,
    s0 = 0, s1 = 0, inv0, inv1, ans1 = 0, ans0 = 0;
int power(int x, int y) {
  int s = 1, i = x;
  for (; y; y >>= 1) {
    if (y & 1) s = 1LL * s * i % 998244353;
    i = 1LL * i * i % 998244353;
  }
  return s;
}
inline void add(int &x, int y) {
  x += y;
  if (x >= 998244353) x -= 998244353;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    if (a[i])
      s1 += w[i];
    else
      s0 += w[i];
  }
  inv0 = power(s0, 998244353 - 2);
  inv1 = power(s1, 998244353 - 2);
  for (i = -m; i <= m; i++) inv[3010 + i] = power(s0 + s1 + i, 998244353 - 2);
  f[0][0] = 1;
  for (i = 0; i < m; i++)
    for (j = 0; j <= i; j++) {
      x = j;
      y = i - j;
      if (!f[x][y]) continue;
      add(f[x + 1][y],
          1LL * f[x][y] * (s1 + x) % 998244353 * inv[3010 + x - y] % 998244353);
      add(f[x][y + 1],
          1LL * f[x][y] * (s0 - y) % 998244353 * inv[3010 + x - y] % 998244353);
    }
  for (i = 0; i <= m; i++) {
    ans1 = (ans1 + 1LL * (s1 + i) * f[i][m - i] % 998244353) % 998244353;
    ans0 = (ans0 + 1LL * (s0 - i) * f[m - i][i] % 998244353) % 998244353;
  }
  for (i = 1; i <= n; i++)
    if (a[i])
      printf("%I64d\n", 1LL * ans1 * w[i] % 998244353 * inv1 % 998244353);
    else
      printf("%I64d\n", 1LL * ans0 * w[i] % 998244353 * inv0 % 998244353);
  return 0;
}
