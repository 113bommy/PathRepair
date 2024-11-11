#include <bits/stdc++.h>
using namespace std;
int a[51][51], dp[51][51][51][51];
int solve(int x1, int y1, int x2, int y2) {
  if (x1 == x2 && y1 == y2) return a[x1][y1];
  if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
  int ans = max(x2 - x1 + 1, y2 - y1 + 1);
  for (int i = x1; i < x2; i++) {
    ans = min(ans, solve(x1, y1, i, y2) + solve(i + 1, y1, x2, y2));
  }
  for (int i = y1; i < y2; i++) {
    ans = min(ans, solve(x1, y1, x2, i) + solve(x1, i + 1, x2, y2));
  }
  return dp[x1][y1][x2][y2] = ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = (s[j] == '#');
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0, n - 1, n - 1) << "\n";
}
