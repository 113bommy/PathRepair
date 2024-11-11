#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, r, dp[maxn];
int a[maxn][5];
signed main() {
  memset(dp, 128, sizeof(dp));
  dp[0] = 0;
  a[0][2] = a[0][3] = 1;
  scanf("%d%d", &r, &n);
  for (int i = 1; i <= n; i++) {
    int t, x, y, dis;
    scanf("%d%d%d", &t, &x, &y);
    a[i][1] = t, a[i][2] = x, a[i][3] = y;
    for (int j = i - 1; j >= max(0, i - 1500); j--) {
      dis = abs(x - a[j][2]) + abs(y - a[j][3]);
      if (a[j][1] + dis <= t) dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
  printf("%d\n", ans);
}
