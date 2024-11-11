#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
int n;
char fld[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
int calc(int i1, int j1, int i2, int j2) {
  int l1 = i2 - i1 + 1;
  int l2 = j2 - j1 + 1;
  if (l1 <= 0 || l2 <= 0) {
    return 0;
  }
  if (dp[i1][j1][i2][j2] == -1) {
    dp[i1][j1][i2][j2] = max(l1, l2);
    int cnt = 0;
    for (int i = i1; i <= i2; i++) {
      for (int j = j1; j <= j2; j++) {
        cnt += (fld[i][j] == '#');
      }
    }
    if (!cnt) {
      dp[i1][j1][i2][j2] = 0;
    }
    for (int i = i1; i <= i2; i++) {
      int cur = 0;
      cur += calc(i1, j1, i, j2);
      cur += calc(i + 1, j1, i2, j2);
      dp[i1][j1][i2][j2] = min(dp[i1][j1][i2][j2], cur);
    }
    for (int j = j1; j <= j2; j++) {
      int cur = 0;
      cur += calc(i1, j1, i2, j);
      cur += calc(i1, j + 1, i2, j2);
      dp[i1][j1][i2][j2] = min(dp[i1][j1][i2][j2], cur);
    }
  }
  return dp[i1][j1][i2][j2];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> fld[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < n; j1++) {
          dp[i][j][i1][j1] = -1;
        }
      }
    }
  }
  cout << calc(0, 0, n - 1, n - 1) << endl;
}
