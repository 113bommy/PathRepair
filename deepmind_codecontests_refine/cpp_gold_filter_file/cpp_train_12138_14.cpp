#include <bits/stdc++.h>
using namespace std;
string s[1234];
int n, m;
int vis[1234][1234][6][3];
int f = 0;
void dfs(int x, int y, int dir, int turn) {
  if (x >= n || y >= m || turn > 2 || x < 0 || y < 0 || f == 1) return;
  if (s[x][y] == '*') return;
  if (vis[x][y][dir][turn] == 1) return;
  if (s[x][y] == 'T') {
    f = 1;
    return;
  } else {
    vis[x][y][dir][turn] = 1;
    if (dir == 1) {
      dfs(x, y + 1, 1, turn);
      dfs(x, y - 1, 3, turn + 1);
      dfs(x - 1, y, 4, turn + 1);
      dfs(x + 1, y, 2, turn + 1);
    }
    if (dir == 2) {
      dfs(x, y + 1, 1, turn + 1);
      dfs(x, y - 1, 3, turn + 1);
      dfs(x - 1, y, 4, turn + 1);
      dfs(x + 1, y, 2, turn);
    }
    if (dir == 3) {
      dfs(x, y + 1, 1, turn + 1);
      dfs(x, y - 1, 3, turn);
      dfs(x - 1, y, 4, turn + 1);
      dfs(x + 1, y, 2, turn + 1);
    }
    if (dir == 4) {
      dfs(x, y + 1, 1, turn + 1);
      dfs(x, y - 1, 3, turn + 1);
      dfs(x - 1, y, 4, turn);
      dfs(x + 1, y, 2, turn + 1);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  int i, j;
  pair<int, int> pos;
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (s[i][j] == 'S') {
        pos = make_pair(i, j);
      }
    }
  }
  dfs(pos.first, pos.second + 1, 1, 0);
  dfs(pos.first, pos.second - 1, 3, 0);
  dfs(pos.first - 1, pos.second, 4, 0);
  dfs(pos.first + 1, pos.second, 2, 0);
  if (f)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
