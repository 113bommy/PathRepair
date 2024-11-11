#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
char gph[20][120];
int l[20], r[20], v[20], dp[20][2];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = n; i >= 1; i--) {
    scanf("%s", gph[i] + 1);
    for (int j = 2; j <= m + 1; j++)
      if (gph[i][j] == '1') {
        l[i] = j;
        v[i] = 1;
        break;
      }
    for (int j = m + 1; j >= 2; j--)
      if (gph[i][j] == '1') {
        r[i] = j;
        break;
      }
  }
  while (!v[n] && n >= 1) n--;
  if (n == 1) return printf("%d\n", r[1] ? r[1] - 1 : 0) * 0;
  dp[1][0] = r[1] ? (r[1] - 1) * 2 : 0;
  dp[1][1] = m + 1;
  for (int i = 2; i < n; i++) {
    if (!v[i]) {
      dp[i][0] = dp[i - 1][0] + 1;
      dp[i][1] = dp[i - 1][1] + 1;
      continue;
    }
    dp[i][0] = min(dp[i - 1][0] + 2 * (r[i] - 1) + 1, dp[i - 1][1] + m + 1 + 1);
    dp[i][1] =
        min(dp[i - 1][1] + 2 * (m + 2 - l[i]) + 1, dp[i - 1][0] + m + 1 + 1);
  }
  int ans = min(dp[n - 1][0] + r[n], dp[n - 1][1] + 1 + m + 2 - l[n]);
  printf("%d\n", ans);
}
