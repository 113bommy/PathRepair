#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int INF = 1e8;
int dp[80][80][80][3];
char s[80];
int cnt[80][3], id[80][3];
int main() {
  int n;
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) cnt[i][j] = cnt[i - 1][j];
    if (s[i] == 'V')
      cnt[i][0]++, id[cnt[i][0]][0] = i;
    else if (s[i] == 'K')
      cnt[i][1]++, id[cnt[i][1]][1] = i;
    else
      cnt[i][2]++, id[cnt[i][2]][2] = i;
  }
  int i, j, k, t, q;
  for (i = 0; i <= 75; i++)
    for (j = 0; j <= 75; j++)
      for (k = 0; k <= 75; k++)
        for (t = 0; t < 3; t++) dp[i][j][k][t] = INF;
  dp[0][0][0][2] = 0;
  for (i = 0; i <= cnt[n][0]; i++)
    for (j = 0; j <= cnt[n][1]; j++)
      for (k = 0; k <= cnt[n][2]; k++) {
        for (t = 0; t < 3; t++) {
          if (dp[i][j][k][t] == INF) continue;
          for (q = 0; q < 3; q++) {
            int tmp;
            if (q == 0)
              tmp = max(0, cnt[id[i + 1][0]][1] - j) +
                    max(0, cnt[id[i + 1][0]][2] - k);
            else if (q == 1)
              tmp = max(0, cnt[id[j + 1][1]][0] - i) +
                    max(0, cnt[id[j + 1][1]][2] - k);
            else
              tmp = max(0, cnt[id[k + 1][2]][0] - i) +
                    max(0, cnt[id[k + 1][2]][1] - j);
            if (q == 0) {
              dp[i + 1][j][k][q] =
                  min(dp[i + 1][j][k][q], dp[i][j][k][t] + tmp);
            } else if (q == 1) {
              if (t == 0) continue;
              dp[i][j + 1][k][q] =
                  min(dp[i][j + 1][k][q], dp[i][j][k][t] + tmp);
            } else {
              dp[i][j][k + 1][q] =
                  min(dp[i][j][k + 1][q], dp[i][j][k][t] + tmp);
            }
          }
        }
      }
  int ans = INF;
  for (t = 0; t < 3; t++)
    ans = min(ans, dp[cnt[n][0]][cnt[n][1]][cnt[n][2]][t]);
  cout << ans << endl;
}
