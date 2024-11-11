#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long llread() {
  char ch = getchar();
  long long x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline int Power(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % 998244353;
    x = 1ll * x * x % 998244353;
    y >>= 1;
  }
  return ret;
}
int fac[610], inv[610], a[610], b[610], wha[610], whb[610];
int s[610][610], fa[610];
int f[610], g[610], h[610];
inline int dfs(int x) {
  if (!b[x]) return 0;
  if (!wha[b[x]]) return b[x];
  return dfs(wha[b[x]]);
}
inline int CC(int n, int m) {
  if (n < m || m < 0) return 0;
  return 1ll * fac[n] * inv[m] % 998244353 * inv[n - m] % 998244353;
}
inline int calc(int n, int m) {
  if (m == 0) return 1;
  if (n - m < 0 || n <= 0 || m < 0) return 0;
  return 1ll * fac[n] * inv[n - m] % 998244353;
}
inline int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
inline void init(int n) {
  fac[0] = fac[1] = 1;
  inv[0] = inv[1] = 1;
  for (int i = (2); i <= (n); ++i) {
    fac[i] = 1ll * fac[i - 1] * i % 998244353;
    inv[i] = 1ll * inv[998244353 % i] * (998244353 - 998244353 / i) % 998244353;
  }
  for (int i = (2); i <= (n); ++i) {
    inv[i] = 1ll * inv[i - 1] * inv[i] % 998244353;
  }
}
int main() {
  int n = read();
  for (int i = (1); i <= (n); ++i) {
    a[i] = read(), wha[a[i]] = i;
  }
  for (int i = (1); i <= (n); ++i) {
    b[i] = read(), whb[b[i]] = i;
  }
  init(n * 2);
  s[0][0] = 1;
  for (int i = (1); i <= (n); ++i) {
    for (int j = (1); j <= (i); ++j) {
      s[i][j] = (s[i - 1][j - 1] + 1ll * (i - 1) * s[i - 1][j]) % 998244353;
    }
  }
  int A = 0, B = 0, C = 0;
  for (int i = (1); i <= (n); ++i) {
    if (a[i] == 0) {
      if (dfs(i))
        ++B;
      else
        ++A;
    } else {
      if (!whb[a[i]]) {
        if (!dfs(i)) {
          ++C;
        }
      }
    }
  }
  for (int i = (0); i <= (B); ++i) {
    for (int j = (i); j <= (B); ++j) {
      f[i] += 1ll * CC(B, j) * s[j][i] % 998244353 *
              calc(A + B - j - 1, B - j) % 998244353;
      if (f[i] >= 998244353) f[i] -= 998244353;
    }
  }
  for (int i = (0); i <= (C); ++i) {
    for (int j = (i); j <= (C); ++j) {
      g[i] += 1ll * CC(C, j) * s[j][i] % 998244353 *
              calc(A + C - j - 1, C - j) % 998244353;
      if (g[i] >= 998244353) g[i] -= 998244353;
    }
  }
  for (int i = (0); i <= (B); ++i)
    for (int j = (0); j <= (C); ++j) {
      h[i + j] += 1ll * f[i] * g[j] % 998244353;
      if (h[i + j] >= 998244353) h[i + j] -= 998244353;
    }
  memset(g, 0, sizeof(g));
  for (int i = (0); i <= (A); ++i) {
    g[i] = 1ll * s[A][i] * fac[A] % 998244353;
  }
  memset(f, 0, sizeof(f));
  for (int i = (0); i <= (B + C); ++i) {
    for (int j = (0); j <= (A); ++j) {
      f[i + j] += 1ll * h[i] * g[j] % 998244353;
      if (f[i + j] >= 998244353) f[i + j] -= 998244353;
    }
  }
  int cnt = 0;
  for (int i = (1); i <= (n); ++i) {
    fa[i] = i;
  }
  for (int i = (1); i <= (n); ++i) {
    if (!(a[i] && b[i])) continue;
    int u = Find(a[i]), v = Find(b[i]);
    if (u == v) ++cnt;
    fa[u] = v;
  }
  for (int i = (0); i <= (n - 1); ++i) {
    printf("%d ", f[n - i - cnt]);
  }
}
