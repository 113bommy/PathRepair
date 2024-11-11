#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
const int INF = 1000 * 1000 * 1000;
const long long LINF = (long long)INF * INF;
char grid[100100][20];
int n, m;
void dfs(int, int, int);
pair<int, int> dst[100100][20];
bool mark[100100][20];
void calc(int up, int down) {
  for (int i = (up); i < (down); i++) {
    fill(mark[i], mark[i] + m + 5, 0);
  }
  for (int i = down - 1; i >= up; i--) {
    for (int j = (0); j < (m); j++) {
      if (!mark[i][j]) {
        dfs(i, j, up);
      }
    }
  }
}
void dfs(int x, int y, int up) {
  mark[x][y] = true;
  pair<int, int> nxt;
  if (grid[x][y] == '<') {
    nxt = {x, y - 1};
  } else if (grid[x][y] == '>') {
    nxt = {x, y + 1};
  } else {
    nxt = {x - 1, y};
  }
  if (nxt.first < 0 || nxt.second < 0 || nxt.second >= m) {
    dst[x][y] = nxt;
    return;
  }
  if ((grid[x][y] == '>' && grid[nxt.first][nxt.second] == '<') ||
      (grid[x][y] == '<' && grid[nxt.first][nxt.second] == '>')) {
    mark[nxt.first][nxt.second] = true;
    dst[x][y] = {-INF, -INF};
    dst[nxt.first][nxt.second] = {-INF, -INF};
    return;
  }
  if (nxt.first < up) {
    dst[x][y] = nxt;
    return;
  }
  if (!mark[nxt.first][nxt.second]) {
    dfs(nxt.first, nxt.second, up);
  }
  dst[x][y] = dst[nxt.first][nxt.second];
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int q;
  cin >> n >> m >> q;
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (m); j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < n; i += 350) {
    calc(i, min(n, i + 350));
  }
  while (q--) {
    char op;
    cin >> op;
    if (op == 'A') {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      while (x >= 0 && y >= 0 && y < m) {
        pair<int, int> nxt = dst[x][y];
        x = nxt.first;
        y = nxt.second;
      }
      if (x == -INF) {
        cout << -1 << ' ' << -1 << '\n';
      } else {
        cout << x + 1 << ' ' << y + 1 << '\n';
      }
    } else {
      int x, y;
      char c;
      cin >> x >> y >> c;
      x--;
      y--;
      grid[x][y] = c;
      calc((x / 350) * 350, min(n, (x / 350 + 1) * 350));
    }
  }
  return 0;
}
