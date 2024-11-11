#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 410;
const double eps = -1e8;
const int ORIG = 200;
int n, d, x, y, mx[MAX], my[MAX];
int dp[MAX][MAX];
bool far(int qx, int qy) {
  int dx = qx - ORIG;
  int dy = qy - ORIG;
  return dx * dx + dy * dy > d * d;
}
int dfs(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y];
  for (int i = 0, _n = (n); i < _n; ++i) {
    int dx = x + mx[i];
    int dy = y + my[i];
    if (!far(dx, dy) and dfs(dx, dy) == 0) return dp[x][y] = 1;
  }
  return dp[x][y] = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> x >> y >> n >> d;
  for (int i = 0, _n = (n); i < _n; ++i) cin >> mx[i] >> my[i];
  memset(dp, -1, sizeof(dp));
  int ans = dfs(x + ORIG, y + ORIG);
  cout << (ans ? "Anton" : "Dasha") << endl;
  return 0;
}
