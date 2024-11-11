#include <bits/stdc++.h>
using namespace std;
int dp[50][50];
int dp1[50][50][50][50];
int check(int x1, int y1, int x2, int y2) {
  int cnt = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
  return (cnt == 0);
}
int solve(int r1, int r2, int c1, int c2) {
  if (r1 > r2 || c1 > c2) return 0;
  int& ret = dp1[r1][r2][c1][c2];
  if (ret != -1) return ret;
  ret = 0;
  int arr[4];
  for (int i = 0; i < (1 << 4); i++) {
    int tot = 0;
    for (int j = 0; j < 4; j++) {
      if (i & (1 << j)) {
        arr[j] = 1;
        if (j & 1) arr[j] = -arr[j];
        tot++;
      } else {
        arr[j] = 0;
      }
    }
    int v = solve(r1 + arr[0], r2 + arr[1], c1 + arr[2], c2 + arr[3]);
    if (tot & 1)
      ret += v;
    else
      ret -= v;
  }
  ret += check(r1, c1, r2, c2);
  return ret;
}
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<string> A(n + 1);
  int a[n + 1][m + 1];
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    for (int j = 0; j < m; ++j) a[i][j + 1] = A[i][j] - '0';
  }
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
    }
  }
  int x1, y1, x2, y2;
  memset(dp1, -1, sizeof dp1);
  while (m--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << solve(x1, x2, y1, y2) << endl;
  }
  return 0;
}
