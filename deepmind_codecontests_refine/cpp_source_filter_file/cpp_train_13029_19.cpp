#include <bits/stdc++.h>
using namespace std;
int const p = 998244353;
int f[3005][3005], g[3005][3005], a[3005], w[3005];
int pw(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % p;
    x = 1ll * x * x % p;
    y >>= 1;
  }
  return res;
}
int main() {
  int n, m, s = 0, s0 = 0, s1 = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    scanf("%d", &w[i]), (a[i] ? s1 : s0) += w[i], s += w[i];
  for (int i = 0; i <= m; i++) f[i][m - i] = g[i][m - i] = 1;
  for (int i = m - 1; i >= 0; i--)
    for (int a = 0; a <= i; a++) {
      int b = i - a, t = pw(s0 + s1 + a - b, p - 2);
      if (b > s0) continue;
      f[a][b] = (1ll * (s1 + a + 1) * t % p * f[a + 1][b] +
                 1ll * (s0 - b) * t % p * f[a][b + 1]) %
                p;
      g[a][b] = (1ll * (s1 + a) * t % p * g[a + 1][b] +
                 1ll * (s0 - b - 1) * t % p * g[a][b + 1]) %
                p;
    }
  for (int i = 1; i <= n; i++)
    printf("%lld\n", 1ll * (a[i] ? f[0][0] : g[0][0]) * w[i] % p);
  return 0;
}
