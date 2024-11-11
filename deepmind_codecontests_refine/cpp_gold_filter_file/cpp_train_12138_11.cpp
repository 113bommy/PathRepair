#include <bits/stdc++.h>
using namespace std;
int sx, sy, ex, ey, n, m;
string s[1009];
int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};
int dp[1009][1009][7][7];
bool valid(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '*')
    return true;
  else
    return false;
}
int solve(int i, int j, int dir, int turn) {
  int res = 0, x;
  if (turn < 0) return 0;
  if (i == ex && j == ey && turn >= 0) {
    return 1;
  }
  if (dp[i][j][dir][turn] != -1) return dp[i][j][dir][turn];
  for (int k = 0; k < 4; k++) {
    int tx = i + dx[k];
    int ty = j + dy[k];
    if (valid(tx, ty)) {
      if (k == dir)
        x = solve(tx, ty, dir, turn);
      else
        x = solve(tx, ty, k, turn - 1);
      res = max(res, x);
    }
  }
  return dp[i][j][dir][turn] = res;
}
int main() {
  int i, j, k, l, emne;
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (s[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (s[i][j] == 'T') {
        ex = i;
        ey = j;
      }
    }
  }
  memset(dp, -1, sizeof dp);
  emne = solve(sx, sy, 0, 3);
  if (emne)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
