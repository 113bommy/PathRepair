#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[20][105];
int dp[20][3];
int num[20];
int main(int argc, const char* argv[]) {
  while (cin >> n >> m) {
    memset(num, 0, sizeof(num));
    for (int i = n; i >= 1; i--) {
      scanf("%s", s[i]);
      for (int j = 1; j <= m; j++) {
        if (s[i][j] == '1') num[i]++;
      }
    }
    for (int i = n - 1; i >= 1; i--) num[i] += num[i - 1];
    int k;
    for (k = m; k > 0; k--)
      if (s[1][k] == '1') break;
    dp[1][0] = 2 * k;
    dp[1][1] = m + 1;
    dp[1][2] = k;
    for (int i = 2; i <= n; i++) {
      int j;
      for (j = m; j > 0; j--) {
        if (s[i][j] == '1') break;
      }
      dp[i][0] = min(dp[i - 1][0] + 1 + 2 * j, dp[i - 1][1] + 1 + m + 1);
      dp[i][2] = dp[i - 1][0] + 1 + j;
      for (j = 1; j <= m; j++) {
        if (s[i][j] == '1') break;
      }
      dp[i][1] = min(dp[i - 1][0] + m + 2, dp[i - 1][1] + 1 + 2 * (m + 1 - j));
      dp[i][2] = min(dp[i - 1][1] + 1 + (m + 1 - j), dp[i][2]);
    }
    for (int i = 1; i <= n; i++) {
      if (num[i + 1] == 0) {
        cout << dp[i][2] << endl;
        break;
      }
    }
  }
  return 0;
}
