#include <bits/stdc++.h>
using namespace std;
bool isBlack[55][55];
int dp[55][55][55][55];
int solve(int x1, int y1, int x2, int y2) {
  if (x1 == x2 && y1 == y2) {
    return isBlack[x1][y1];
  }
  if (dp[x1][y1][x2][y2] != -1) {
    return dp[x1][y1][x2][y2];
  }
  int ret = max(x2 - x1, y2 - y1) + 1;
  for (int i = x1; i < x2 - x1; i++) {
    ret = min(ret, solve(x1, y1, i, y2) + solve(i + 1, y1, x2, y2));
  }
  for (int i = y1; i < y2; i++) {
    ret = min(ret, solve(x1, y1, x2, i) + solve(x1, i + 1, x2, y2));
  }
  dp[x1][y1][x2][y2] = ret;
  return ret;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < n; j++) {
      isBlack[i][j] = str[j] == '#' ? 1 : 0;
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0, n - 1, n - 1);
}
