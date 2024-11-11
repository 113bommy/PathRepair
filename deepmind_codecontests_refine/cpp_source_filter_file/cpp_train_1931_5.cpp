#include <bits/stdc++.h>
using namespace std;
char str1[1005], str2[1005];
int dp[1005][1005][11], c[1005][1005], cc[1005][1005];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cin >> str1 + 1 >> str2 + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str1[i] == str2[j]) {
        c[i][j] = c[i - 1][j - 1] + 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    for (int p = 1; p <= n; p++) {
      for (int q = 1; q <= m; q++) {
        dp[p][q][i] = max(dp[p - 1][q][i], dp[p][q - 1][i]);
        dp[p][q][i] =
            max(dp[p][q][i], c[p][q] + dp[p - c[p][q]][q - c[p][q]][k - 1]);
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    ans = max(ans, dp[n][m][i]);
  }
  cout << ans << endl;
  return 0;
}
