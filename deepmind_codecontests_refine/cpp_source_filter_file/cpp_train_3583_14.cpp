#include <bits/stdc++.h>
using namespace std;
const int mx = 300000;
int n, m, a[500], b[500], bit[2000000], t[30], dp[1000001][21];
char t1[500];
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n - 1; i++) scanf("%d", &a[i]);
  scanf("%d\n", &m);
  for (int i = 0; i <= m - 1; i++) scanf("%c%d\n", &t1[i], &b[i]);
  sort(a, a + n);
  reverse(a, a + n);
  n = m;
  t[0] = 1;
  for (int i = 1; i <= 21; i++) t[i] = 2 * t[i - 1];
  for (int i = 1; i <= 1000000; i++) {
    for (int j = 0; j <= 20; j++)
      if ((i | t[j]) == i) {
        bit[i] = j;
        break;
      }
  }
  memset(dp[0], 0, sizeof(dp[0]));
  for (int i = 1; i <= t[m] - 1; i++) {
    dp[i][m] = 0;
    for (int j = m - 1; j >= 0; j--)
      if (b[j] == 1) {
        if (t1[j] == 'p') {
          dp[i][j] = dp[i ^ t[bit[i]]][j + 1] + a[bit[i]];
        } else {
          dp[i][j] = dp[i][j + 1];
          for (int k = 0; k <= m - 1; k++)
            if ((i | t[k]) == i) {
              dp[i][j] = max(dp[i][j], dp[i ^ t[k]][j + 1]);
            }
        }
      } else {
        if (t1[j] == 'p') {
          dp[i][j] = dp[i ^ t[bit[i]]][j + 1] - a[bit[i]];
        } else {
          dp[i][j] = dp[i][j + 1];
          for (int k = 0; k <= m - 1; k++)
            if ((i | t[k]) == i) {
              dp[i][j] = min(dp[i][j], dp[i ^ t[k]][j + 1]);
            }
        }
      }
  }
  cout << dp[t[m] - 1][0];
  return 0;
}
