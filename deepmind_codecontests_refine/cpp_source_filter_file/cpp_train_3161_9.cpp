#include <bits/stdc++.h>
using namespace std;
int main() {
  int white[1000];
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  memset(white, 0, sizeof(white));
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (m); j++) {
      char ch;
      cin >> ch;
      if (ch == '.') white[j]++;
    }
  }
  static int dp[1000][1000][2];
  for (int i = 0; i < (1000); i++)
    for (int j = 0; j < (1000); j++)
      for (int k = 0; k < (2); k++) dp[i][j][k] = (1 << 29);
  for (int i = 0; i < m; i++) {
    if (i == 0) {
      dp[0][0][0] = n - white[0];
      dp[0][0][1] = white[0];
      continue;
    }
    for (int j = 0; j < y; j++) {
      if (j + 1 < y) {
        if (dp[i - 1][j][0] != (1 << 29))
          dp[i][j + 1][0] = n - white[i] + dp[i - 1][j][0];
        if (dp[i - 1][j][1] != (1 << 29))
          dp[i][j + 1][1] = white[i] + dp[i - 1][j][1];
      }
      if (x <= j + i) {
        dp[i][0][0] = min(dp[i][0][0], n - white[i] + dp[i - 1][j][1]);
        dp[i][0][1] = min(dp[i][0][1], white[i] + dp[i - 1][j][0]);
      }
    }
  }
  int ans = (1 << 29);
  for (int i = x - 1; i < y; i++) {
    ans = min(ans, min(dp[m - 1][i][0], dp[m - 1][i][1]));
  }
  cout << ans << endl;
  return 0;
}
