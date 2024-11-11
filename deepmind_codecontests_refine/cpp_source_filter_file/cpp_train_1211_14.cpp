#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& x) {
  char c = getchar();
  T p = 1, n = 0;
  while (c < '0' || c > '9') {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    n = n * 10 + c - '0';
    c = getchar();
  }
  x = p * n;
}
template <class T, class U>
void read(T& x, U& y) {
  read(x), read(y);
}
template <class T, class U, class V>
void read(T& x, U& y, V& z) {
  read(x), read(y), read(z);
}
const int maxn = 105;
const long long mod = 1e9 + 7;
bool G[maxn][maxn];
int n, a[maxn][maxn];
int power(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) r = 1ll * r * a % mod;
  return r;
}
int det() {
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    int j;
    for (j = i; j < n; ++j)
      if (a[j][i]) break;
    ans = 1ll * ans * a[j][i] % mod;
    if (j != i) ans = mod - ans;
    for (int k = i; k < n; ++k) swap(a[i][k], a[j][k]);
    for (int k = i + 1; k < n; ++k) {
      int d = 1ll * a[k][i] * power(a[i][i], mod - 2) % mod;
      for (int l = i; l < n; ++l)
        a[k][l] = (a[k][l] - 1ll * d * a[i][l] % mod + mod) % mod;
    }
  }
  return ans;
}
int go(int x) {
  memset(a, 0, sizeof a);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < i; ++j)
      if (G[i][j])
        a[i][j] = (mod - x) % mod, a[j][i] = (mod - x) % mod,
        (a[i][i] += x) %= mod, (a[j][j] += x) %= mod;
      else
        a[i][j] = mod - 1, a[j][i] = mod - 1, (a[i][i] += 1) %= mod,
        (a[j][j] += 1) %= mod;
  return det();
}
int f[maxn][maxn], fac[maxn], ifac[maxn], s[maxn][maxn], r[maxn];
int main() {
  read(n);
  for (int i = 1, u, v; i < n; ++i) read(u, v), G[u][v] = G[v][u] = 1;
  for (int i = 0; i < n; ++i) f[0][i] = go(i);
  for (int i = 1; i < n; ++i)
    for (int j = 0; j < n - i; ++j)
      f[i][j] = (f[i - 1][j + 1] - f[i - 1][j]) % mod;
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = power(fac[n], mod - 2);
  for (int i = n - 1; ~i; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  for (int i = 0; i < n; ++i) r[i] = 1ll * f[i][0] * ifac[i] % mod;
  s[0][0] = 1;
  for (int i = 1; i < n; ++i)
    for (int j = 1; j <= i; ++j)
      s[i][j] = (s[i - 1][j - 1] + 1ll * (i - 1) * s[i - 1][j] % mod) % mod;
  for (int i = 0; i < n; ++i)
    for (int j = i - 1, m1 = mod - 1; ~j; --j, m1 = mod - m1)
      (r[j] += 1ll * r[i] * m1 % mod * s[i][j] % mod) %= mod;
  for (int i = 0; i < n; ++i) printf("%d ", r[i]);
  return 0;
}
