#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string ans = "YES";
  int i, j, x, y;
  char dp[102][102];
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> dp[i][j];
      if (dp[i][j] == '.') dp[i][j] = '0';
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      int cnt = 0;
      if (dp[i][j] == '*') continue;
      for (x = -1; x <= 1; x++) {
        for (y = -1; y <= 1; y++) {
          if (dp[i + x][j + y] == '*') cnt++;
        }
      }
      if (cnt != (dp[i][j] - '0')) {
        ans = "NO";
        break;
      }
    }
  }
  cout << ans;
  return 0;
}
