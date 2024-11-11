#include <bits/stdc++.h>
using namespace std;
const long long inf = INT_MAX, df = 1005;
long long i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a[df];
double dp[df][df];
inline long long read() {
  long long x = 0, y = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') y = (ch == '-') ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * y;
}
int main() {
  n = read(), m = read();
  for (long long i = (1); i <= (n); ++i) a[i] = read();
  for (long long i = (1); i <= (n); ++i) {
    for (long long j = (1); j <= (n); ++j) dp[i][j] = (a[i] > a[j] ? 1.0 : 0.0);
  }
  while (m--) {
    long long x = read(), y = read();
    for (long long i = (1); i <= (n); ++i) {
      ;
      dp[y][i] = dp[x][i] = 0.5 * (dp[x][i] + dp[y][i]);
      dp[i][y] = dp[i][x] = 1.0 - dp[x][i];
    }
    dp[x][y] = dp[y][x] = 0.5;
  }
  double ans = 0;
  for (long long i = (1); i <= (n); ++i) {
    for (long long j = (i + 1); j <= (n); ++j) ans += dp[i][j];
  }
  return printf("%.7lf\n", ans), 0;
}
