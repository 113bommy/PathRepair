#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
const int maxm = maxn * maxn;
const int INF = 0x3f3f3f3f;
int n, k, s, ans, res;
int a[maxn];
int dp[maxn][maxm];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
int main() {
  if (fopen("D.in", "r") != NULL) {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
  }
  n = read(), k = read(), s = read();
  s = min(s, n * (n - 1) * 2);
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= k; i++) ans += a[i];
  memset(dp, INF, sizeof(dp));
  dp[0][0] = 0;
  for (int p = 1; p <= k; p++)
    for (int i = p - 1; i >= 0; i--)
      for (int j = s - (k + 1 - p); j >= 0; j--)
        dp[i + 1][j + k + 1 - p] =
            min(dp[i + 1][j + k + 1 - p], dp[i][j] - a[p]);
  for (int p = k + 1; p <= n; p++)
    for (int i = 1; i <= k; i++)
      for (int j = s - (p - (k + 1)); j >= 0; j--)
        dp[i - 1][j + p - (k + 1)] =
            min(dp[i - 1][j + p - (k + 1)], dp[i][j] + a[p]);
  for (int i = 0; i <= s; i++) res = min(res, dp[0][i]);
  printf("%d\n", ans + res);
  return 0;
}
