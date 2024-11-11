#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1010][1010];
int D[1010][1010][5];
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
bool is_valid(int x, int y) {
  return (0 <= x && x < n && 0 <= y && y < m && s[x][y] != '*');
}
int bfs(int sx, int sy) {
  memset(D, -1, sizeof(D));
  deque<pair<pair<int, int>, int> > que;
  for (int i = 0; i < 4; i++) {
    que.push_back({{sx, sy}, i});
    D[sx][sy][i] = 0;
  }
  while (!que.empty()) {
    auto it = que.front();
    que.pop_front();
    int x, y, dir;
    tie(x, y) = it.first;
    dir = it.second;
    if (D[x][y][dir] > 3) continue;
    if (s[x][y] == 'T') return D[x][y][dir];
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (is_valid(nx, ny) &&
          (D[nx][ny][i] == -1 || D[x][y][i] + (i != dir) < D[nx][ny][i])) {
        D[nx][ny][i] = D[x][y][dir] + (i != dir);
        if (i == dir)
          que.push_front({{nx, ny}, i});
        else
          que.push_back({{nx, ny}, i});
      }
    }
  }
  return 1000;
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) cin >> s[i];
    int ans = 1000;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (s[i][j] == 'S') ans = bfs(i, j);
    if (ans <= 2)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
