#include <bits/stdc++.h>
using namespace std;
void add(int &a, int b) { a += b, a %= 1000000007; }
int n, h, dp[2][32][32][32][2], ans = 0;
int main() {
  scanf("%d%d", &n, &h);
  bool pre = 1, now = 0;
  dp[now][0][0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    now ^= 1, pre ^= 1;
    for (int j = 0; j <= h; j++)
      for (int k = 0; k <= h; k++)
        for (int l = 0; l <= h; l++)
          for (int flag = 0; flag < 2; flag++)
            if (dp[pre][j][k][l][flag]) {
              int tmp = dp[pre][j][k][l][flag];
              dp[pre][j][k][l][flag] = 0;
              if (j == h && k == h && l == h && flag || !tmp) continue;
              int o = flag ? h : 1;
              add(dp[now][min(j + 1, h)][min(k + 1, h)][min(l + 1, h)][flag],
                  tmp);
              add(dp[now][min(k + 1, h)][min(l + 1, h)][o][j == h], tmp);
              add(dp[now][min(j + 1, h)][min(l + 1, h)][o][k == h], tmp);
              add(dp[now][min(j + 1, h)][min(k + 1, h)][o][l == h], tmp);
            }
  }
  for (int i = 0; i <= h; i++)
    for (int j = 0; j <= h; j++)
      for (int k = 0; k <= h; k++)
        for (int flag = 0; flag < 2; flag++)
          if (i < h || j < h || k < h || !flag)
            add(ans, dp[now][i][j][k][flag]);
  printf("%d\n", ans);
  return 0;
}
