#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, fh = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * fh;
}
const int maxn = 2005, yrz = 1e9 + 7;
int dp[maxn][maxn], arr[maxn], n, m, d[maxn][2];
int main() {
  n = m = read();
  for (register int i = 1; i <= n; ++i) arr[i] = read();
  for (register int i = 1; i <= n; ++i)
    if (arr[i] != -1) d[i][0] = d[arr[i]][1] = 1;
  int t = n;
  for (register int i = 1; i <= t; ++i)
    if (d[i][0]) --n;
  t = m;
  for (register int i = 1; i <= t; ++i)
    if (d[i][1] | d[i][0]) --m;
  dp[0][0] = 1;
  for (register int i = 1; i <= n; ++i) {
    dp[i][0] = 1ll * dp[i - 1][0] * i % yrz;
    for (register int j = 1; j <= m; ++j)
      dp[i][j] = (1ll * (j >= 2) * dp[i - 1][j - 2] * (j - 1) +
                  1ll * (i - j) * dp[i - 1][j - 1]) %
                 yrz;
  }
  cout << dp[n][m];
  return 0;
}
