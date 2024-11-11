#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7, inf = 1e9 + 7;
int a[N], dp[2][50], now, n;
void gmin(int &a, int b) {
  if (a > b) a = b;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), a[i] /= 100;
  now = 0;
  for (int i = 1; i <= 40; ++i) dp[now][i] = inf;
  for (int i = 1; i <= n; ++i) {
    now ^= 1;
    for (int j = 0; j <= 40; ++j) dp[now][j] = inf;
    for (int j = 0; j <= 40; ++j)
      if (dp[now ^ 1][j] != inf) {
        if (j < 35) gmin(dp[now][j + a[i] / 10], dp[now ^ 1][j] + a[i]);
        int tmp = max(a[i] - j, 0);
        gmin(dp[now][j - a[i] + tmp], dp[now ^ 1][j] + tmp);
      }
  }
  int ans = inf;
  for (int i = 0; i <= 19; ++i) gmin(ans, dp[now][i]);
  printf("%d00\n", ans);
  return 0;
}
