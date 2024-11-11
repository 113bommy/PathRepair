#include <bits/stdc++.h>
using namespace std;
int dp[300100][22];
int a[300100], n;
void make(int &x, int y) {
  if (x == -1)
    x = y;
  else
    x = min(x, y);
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= 20; ++j) {
      if (dp[i][j] == -1) continue;
      make(dp[i + 1][min(40, j + a[i + 1] / 1000)], dp[i][j] + a[i + 1]);
      if (j * 100 >= a[i + 1])
        make(dp[i + 1][j - a[i + 1] / 100], dp[i][j]);
      else
        make(dp[i + 1][0], dp[i][j] + a[i + 1] - j * 100);
    }
  int ans = -1;
  for (int i = 0; i <= 20; ++i)
    if (~dp[n][i]) make(ans, dp[n][i]);
  printf("%d\n", ans);
  return 0;
}
