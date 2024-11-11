#include <bits/stdc++.h>
using namespace std;
int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}
const int N = 300000 + 10;
const int mod = 998244353;
int qpow(int a, int b) {
  int c = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) c = 1ll * c * a % mod;
  return c;
}
int n, s, a[N];
int f[N], g[N];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), s += a[i];
  g[0] = n - 1;
  for (int i = 1; i < s; ++i)
    g[i] = (1ll * s * (n - 1) + 1ll * i * (n - 1) % mod * g[i - 1]) % mod *
           qpow(s - i, mod - 2) % mod;
  for (int i = s; ~i; --i) f[i] = f[i + 1] + g[i];
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans = (ans + f[a[i]]) % mod;
  ans = (ans - 1ll * f[0] * (n - 1) % mod + mod) % mod;
  ans = 1ll * ans * qpow(n, mod - 2) % mod;
  printf("%d\n", ans);
  return 0;
}
