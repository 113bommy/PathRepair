#include <bits/stdc++.h>
using namespace std;
int dp[30005][505], n, tr[33333], d, ans, x, mx;
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    tr[x]++;
    mx = max(mx, x);
  }
  for (int i = 1; i <= mx; i++) {
    for (int j = 0; j <= 500; j++) dp[i][j] = -1e9;
  }
  dp[d][250] = tr[d];
  ans = tr[d];
  for (int i = d + 1; i <= mx; i++) {
    for (int j = 0; j < 500; j++) {
      int pre = i - (d + j - 250);
      if (pre < d || pre >= i) continue;
      dp[i][j] = max(max(dp[pre][j + 1], dp[pre][j]), dp[pre][j - 1]);
      dp[i][j] += tr[i];
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
