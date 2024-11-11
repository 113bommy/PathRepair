#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool dp[1002][1002][3][4];
int n, m;
string str[1002];
bool flag;
void func(int r, int c, int cnt, int prev) {
  if (cnt >= 3) return;
  if (r >= n || r < 0 || c >= m || c < 0) return;
  if (dp[r][c][cnt][prev] || flag) return;
  if (str[r][c] == 'T') flag = 1;
  int i, j, tx, ty;
  dp[r][c][cnt][prev] = 1;
  for (i = 0; i < 4; ++i) {
    tx = r + dx[i];
    ty = c + dy[i];
    if (tx >= 0 && tx < n && ty >= 0 && ty < m && str[tx][ty] != '*') {
      if (i != prev)
        func(tx, ty, cnt + 1, i);
      else
        func(tx, ty, cnt, i);
    }
  }
  return;
}
int main() {
  int i, j, k;
  cin >> n >> m;
  for (i = 0; i < n; ++i) cin >> str[i];
  flag = 0;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (str[i][j] == 'S') {
        for (k = 0; k < 4; ++k) func(i, j, 0, k);
        if (flag)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
        return 0;
      }
    }
  }
}
