#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma GCC optimize(2)
using namespace std;
const int MAXN = 1e6 + 666, mod = 998244353, N = 2005;
const long long INF = 0x7ffffffffffffff, inf = 0x3f3f3f3f;
const double PI = acos(-1);
template <class T>
inline void MAX(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
inline void MIN(T &x, T y) {
  if (y < x) x = y;
}
template <class T>
inline void rd(T &x) {
  x = 0;
  char o, f = 1;
  while (o = getchar(), o < 48)
    if (o == 45) f = -f;
  do x = (x << 3) + (x << 1) + (o ^ 48);
  while (o = getchar(), o > 47);
  x *= f;
}
template <class T>
inline T ksm(T x, T y) {
  T ans = 1;
  while (y > 0) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
template <class T>
inline T GCD(T x, T y) {
  if (x == 1 || y == 1) return 1;
  if (y > x) swap(x, y);
  while (x % y != 0) {
    x = x % y;
    swap(x, y);
  }
  return y;
}
long long f[510][510], g[510][510], a[510][510];
int main() {
  long long i, j, k, m, n, t, len, l, r, ans;
  rd(n);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) rd(a[i][j]);
  for (i = 1; i <= n; ++i) f[i][i] = 1;
  for (len = 2; len <= n; ++len) {
    for (l = 1; l <= n - len + 1; ++l) {
      int r = l + len - 1;
      if (a[l][r])
        for (k = l; k <= r - 1; ++k)
          (f[l][r] +=
           (f[l][k] + g[l][k]) * (g[k + 1][r] + f[k + 1][r]) % mod) %= mod;
      for (k = l + 1; k <= r - 1; ++k)
        if (a[l][k]) (g[l][r] += f[l][k] * (f[k][r] + g[k][r])) %= mod;
    }
  }
  ans = (f[1][n] + g[1][n]) % mod;
  printf("%lld", ans);
  return 0;
}
