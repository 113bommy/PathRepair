#include <bits/stdc++.h>
using namespace std;
char graph[110][110];
struct fff {
  int s;
  string p;
};
fff dp[110][110][20];
int n, m, mod;
int main() {
  int now;
  scanf("%d %d %d", &n, &m, &mod);
  mod++;
  for (int i = 0; i < 110; i++)
    for (int j = 0; j < 110; j++)
      for (int k = 0; k < 20; k++) {
        dp[i][j][k].s = -1;
        dp[i][j][k].p = "";
      }
  for (int i = 0; i < n; i++) scanf("%s", graph[i]);
  for (int j = 0; j < m; j++) {
    now = graph[0][j] - '0';
    dp[0][j][now % mod].s = now;
  }
  for (int i = 1; i < n; i++)
    for (int j = 0; j < m; j++) {
      now = graph[i][j] - '0';
      if (j > 0) {
        for (int k = 0; k < mod; k++) {
          if (dp[i - 1][j - 1][k].s != -1) {
            if (dp[i][j][(k + now) % mod].s < dp[i - 1][j - 1][k].s + now) {
              dp[i][j][(k + now) % mod].s = dp[i - 1][j - 1][k].s + now;
              dp[i][j][(k + now) % mod].p = dp[i - 1][j - 1][k].p + 'L';
            }
          }
        }
      }
      if (j < m - 1) {
        for (int k = 0; k < mod; k++) {
          if (dp[i - 1][j + 1][k].s != -1) {
            if (dp[i][j][(k + now) % mod].s < dp[i - 1][j + 1][k].s + now) {
              dp[i][j][(k + now) % mod].s = dp[i - 1][j + 1][k].s + now;
              dp[i][j][(k + now) % mod].p = dp[i - 1][j + 1][k].p + 'R';
            }
          }
        }
      }
    }
  fff ans;
  ans.s = -1;
  int pos;
  for (int j = 0; j < m; j++)
    if (dp[n - 1][j][0].s > ans.s) {
      ans.s = dp[n - 1][j][0].s;
      ans.p = dp[n - 1][j][0].p;
      pos = j;
    }
  if (ans.s == -1)
    printf("-1\n");
  else {
    printf("%d\n%d\n", ans.s, pos + 1);
    int n = ans.p.size();
    for (int i = n - 1; i >= 0; i--) printf("%c", ans.p[i]);
  }
  return 0;
}
