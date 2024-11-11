#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 10;
const int mod = 998244353;
int n, m, k;
int a[N], b[N], fac[N], ifac[N], dp[N][N];
template <typename T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
inline int quickpow(int a, int n) {
  int res = 1, b = a;
  for (; n; n >>= 1, a = (long long)a * a % mod)
    if (n & 1) res = (long long)res * a % mod;
  return res;
}
inline void inc(int &x, int y) { x = x + y < mod ? x + y : x + y - mod; }
inline void dec(int &x, int y) { x = x - y >= 0 ? x - y : x - y + mod; }
inline int binom(int n, int m) {
  if (n < m)
    return 0;
  else
    return (long long)fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int main() {
  read(n), read(k);
  if (k <= 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  m = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
  dp[0][n] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= 2 * n; ++j) {
      if (!dp[i][j]) continue;
      int now = i + 1, nxt = now % n + 1;
      if (a[now] != a[nxt]) {
        if (j) inc(dp[i + 1][j - 1], dp[i][j]);
        inc(dp[i + 1][j + 1], dp[i][j]);
        inc(dp[i + 1][j], (long long)(k - 2) * dp[i][j] % mod);
      } else
        inc(dp[i + 1][j], (long long)k * dp[i][j] % mod);
    }
  }
  int ans = 0;
  for (int i = n + 1; i <= 2 * n; ++i) inc(ans, dp[n][i]);
  printf("%d\n", ans);
  return 0;
}
