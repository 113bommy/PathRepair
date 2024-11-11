#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 20;
int n, m, cnt, cntp, deg[N][N], vis[N][N];
int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};
char money[4] = {'v', '<', '^', '>'};
char a[N][N];
struct node {
  int deg;
  int x, y;
  node(int a, int b, int t) { x = a, y = b, deg = t; }
  bool operator<(struct node t) const { return deg > t.deg; }
};
queue<struct node> q;
int main() {
  while (~scanf("%d%d", &m, &n)) {
    getchar();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) scanf("%c", &a[i][j]);
      getchar();
    }
    memset(vis, 0, sizeof(vis));
    memset(deg, 0, sizeof(deg));
    cnt = 0, cntp = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] == '.') {
          cntp++;
          struct node temp(i, j, 0);
          for (int k = 0; k < 4; k++) {
            int tx = i + dir[k][0], ty = j + dir[k][1];
            if (tx >= 0 && tx < m && ty >= 0 && ty < n) {
              if (a[tx][ty] == '.') temp.deg++;
            }
          }
          if (temp.deg == 1) q.push(temp);
          deg[i][j] = temp.deg;
        }
    while (!q.empty()) {
      struct node temp = q.front();
      q.pop();
      if (!vis[temp.x][temp.y]) {
        for (int k = 0; k < 4; k++) {
          int tx = temp.x + dir[k][0], ty = temp.y + dir[k][1];
          if (tx >= 0 && tx < m && ty >= 0 && ty < n && a[tx][ty] == '.' &&
              !vis[tx][ty]) {
            a[tx][ty] = money[k], a[temp.x][temp.y] = money[((k + 2) % 4)];
            vis[tx][ty] = 1, vis[temp.x][temp.y] = 1;
            for (int u = 0; u < 4; u++) {
              int ttx = tx + dir[u][0], tty = ty + dir[u][1];
              if (ttx >= 0 && ttx < m && tty >= 0 && tty < n &&
                  a[ttx][tty] == '.' && !vis[ttx][tty]) {
                deg[ttx][tty]--;
                if (deg[ttx][tty] == 1) {
                  struct node temp(ttx, tty, 1);
                  q.push(temp);
                }
              }
            }
            cnt += 2;
          }
        }
      }
    }
    if (cnt != cntp)
      printf("Not unique\n");
    else
      for (int i = 0; i < m; i++) printf("%s\n", a[i]);
  }
  return 0;
}
