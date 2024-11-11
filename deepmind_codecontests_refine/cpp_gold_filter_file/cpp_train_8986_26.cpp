#include <bits/stdc++.h>
#pragma GCC optimize "O3"
using namespace std;
constexpr int RND = 3100, HP = 200;
int hp[2], dt[2], l[2], r[2], p[2];
double dp[2][RND][HP + 1], df0[2], df1[2];
int main() {
  for (int i = 0; i < 2; ++i) {
    scanf("%d %d %d %d %d", hp + i, dt + i, l + i, r + i, p + i);
    dp[i][0][hp[i]] = 1;
    df0[i] = double(100 - p[i]) / 100 / (r[i] - l[i] + 1);
    df1[i] = p[i] / 100.0;
  }
  if (p[0] == 100) {
    puts("0");
    return 0;
  } else if (p[1] == 100) {
    puts("1");
    return 0;
  }
  for (int i = 1; i < RND; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k <= hp[j]; ++k) {
        for (int m = l[1 - j]; m <= r[1 - j]; ++m)
          dp[j][i][max(0, k - m)] += dp[j][i - 1][k] * df0[1 - j];
        dp[j][i][k] += dp[j][i - 1][k] * df1[1 - j];
      }
  double ans = 0;
  for (int i = 1; i < RND; ++i) {
    int t = ((i - 1) * dt[0] + dt[1] - 1) / dt[1];
    if (t >= RND) break;
    ans += (1 - dp[0][t][0]) * (dp[1][i][0] - dp[1][i - 1][0]);
  }
  printf("%.8f\n", ans);
}
