#include <bits/stdc++.h>
using namespace std;
int dp[30010][545];
int hs[30005];
int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  memset(hs, 0, sizeof(hs));
  for (int i = 1; i <= n; i++) {
    int tmp;
    scanf("%d", &tmp);
    hs[tmp]++;
  }
  memset(dp, -1, sizeof(dp));
  int mx = hs[d];
  dp[d][250] = hs[d];
  for (int i = d + 1; i < 30005; i++) {
    for (int j = 1; j <= 500; j++) {
      int dis = j - 250 + d;
      if (i - dis > 0 && i - dis < i) {
        if (dp[i - dis][j + 1] != -1)
          dp[i][j] = max(hs[i] + dp[i - dis][j + 1], dp[i][j]);
        if (dp[i - dis][j] != -1)
          dp[i][j] = max(hs[i] + dp[i - dis][j], dp[i][j]);
        if (dp[i - dis][j - 1] != -1)
          dp[i][j] = max(hs[i] + dp[i - dis][j - 1], dp[i][j]);
      }
      mx = max(dp[i][j], mx);
    }
  }
  printf("%d\n", mx);
  return 0;
}
