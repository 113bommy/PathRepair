#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int INF = 0x3f3f3f3f;
int n;
long long a[N], g[2][N];
int dp[2][N];
inline long long read() {
  long long f = 1, x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
inline void upd(int& x, int y) { x = min(x, y); }
inline long long f(long long x) {
  if (x % 2 == 0) return x / 2;
  return x;
}
int main() {
  n = read(), a[0] = 1;
  for (int i = (n), iend = (1); i >= iend; i--) a[i] = read();
  dp[0][0] = 0, g[0][0] = 1;
  for (int i = (1), iend = (n); i <= iend; i++) {
    for (int j = (0), jend = (i); j <= jend; j++) dp[i & 1][j] = INF;
    for (int j = (0), jend = (i - 1); j <= jend; j++) {
      int t = i & 1;
      if ((2 * a[i]) % g[t ^ 1][j] == 0 &&
          (2 * a[i] / g[t ^ 1][j]) % 2 != g[t ^ 1][j] % 2)
        upd(dp[t][i], dp[t ^ 1][j]), g[t][i] = a[i];
      upd(dp[t][j], dp[t ^ 1][j] + 1), g[t][j] = f(g[t ^ 1][j]);
    }
  }
  int ans = INF;
  for (int i = (0), iend = (n); i <= iend; i++) upd(ans, dp[n & 1][i]);
  printf("%d", ans);
  return 0;
}
