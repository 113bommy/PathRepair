#include <bits/stdc++.h>
using namespace std;
int n, m;
int mark[110][110];
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int check(int x, int y) {
  if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
  return 0;
}
int dfs(int id, int x1, int y1, int x2, int y2) {
  if (x1 == x2 && y1 == y2) return 1;
  if (id >= 10) return 2;
  int i, j;
  if (id % 2 == 1) {
    for (i = 0; i < 4 && !mark[x1][y1]; i++) {
      if (check(x1 + dx[i], y1 + dy[i])) {
        if (dfs(id + 1, x1 + dx[i], y1 + dy[i], x2, y2) == 1) return 1;
      }
    }
    for (i = 0; i < 4 && !mark[x2][y2]; i++) {
      if (check(x2 + dx[i], y2 + dy[i])) {
        if (dfs(id + 1, x1, y1, x2 + dx[i], y2 + dy[i]) == 1) return 1;
      }
    }
    return 2;
  } else {
    for (i = -1; i <= 1; i++) {
      for (j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) continue;
        if (check(x1 + i, y1 + j) && !mark[x1 + i][y1 + j] &&
            (x1 + i != x2 || y1 + j != y2)) {
          mark[x1 + i][y1 + j] = 1;
          if (dfs(id + 1, x1, y1, x2, y2) == 2) {
            mark[x1 + i][y1 + j] = 0;
            return 2;
          }
          mark[x1 + i][y1 + j] = 0;
        }
      }
    }
    for (i = -1; i <= 1; i++) {
      for (j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) continue;
        if (check(x2 + i, y2 + j) && !mark[x2 + i][y2 + j] &&
            (x2 + i != x1 || y2 + j != y1)) {
          mark[x2 + i][y2 + j] = 1;
          if (dfs(id + 1, x1, y1, x2, y2) == 2) {
            mark[x2 + i][y2 + j] = 0;
            return 2;
          }
          mark[x2 + i][y2 + j] = 0;
        }
      }
    }
    return 1;
  }
}
int main() {
  int x1, y1, x2, y2;
  int i, j;
  while (scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2) != EOF) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        mark[i][j] = 0;
      }
    }
    if (dfs(1, x1, y1, x2, y2) == 1)
      printf("First\n");
    else
      printf("Second\n");
  }
  return 0;
}
