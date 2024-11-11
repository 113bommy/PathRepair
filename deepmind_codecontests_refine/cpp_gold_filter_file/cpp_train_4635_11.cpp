#include <bits/stdc++.h>
using namespace std;
char a[505][505];
int dp[505][505];
int main() {
  memset(a, 0, sizeof(a));
  memset(dp, 0, sizeof(dp));
  int w, h, n;
  cin >> h >> w;
  for (int i = 0; i < h; i++) scanf("%s", a[i]);
  for (int i = 1; i < h; i++) {
    if (a[i][0] == '.' && a[i - 1][0] == '.')
      dp[i][0] = dp[i - 1][0] + 1;
    else
      dp[i][0] = dp[i - 1][0];
  }
  for (int i = 1; i < w; i++) {
    if (a[0][i] == '.' && a[0][i - 1] == '.')
      dp[0][i] = dp[0][i - 1] + 1;
    else
      dp[0][i] = dp[0][i - 1];
  }
  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      if (a[i][j] == '.') {
        if (a[i - 1][j] == '.') dp[i][j]++;
        if (a[i][j - 1] == '.') dp[i][j]++;
      }
    }
  }
  cin >> n;
  int x1, y1, x2, y2, k = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 == 1 && y1 == 1)
      k = dp[x2 - 1][y2 - 1];
    else if (x1 == 1) {
      k = dp[x2 - 1][y2 - 1] - dp[x2 - 1][y1 - 2];
      for (int j = x1 - 1; j < x2; j++)
        if (a[j][y1 - 2] == '.' && a[j][y1 - 1] == '.') k--;
    } else if (y1 == 1) {
      k = dp[x2 - 1][y2 - 1] - dp[x1 - 2][y2 - 1];
      for (int j = y1 - 1; j < y2; j++)
        if (a[x1 - 2][j] == '.' && a[x1 - 1][j] == '.') k--;
    } else {
      k = dp[x2 - 1][y2 - 1] - dp[x2 - 1][y1 - 2] - dp[x1 - 2][y2 - 1] +
          dp[x1 - 2][y1 - 2];
      for (int j = x1 - 1; j < x2; j++)
        if (a[j][y1 - 2] == '.' && a[j][y1 - 1] == '.') k--;
      for (int j = y1 - 1; j < y2; j++)
        if (a[x1 - 2][j] == '.' && a[x1 - 1][j] == '.') k--;
    }
    cout << k << endl;
  }
  return 0;
}
