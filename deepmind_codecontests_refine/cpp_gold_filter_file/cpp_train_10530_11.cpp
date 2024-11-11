#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, T b) {
  return b > a ? a = b, 1 : 0;
}
inline int read() {
  int x(0), sgn(1);
  char ch(getchar());
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
  return x * sgn;
}
void File() {}
const int N = 1e5 + 1e3, K = 14, M = 4, Mod = 1e9 + 7;
int dp[N][K][1 << M];
int main() {
  File();
  int n = read(), k = read(), m = read();
  dp[0][0][0] = 1;
  for (register int i = (0), iend = (int)(n); i < iend; ++i)
    for (register int j = (0), jend = (int)(k); j <= jend; ++j)
      for (register int sta = (0), staend = (int)(1 << m); sta < staend;
           ++sta) {
        (dp[i + 1][j][sta >> 1] += dp[i][j][sta]) %= Mod;
        int res = dp[i][j][sta] * (1ll + __builtin_popcount(sta)) % Mod;
        (dp[i + 1][j + 1][(sta >> 1) | (1 << m - 1)] += res) %= Mod;
      }
  int ans = 0;
  for (register int sta = (0), staend = (int)(1 << m); sta < staend; ++sta)
    (ans += dp[n][k][sta]) %= Mod;
  printf("%d\n", ans);
  return 0;
}
