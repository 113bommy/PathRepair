#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const int INF = 0x3f;
int dp[maxn][maxn];
int a[maxn];
int main() {
  int n, h, l, r;
  scanf("%d %d %d %d", &n, &h, &l, &r);
  memset(dp, -INF, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < h; j++) {
      dp[i][j] = max(dp[i - 1][(j - a[i] + h) % h],
                     dp[i - 1][(j - a[i] + 1 + h) % h]) +
                 (j >= l && j <= r);
    }
  }
  int ans = -1;
  for (int i = 1; i <= h; i++) {
    ans = max(ans, dp[n][i]);
  }
  printf("%d\n", ans);
  return 0;
}
