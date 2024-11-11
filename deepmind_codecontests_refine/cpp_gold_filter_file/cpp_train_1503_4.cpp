#include <bits/stdc++.h>
using namespace std;
const int N = 410, inf = 1e9;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
int f[N][N];
int dp[N];
int g[N][N], h[N][N];
int v[N], w[N];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) v[i] = read();
  for (int i = 1; i <= n; ++i) w[i] = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) f[i][j] = g[i][j] = h[i][j] = -inf;
  for (int i = n; i >= 0; --i) {
    f[i][i] = v[1];
    g[i][i] = h[i][i] = 0;
    for (int j = i + 1; j <= n; ++j) {
      for (int k = i; k < j - 1; ++k)
        if (w[k] + 1 == w[j]) g[i][j] = max(g[i][j], g[i][k] + f[k + 1][j - 1]);
      if (w[j - 1] + 1 == w[j]) g[i][j] = max(g[i][j], g[i][j - 1]);
    }
    for (int j = i + 1; j <= n; ++j) {
      for (int k = i; k < j - 1; ++k)
        if (w[k] - 1 == w[j]) h[i][j] = max(h[i][j], h[i][k] + f[k + 1][j - 1]);
      if (w[j - 1] - 1 == w[j]) h[i][j] = max(h[i][j], h[i][j - 1]);
    }
    for (int j = i; j <= n; ++j) {
      if (w[j] - w[i] + 1 > 0 && w[j] - w[i] + 1 <= n)
        f[i][j] = max(f[i][j], g[i][j] + v[w[j] - w[i] + 1]);
      if (w[i] - w[j] + 1 > 0 && w[i] - w[j] + 1 <= n)
        f[i][j] = max(f[i][j], h[i][j] + v[w[i] - w[j] + 1]);
      for (int k = i; k < j; ++k) f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
      for (int k = i; k < j; ++k)
        if (2 * w[k] - w[i] - w[j] + 1 > 0 && 2 * w[k] - w[i] - w[j] + 1 <= n)
          f[i][j] =
              max(f[i][j], g[i][k] + h[k][j] + v[2 * w[k] - w[j] - w[i] + 1]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    for (int j = 0; j < i; ++j) dp[i] = max(dp[i], dp[j] + f[j + 1][i]);
  }
  cout << dp[n] << endl;
  return 0;
}
