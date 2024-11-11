#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fff;
int n;
pair<int, int> p[25];
int dis[25][25];
int dp[1 << 24 | 1];
int pre[1 << 24 | 1];
int main() {
  scanf("%d%d%d", &p[0].first, &p[0].second, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &p[i].first, &p[i].second);
  }
  for (int i = 0; i <= n; ++i)
    for (int j = i; j <= n; ++j) {
      dis[i][j] = dis[j][i] =
          pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2);
    }
  for (int m = 1; m < (1 << n); ++m) {
    dp[m] = INF;
  }
  dp[0] = 0;
  for (int m = 0; m < (1 << n); ++m) {
    if (dp[m] == INF) continue;
    for (int i = 1; i <= n; ++i) {
      if (m & 1 << (i - 1)) continue;
      for (int j = 1; j <= n; ++j) {
        if (m & 1 << (j - 1)) continue;
        if (dp[m | (1 << i - 1) | (1 << j - 1)] >
            dp[m] + dis[0][i] + dis[i][j] + dis[j][0]) {
          dp[m | (1 << i - 1) | (1 << j - 1)] =
              dp[m] + dis[0][i] + dis[i][j] + dis[j][0];
          pre[m | (1 << i - 1) | (1 << j - 1)] = m;
        }
      }
      break;
    }
  }
  printf("%d\n", dp[(1 << n) - 1]);
  int num = (1 << n) - 1;
  while (num) {
    printf("0 ");
    int t = pre[num] ^ num;
    for (int i = 0; i < n; ++i) {
      if (t & (1 << i)) {
        printf("%d ", i + 1);
      }
    }
    num = pre[num];
  }
  printf("0\n");
  return 0;
}
