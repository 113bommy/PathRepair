#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
bool mat[55][55];
int n;
int dx[] = {0, -1, -2, 0, 1, 2};
int dy[] = {-2, -1, 0, 2, 1, 0};
void location(int &x, int &y, int xt, int yt, bool t) {
  mat[xt][yt] = t;
  x = xt;
  y = yt;
}
bool querry(int x1, int y1, int x2, int y2) {
  if (x1 + y1 + 2 > x2 + y2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  printf("? %d %d %d %d\n", x1, y1, x2, y2);
  fflush(stdout);
  int temp;
  scanf("%d", &temp);
  return bool(temp);
}
void bfs(int x, int y) {
  bool vis[55][55];
  memset(vis, 0, sizeof(vis));
  queue<pair<int, int>> Q;
  Q.push(make_pair(x, y));
  vis[x][y] = 1;
  vis[n][n] = 1;
  while (!Q.empty()) {
    pair<int, int> t = Q.front();
    Q.pop();
    for (int i = 0; i < 6; i++) {
      int tx = t.first + dx[i];
      int ty = t.second + dy[i];
      if (tx < 1 || tx > n || ty < 1 || ty > n) continue;
      if (!vis[tx][ty]) {
        if (querry(tx, ty, t.first, t.second))
          mat[tx][ty] = mat[t.first][t.second];
        else
          mat[tx][ty] = !mat[t.first][t.second];
        Q.push(make_pair(tx, ty));
        vis[tx][ty] = 1;
      }
    }
  }
}
int x2, y2;
bool dfs(int x, int y, int deep, bool r) {
  if (deep == 4) return false;
  int dx[] = {0, 1};
  int dy[] = {1, 0};
  for (int i = 0; i < 2; i++) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (tx > n || ty > n) continue;
    if (deep + 1 == 4 && r ^ mat[tx][ty]) {
      x2 = tx;
      y2 = ty;
      return true;
    }
    return dfs(tx, ty, deep + 1, r ^ mat[tx][ty]);
  }
  return false;
}
int main() {
  int i, j;
  scanf("%d", &n);
  mat[1][1] = mat[1][2] = 1;
  mat[n][n] = 0;
  bfs(1, 1);
  bfs(1, 2);
  int flag = 0;
  int turn = 0;
  for (i = 1; !flag && i <= n; i++)
    for (j = 1; !flag && j <= n; j++) {
      if (dfs(i, j, 1, mat[i][j])) {
        flag = 1;
        bool t = querry(i, j, x2, y2);
        if (t && mat[i][j] != mat[x2][y2])
          turn = 1;
        else if (!t && mat[i][j] == mat[x2][y2])
          turn = 1;
      }
    }
  if (turn) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if ((i + j) % 2) mat[i][j] = !mat[i][j];
      }
    }
  }
  printf("!\n");
  fflush(stdout);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d", mat[i][j]);
      fflush(stdout);
    }
    printf("\n");
  }
}
