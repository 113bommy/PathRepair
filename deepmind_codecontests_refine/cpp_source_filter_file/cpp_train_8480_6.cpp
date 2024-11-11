#include <bits/stdc++.h>
using namespace std;
int dp[30005][800];
int cnt[30005];
int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d", &p);
    cnt[p]++;
  }
  memset(dp, -1, sizeof(dp));
  int mn = max(0, d - 800 / 2);
  dp[d][d - mn] = 0;
  int mx = 0;
  for (int i = 0; i < 30005; i++) {
    for (int j = 0; j < 800; j++) {
      if (dp[i][j] == -1) continue;
      mx = max(mx, dp[i][j]);
      int D = j + mn;
      if (j > 0) {
        int nd = D - 1;
        if (i + nd < 30005)
          dp[i + nd][j - 1] = max(dp[i + nd][j - 1], dp[i][j] + cnt[i]);
      }
      if (j + 1 < 800) {
        int nd = D + 1;
        if (i + nd < 30005)
          dp[i + nd][j + 1] = max(dp[i + nd][j + 1], dp[i][j] + cnt[i]);
      }
      int nd = D;
      if (i + nd < 30005) dp[i + nd][j] = max(dp[i + nd][j], dp[i][j] + cnt[i]);
    }
  }
  printf("%d\n", mx);
  return 0;
}
