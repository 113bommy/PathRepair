#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int sum[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
char s[maxn];
int cal(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}
int dfs(int x1, int y1, int x2, int y2) {
  if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
  if (cal(x1, y1, x2, y2) == 0) return 0;
  int ans = max(y2 - y1 + 1, x2 - x1 + 1);
  for (int i = x1; i < x2; i++) {
    ans = min(ans, dfs(i + 1, y1, x2, y2) + dfs(x1, y1, i, y2));
  }
  for (int i = y1; i < y2; i++) {
    ans = min(ans, dfs(x1, y1, x2, i) + dfs(x1, i + 1, x2, y2));
  }
  return dp[x1][y1][x2][y2] = ans;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    cin >> s + 1;
    for (int j = 1; j <= n; j++) {
      if (s[j] == '#') sum[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sum[i][j];
    }
  }
  cout << dfs(1, 1, n, n) << endl;
  return 0;
}
