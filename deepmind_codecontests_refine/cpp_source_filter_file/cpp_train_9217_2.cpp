#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 15;
const int maxm = 1e6 + 15;
const int inf = 0x3f3f3f3f;
int a[105], dp[105][4];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  memset(dp, 0xc3, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][1], dp[i][0]);
    dp[i][0] = max(dp[i - 1][2], dp[i][0]);
    dp[i][0] = max(dp[i - 1][3], dp[i][0]);
    dp[i][0] = max(dp[i - 1][0], dp[i][0]);
    if (a[i] == 1 or a[i] == 3) {
      dp[i][1] = max(dp[i - 1][2] + 1, dp[i][1]);
      dp[i][1] = max(dp[i - 1][0] + 1, dp[i][1]);
    } else if (a[i] == 2 or a[i] == 3) {
      dp[i][2] = max(dp[i - 1][1] + 1, dp[i][2]);
      dp[i][2] = max(dp[i - 1][0] + 1, dp[i][2]);
    }
  }
  int ans = max(dp[n][2], max(dp[n][0], dp[n][1]));
  cout << n - ans << endl;
  return 0;
}
