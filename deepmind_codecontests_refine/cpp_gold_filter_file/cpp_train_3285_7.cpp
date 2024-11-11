#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &num) {
  T x = 0, f = 1;
  char ch = getchar();
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch <= '9' && ch >= '0'; ch = getchar())
    x = (x << 3) + (x << 1) + (ch ^ '0');
  num = x * f;
}
const int mod = 998244353;
inline int qmod(int x) { return x < mod ? x : x - mod; }
inline int fpow(int x, int t) {
  int r = 1;
  for (; t; t >>= 1, x = 1ll * x * x % mod)
    if (t & 1) r = 1ll * r * x % mod;
  return r;
}
int n, cc, a[2005], b[2005], p[2005], q[2005], s[2005][2005], fa[2005],
    fac[2005], Inv[2005];
int f[2005], g[2005], h[2005], f2[2005], f3[2005];
bool del[2005];
inline int _C(int aa, int bb) {
  return (aa < bb) ? 1 : 1ll * fac[aa] * Inv[bb] % mod * Inv[aa - bb] % mod;
}
inline int _A(int aa, int bb) {
  return !bb ? 1 : 1ll * fac[aa] * Inv[aa - bb] % mod;
}
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) read(b[i]);
  s[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++)
      s[i][j] = qmod(s[i - 1][j - 1] + 1ll * (i - 1) * s[i - 1][j] % mod);
  }
  fac[0] = Inv[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
  Inv[n] = fpow(fac[n], mod - 2);
  for (int i = n - 1; i; i--) Inv[i] = 1ll * Inv[i + 1] * (i + 1) % mod;
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= n; i++) {
    if (a[i] && b[i]) {
      del[i] = 1;
      if (find(a[i]) == find(b[i]))
        ++cc;
      else
        fa[find(a[i])] = find(b[i]);
    }
  }
  for (int i = 1; i <= n; i++)
    if (!del[i]) {
      a[i] = find(a[i]);
      b[i] = find(b[i]);
      p[a[i]] = i;
      q[b[i]] = i;
    }
  int A = 0, B = 0, C = 0;
  for (int i = 1; i <= n; i++) {
    if (p[i] && q[i]) ++C, del[p[i]] = del[q[i]] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (!del[i]) {
      if (!a[i] && !b[i])
        ++C;
      else if (!a[i])
        ++A;
      else
        ++B;
    }
  for (int i = 0; i <= A; i++) {
    for (int j = i; j <= A; j++) {
      f[i] = qmod(f[i] + 1ll * s[j][i] * _C(A, j) % mod *
                             _A(A + C - j - 1, A - j) % mod);
    }
  }
  for (int i = 0; i <= B; i++) {
    for (int j = i; j <= B; j++) {
      g[i] = qmod(g[i] + 1ll * s[j][i] * _C(B, j) % mod *
                             _A(B + C - j - 1, B - j) % mod);
    }
  }
  for (int i = 0; i <= C; i++) h[i] = 1ll * s[C][i] * fac[C] % mod;
  for (int i = 0; i <= A; i++) {
    for (int j = 0; j <= B; j++) {
      f2[i + j] = qmod(f2[i + j] + 1ll * f[i] * g[j] % mod);
    }
  }
  for (int i = 0; i <= A + B; i++) {
    for (int j = 0; j <= C; j++) {
      f3[i + j] = qmod(f3[i + j] + 1ll * f2[i] * h[j] % mod);
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", n - i - cc >= 0 ? f3[n - i - cc] : 0);
  }
  return 0;
}
