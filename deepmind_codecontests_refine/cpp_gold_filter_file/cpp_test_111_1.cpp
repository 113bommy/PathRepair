#include <bits/stdc++.h>
using namespace std;
char _buf[100000], *_p1 = _buf, *_p2 = _buf;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return (f == 1) ? x : -x;
}
const int maxn = 2005, maxk = 25, mod = 998244353;
int dp[2][maxn * 2][maxn], pre[2][maxn * 2][maxn], now, last;
int fac[maxn], inv[maxn], invf[maxn], n, b[maxn], l[maxn], r[maxn], k;
inline int qpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = 1ll * ret * x % mod;
    k >>= 1, x = 1ll * x * x % mod;
  }
  return ret;
}
inline int C(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return 1ll * fac[n] * invf[m] % mod * invf[n - m] % mod;
}
inline void input() {
  n = gi();
  k = gi();
  for (int i = 1; i <= n; ++i) b[i] = gi();
  for (int i = 1; i <= n; ++i) l[i] = max(0, b[i] - k), r[i] = min(n, b[i] + k);
  fac[0] = fac[1] = inv[0] = inv[1] = invf[0] = invf[1] = 1;
  for (int i = 2; i <= n; ++i) fac[i] = 1ll * i * fac[i - 1] % mod;
  for (int i = 2; i <= n; ++i)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 2; i <= n; ++i) invf[i] = 1ll * invf[i - 1] * inv[i] % mod;
}
inline void solve() {
  dp[now][0][0] = 1;
  pre[now][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    now = now ^ 1, last = now ^ 1;
    for (int j = i; j >= 0; --j) {
      for (int k = l[i]; k <= r[i]; ++k) {
        int &nval = dp[now][j + k][k];
        nval = (nval + 1ll * (j + k) * dp[last][j + k][k]) % mod;
        if (j + k) nval = (nval + dp[last][j + k - 1][k]) % mod;
        if (j + k && k) {
          int val = pre[last][j + k - 1][k - 1];
          if (k - 1 >= r[i - 1]) val = pre[last][j + k - 1][r[i - 1]];
          nval = (nval + 1ll * val * invf[j]) % mod;
        }
        pre[now][j + k][k] = 1ll * dp[now][j + k][k] * fac[j] % mod;
        if (k)
          pre[now][j + k][k] =
              (pre[now][j + k][k] + pre[now][j + k][k - 1]) % mod;
      }
    }
    for (int j = 0; j <= i - 1; ++j)
      for (int k = l[i - 1]; k <= r[i - 1]; ++k)
        dp[last][j + k][k] = pre[last][j + k][k] = 0;
  }
  int ans = 0;
  for (int j = 0; j <= n; ++j)
    for (int k = l[n]; k <= r[n]; ++k) {
      int val = dp[now][j + k][k];
      ans = (ans + 1ll * fac[n - k] * invf[n - k - j] % mod * val) % mod;
    }
  printf("%d\n", ans);
}
int main() {
  input();
  solve();
  return 0;
}
