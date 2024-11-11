#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const long long mod = 1e9 + 7;
vector<string> grid;
long long dp[2][500][500];
int n, m;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m;
  int mid = (n + m - 2) / 2;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    grid.push_back(s);
  }
  for (int first = 0; first < n; first++) {
    if (first > mid) continue;
    int second = mid - first;
    if (second < 0 || second > mid || second >= m) continue;
    for (int xx = 0; xx < n; xx++) {
      if (n - 1 - xx > mid) continue;
      int yy = m - 1 - (mid - (n - 1 - xx));
      if (yy >= m || m - 1 - yy > mid) continue;
      if (abs(first - xx) + abs(second - yy) < 2 &&
          grid[first][second] == grid[xx][yy])
        dp[1][first][xx] = 1;
    }
  }
  for (int c = mid - 1; c >= 0; c--) {
    for (int first = 0; first < n; first++) {
      if (first > mid) continue;
      int second = c - first;
      if (second < 0 || second > mid || second >= m) continue;
      for (int xx = 0; xx < n; xx++) {
        if (n - 1 - xx > mid) continue;
        int yy = m - 1 - (c - (n - 1 - xx));
        if (yy >= m || m - 1 - yy > mid || yy < 0) continue;
        if (grid[first][second] != grid[xx][yy]) continue;
        if (second + 1 < m && yy - 1 >= 0) dp[0][first][xx] += dp[1][first][xx];
        if (first + 1 < n && yy - 1 >= 0)
          dp[0][first][xx] += dp[1][first + 1][xx];
        if (xx - 1 >= 0 && second + 1 < m)
          dp[0][first][xx] += dp[1][first][xx - 1];
        if (first + 1 < n && xx - 1 >= 0)
          dp[0][first][xx] += dp[1][first + 1][xx - 1];
        dp[0][first][xx] %= mod;
      }
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) dp[1][i][j] = dp[0][i][j], dp[0][i][j] = 0;
  }
  cout << dp[1][0][n - 1] << "\n";
  return 0;
}
