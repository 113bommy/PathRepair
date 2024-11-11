#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[1 << 16], *S, *T;
  if (S == T) {
    T = (S = buf) + fread(buf, 1, 1 << 16, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
inline int read() {
  int x = 0, f = 1;
  char ch = gc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gc();
  return x * f;
}
int n, a[410], w[410], f[410][410], g[410][410], h[410][410], dp[410];
inline void Max(int &x, int y) {
  if (y > x) x = y;
}
int main() {
  n = read();
  for (int i = 0; i <= n; ++i) dp[i] = -0x3f3f3f3f;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) f[i][j] = g[i][j] = h[i][j] = -0x3f3f3f3f;
  for (int i = 1; i <= n; ++i) w[i] = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= n; ++i) f[i][i] = w[1], g[i][i] = h[i][i] = 0;
  for (int l = 2; l <= n; ++l)
    for (int i = 1; i <= n; ++i) {
      int j = i + l - 1;
      if (j > n) break;
      for (int k = i + 1; k <= j; ++k) {
        if (a[k] == a[i] + 1 && g[k][j] != -0x3f3f3f3f)
          Max(g[i][j], i + 1 > k - 1 ? 0 : f[i + 1][k - 1] + g[k][j]);
        if (a[k] == a[i] - 1 && h[k][j] != -0x3f3f3f3f)
          Max(h[i][j], i + 1 > k - 1 ? 0 : f[i + 1][k - 1] + h[k][j]);
        Max(f[i][j], f[i][k - 1] + f[k][j]);
      }
      for (int k = i; k <= j; ++k)
        if (g[i][k] != -0x3f3f3f3f && h[k][j] != -0x3f3f3f3f)
          Max(f[i][j], g[i][k] + h[k][j] + w[2 * a[k] - a[i] - a[j] + 1]);
    }
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    for (int j = 1; j <= i; ++j) Max(dp[i], dp[j - 1] + f[j][i]);
  }
  printf("%d\n", dp[n]);
  return 0;
}
