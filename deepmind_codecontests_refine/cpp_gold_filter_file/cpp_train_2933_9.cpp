#include <bits/stdc++.h>
const int N = 1e5 + 10;
const int mod = 998244353;
using namespace std;
void up(int& x, int y) { x < y && (x = y); }
int d[N][600];
struct node {
  int num, p, x1, x2;
} dp[2][520][2];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    int y = 0, x;
    while (k--) scanf("%d", &x), x--, y |= (1 << x);
    for (int j = 0; j < (1 << 9); ++j) d[i][j] = d[i - 1][j];
    for (int j = 0; j < (1 << 9); ++j) up(d[i][j | y], d[i - 1][j] + 1);
  }
  for (int i = 0; i < (1 << 9); ++i)
    dp[0][i][0] = dp[0][i][1] = {-1, 2 * 0x3f3f3f3f, 0, 0};
  int c = 0;
  for (int i = 1; i <= m; ++i) {
    c ^= 1;
    int p, k, x, y = 0;
    scanf("%d%d", &p, &k);
    while (k--) scanf("%d", &x), x--, y |= (1 << x);
    for (int j = 0; j < (1 << 9); ++j)
      dp[c][j][0] = dp[c ^ 1][j][0], dp[c][j][1] = dp[c ^ 1][j][1];
    if (dp[c][y][0].num < d[n][y] ||
        (dp[c][y][0].num == d[n][y] && dp[c][y][0].p > p))
      dp[c][y][0] = {d[n][y], p, i, 0};
    for (int j = 1; j < (1 << 9); ++j) {
      if (dp[c ^ 1][j][0].num != -1 &&
          (dp[c][y | j][1].num < d[n][y | j] ||
           (dp[c][y | j][1].num == d[n][y | j] &&
            dp[c][y | j][1].p > p + dp[c ^ 1][j][0].p)))
        dp[c][y | j][1] = {d[n][y | j], dp[c ^ 1][j][0].p + p, i,
                           dp[c ^ 1][j][0].x1};
    }
  }
  int num = -1, ans = 2 * 0x3f3f3f3f;
  for (int i = 1; i < (1 << 9); ++i) num = max(num, dp[c][i][1].num);
  int x1 = 1, x2 = 2;
  for (int i = 1; i < (1 << 9); ++i)
    if (num == dp[c][i][1].num && ans > dp[c][i][1].p)
      ans = dp[c][i][1].p, x1 = dp[c][i][1].x1, x2 = dp[c][i][1].x2;
  printf("%d %d\n", x1, x2);
  return 0;
}
