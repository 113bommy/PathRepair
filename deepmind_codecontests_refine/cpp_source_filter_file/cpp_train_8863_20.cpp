#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const int INF = 0x3f3f3f3f;
const int N = 2e3 + 10, mod = 998244353;
int dp[N << 1][N], fac[N << 1];
inline int read() {
  int x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') flag = -1, ch = getchar();
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch - '0'), ch = getchar();
  return x * flag;
}
inline int fpm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod, b /= 2;
  }
  return res;
}
int main() {
  int n = read(), k = read(), l = read(), ans = 0;
  fac[0] = 1;
  for (int i = (1), iend = (n); i <= iend; i++)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  dp[0][0] = 1;
  for (int i = (1), iend = (n << 1); i <= iend; i++)
    for (int j = (0), jend = (i); j <= jend; j++) {
      if (j) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
      dp[i][j] = (dp[i][j] + 1ll * dp[i - 1][j + 1] * (j + 1)) % mod;
    }
  for (int i = (0), iend = ((n << 1)); i <= iend; i++)
    for (int j = (k), jend = (i); j <= jend; j++)
      ans = (ans + 1ll * dp[i][j] * dp[(n << 1) - i][j] % mod * fac[j]) % mod;
  printf("%lld\n", 1ll * ans * l % mod * fpm(2 * n + 1, mod - 2) % mod *
                       fpm(dp[n << 1][0], mod - 2) % mod);
  return 0;
}
