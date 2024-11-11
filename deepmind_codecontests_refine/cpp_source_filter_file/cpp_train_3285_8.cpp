#include <bits/stdc++.h>
const int MAXN = 300;
const int P = 998244353;
int qpow(int n, int k) {
  int r = 1;
  while (k) {
    if (k & 1) r = 1ll * r * n % P;
    n = 1ll * n * n % P, k >>= 1;
  }
  return r;
}
int n;
namespace DSU {
int f[MAXN];
void init() {
  for (int i = 1; i <= n; i++) f[i] = i;
}
int getf(int x) {
  if (x == f[x]) return x;
  return f[x] = getf(f[x]);
}
bool merge(int u, int v) {
  int x = getf(u), y = getf(v);
  if (x == y) return 0;
  f[x] = y;
  return 1;
}
}  // namespace DSU
int a[MAXN], b[MAXN];
bool tag[MAXN], in[MAXN], out[MAXN];
int fac[MAXN], ifac[MAXN];
int s[MAXN][MAXN];
int f[MAXN], g[MAXN], h[MAXN], ans[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  DSU::init();
  int cnt = 0, c1 = 0, c2 = 0, c3 = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] && b[i] && !DSU::merge(a[i], b[i])) tag[DSU::f[a[i]]] = 1, cnt++;
  for (int i = 1; i <= n; i++)
    if (a[i] && !b[i])
      out[DSU::getf(a[i])] = 1;
    else if (!a[i] && b[i])
      in[DSU::getf(b[i])] = 1;
    else if (!a[i] && !b[i])
      c3++;
  for (int i = 1; i <= n; i++)
    if (i == DSU::getf(i) && !tag[i]) {
      if (in[i] && out[i])
        c3++;
      else if (in[i])
        c2++;
      else if (out[i])
        c1++;
    }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
  ifac[n] = qpow(fac[n], P - 2);
  for (int i = n; i >= 1; i--) ifac[i - 1] = 1ll * ifac[i] * i % P;
  s[0][0] = 1;
  for (int i = 0; i <= n; i++)
    for (int j = 1; j <= i; j++)
      s[i][j] = (1ll * (i - 1) * s[i - 1][j] + s[i - 1][j - 1]) % P;
  if (c3 == 0) {
    for (int i = 0; i <= c1; i++) f[i] = s[c1][i];
    for (int i = 0; i <= c2; i++) g[i] = s[c2][i];
  } else {
    for (int i = 0; i <= c1; i++)
      for (int j = i; j <= c1; j++)
        f[i] =
            (f[i] + 1ll * fac[c1] * ifac[j] % P * ifac[c1 - j] % P * s[j][i] %
                        P * fac[c1 + c3 - j - 1] % P * ifac[c3 - 1]) %
            P;
    for (int i = 0; i <= c2; i++)
      for (int j = i; j <= c2; j++)
        g[i] =
            (g[i] + 1ll * fac[c2] * ifac[j] % P * ifac[c2 - j] % P * s[j][i] %
                        P * fac[c2 + c3 - j - 1] % P * ifac[c3 - 1]) %
            P;
  }
  for (int i = c1; i >= 0; i--)
    for (int j = 1; j <= c2; j++) f[i + j] = (f[i + j] + 1ll * f[i] * g[j]) % P;
  for (int i = 0; i <= c3; i++) {
    int t = 1ll * s[c3][i] * fac[c3] % P;
    for (int j = 0; j <= c1 + c2; j++)
      ans[i + j] = (ans[i + j] + 1ll * f[j] * t) % P;
  }
  for (int i = 0; i < n; i++)
    printf("%d ", n - i - cnt >= 0 ? ans[n - i - cnt] : 0);
  putchar('\n');
  return 0;
}
