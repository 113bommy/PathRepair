#include <bits/stdc++.h>
using namespace std;
int n, d;
int g[30010];
int dd[] = {-1, 0, 1};
int dp[30010][600];
int offset = 0;
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    g[x]++;
  }
  int mini = max(d - 245, 1);
  int maxi = d + 245;
  offset = mini;
  memset(dp, -1, sizeof(dp));
  dp[d][d - offset] = g[d];
  int nxt, nl;
  int ans = g[d];
  for (int i = d; i <= 30000; i++) {
    for (int j = mini; j <= maxi; j++) {
      if (dp[i][j] == -1) continue;
      for (int k = 0; k < 3; k++) {
        nl = j + dd[k];
        if (nl < mini || nl > maxi) continue;
        if (i + nl > 30000) break;
        dp[i + nl][nl - offset] =
            max(dp[i + nl][nl - offset], g[i + nl] + dp[i][j - offset]);
      }
      ans = max(ans, dp[i][j - offset]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
