#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 55;
const int INF = 1e9 + 7;
char a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][MAX_N][MAX_N];
void relax(int &x, int y) { x = min(x, y); }
int calc(int i1, int j1, int i2, int j2) {
  if (dp[i1][j1][i2][j2] != INF) {
    return dp[i1][j1][i2][j2];
  }
  dp[i1][j1][i2][j2] = max(i2 - i1 + 1, j2 - j1 + 1);
  for (int i = i1; i < i2; ++i) {
    relax(dp[i1][j1][i2][j2], calc(i1, j1, i, j2) + calc(i + 1, j1, i2, j2));
  }
  for (int j = i1; j < j2; ++j) {
    relax(dp[i1][j1][i2][j2], calc(i1, j1, i2, j) + calc(i1, j + 1, i2, j2));
  }
  return dp[i1][j1][i2][j2];
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i1 = 0; i1 < n; ++i1) {
    for (int j1 = 0; j1 < n; ++j1) {
      for (int i2 = 0; i2 < n; ++i2) {
        for (int j2 = 0; j2 < n; ++j2) {
          dp[i1][j1][i2][j2] = INF;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dp[i][j][i][j] = (a[i][j] == '#');
    }
  }
  cout << calc(0, 0, n - 1, n - 1) << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests = 1;
  while (tests--) {
    solve();
  }
  return 0;
}
