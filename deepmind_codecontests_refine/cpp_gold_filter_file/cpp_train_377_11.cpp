#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int M = 5005;
const int inf = 1000000000;
int n, m, t, x, y, z;
int dp[3][M][2], b[N], pos[N], c[N], d[N];
bool cmp(int x, int y) { return b[x + 1] - b[x] < b[y + 1] - b[y]; }
int main() {
  int i, j;
  scanf("%d%d", &m, &n);
  for (i = 1; i <= n; i++) scanf("%d", &b[i]);
  sort(b + 1, b + 1 + n);
  for (i = 1; i < n; i++) d[i] = b[i + 1] - b[i];
  for (i = 1; i < n; i++) pos[i] = i;
  sort(pos + 1, pos + n, cmp);
  pos[0] = -1;
  t = min(m * 3, n - 1);
  sort(pos + 1, pos + 1 + t);
  for (i = 1; i <= n; i++) c[i] = i % 3;
  for (i = 0; i <= 2; i++)
    for (j = 1; j <= m; j++) dp[i][j][0] = dp[i][j][1] = inf;
  dp[0][0][0] = 0;
  for (i = 1; i <= t; i++) {
    x = c[i];
    y = c[i - 1];
    z = -1;
    if (i > 1) z = c[i - 2];
    for (j = 1; j <= m; j++) {
      dp[x][j][0] = dp[x][j][1] = inf;
      dp[x][j][0] = min(dp[y][j][0], dp[y][j][1]);
      dp[x][j][1] = dp[y][j - 1][0] + d[pos[i]];
      if (pos[i] == pos[i - 1] + 1) {
        dp[x][j][1] = min(dp[x][j][1], dp[z][j - 1][1] + d[pos[i]]);
        dp[x][j][1] = min(dp[x][j][1], dp[z][j - 1][0] + d[pos[i]]);
      } else
        dp[x][j][1] = min(dp[x][j][1], dp[y][j - 1][1] + d[pos[i]]);
    }
  }
  printf("%d\n", min(dp[c[t]][m][0], dp[c[t]][m][1]));
  return 0;
}
