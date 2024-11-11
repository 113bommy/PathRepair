#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int rev[] = {2, 3, 0, 1};
const int maxn = 1e3 + 10;
int n, m;
int xs, ys, xd, yd;
char grd[maxn][maxn];
int dis[maxn][maxn][4];
int mark[maxn][maxn][4];
int can[maxn][maxn][4][4];
queue<pair<pair<int, int>, int>> bfs;
void in();
void solve();
void out();
void fix(int x, int y, int u, int r, int d, int l);
int main() {
  in();
  solve();
  out();
}
void in() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> grd[i][j];
  cin >> xs >> ys >> xd >> yd;
}
void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      mark[i][j][0] = 1;
      mark[i][j][1] = 1;
      mark[i][j][2] = 1;
      mark[i][j][3] = 1;
      if (grd[i][j] == '+') fix(i, j, 1, 1, 1, 1);
      if (grd[i][j] == '|') fix(i, j, 1, 0, 1, 0);
      if (grd[i][j] == '_') fix(i, j, 0, 1, 0, 1);
      if (grd[i][j] == '^') fix(i, j, 1, 0, 0, 0);
      if (grd[i][j] == '>') fix(i, j, 0, 1, 0, 0);
      if (grd[i][j] == 'V') fix(i, j, 0, 0, 1, 0);
      if (grd[i][j] == '<') fix(i, j, 0, 0, 0, 1);
      if (grd[i][j] == 'U') fix(i, j, 0, 1, 1, 1);
      if (grd[i][j] == 'R') fix(i, j, 1, 0, 1, 1);
      if (grd[i][j] == 'D') fix(i, j, 1, 1, 0, 1);
      if (grd[i][j] == 'L') fix(i, j, 1, 1, 1, 0);
    }
  }
  mark[xs][ys][0] = 0;
  bfs.push({{xs, ys}, 0});
  while (bfs.size()) {
    pair<pair<int, int>, int> v = bfs.front();
    if (v.first.first == xd && v.first.second == yd) {
      cout << dis[xd][yd][v.second];
      exit(0);
    }
    bfs.pop();
    if (mark[v.first.first][v.first.second][(v.second + 1) % 4]) {
      mark[v.first.first][v.first.second][(v.second + 1) % 4] = 0;
      dis[v.first.first][v.first.second][(v.second + 1) % 4] =
          dis[v.first.first][v.first.second][v.second] + 1;
      bfs.push({{v.first.first, v.first.second}, (v.second + 1) % 4});
    }
    for (int i = 0; i < 4; i++) {
      int xp = v.first.first + dx[i];
      int yp = v.first.second + dy[i];
      int dp = v.second;
      if (can[v.first.first][v.first.second][v.second][i] && mark[xp][yp][dp] &&
          can[xp][yp][dp][rev[i]]) {
        mark[xp][yp][dp] = 0;
        dis[xp][yp][dp] = dis[v.first.first][v.first.second][v.second] + 1;
        bfs.push({{xp, yp}, dp});
      }
    }
  }
}
void fix(int x, int y, int u, int r, int d, int l) {
  can[x][y][0][0] = u;
  can[x][y][0][1] = r;
  can[x][y][0][2] = d;
  can[x][y][0][3] = l;
  can[x][y][1][0] = l;
  can[x][y][1][1] = u;
  can[x][y][1][2] = r;
  can[x][y][1][3] = d;
  can[x][y][2][0] = d;
  can[x][y][2][1] = l;
  can[x][y][2][2] = u;
  can[x][y][2][3] = r;
  can[x][y][3][0] = r;
  can[x][y][3][1] = d;
  can[x][y][3][2] = l;
  can[x][y][3][3] = u;
}
void out() { cout << -1; }
