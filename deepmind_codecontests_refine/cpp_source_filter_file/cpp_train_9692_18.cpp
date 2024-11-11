#include <bits/stdc++.h>
using namespace std;
const int maxn = 1050;
char mp[maxn][maxn];
int dp[maxn][maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> mp[i][j];
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (mp[i][j] == 'B') {
        cnt++;
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + 1;
      } else
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }
  int bei = 0, bej = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (mp[i][j] == 'W') continue;
      if (dp[i][j] == 1) bei = i, bej = j;
      if (dp[i][j] == cnt) {
        printf("%d %d\n", (i + bei) / 2, (j + bej) / 2);
        return 0;
      }
    }
  return 0;
}
