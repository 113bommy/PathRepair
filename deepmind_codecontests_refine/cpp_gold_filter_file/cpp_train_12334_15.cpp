#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int MAXM = 2000 + 5;
const int MAXN = 2000 + 5;
struct Ntp {
  int x, y;
  Ntp() {}
  Ntp(int x, int y) : x(x), y(y) {}
};
queue<Ntp> q;
int deg[MAXN][MAXM], n, m, sum;
bool vis[MAXN][MAXM];
char path[MAXN][MAXM], str[MAXM];
void print() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      putchar(path[i][j]);
    }
    puts("");
  }
}
void work() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (deg[i][j] == 0) {
        puts("Not unique");
        return;
      } else {
        if (deg[i][j] == 1) {
          q.push(Ntp(i, j));
        }
      }
    }
  }
  int cnt = 0;
  while (!q.empty()) {
    Ntp t = q.front();
    q.pop();
    if (vis[t.x][t.y]) continue;
    cnt += 2;
    for (int i = 0; i < 4; ++i) {
      int tx = t.x + dx[i], ty = t.y + dy[i];
      if (tx > 0 && tx <= n && ty > 0 && ty <= m && !vis[tx][ty]) {
        vis[t.x][t.y] = vis[tx][ty] = true;
        deg[t.x][t.y] = deg[tx][ty] = -100;
        switch (i) {
          case 0:
            path[t.x][t.y] = 'v';
            path[tx][ty] = '^';
            break;
          case 1:
            path[t.x][t.y] = '^';
            path[tx][ty] = 'v';
            break;
          case 2:
            path[t.x][t.y] = '>';
            path[tx][ty] = '<';
            break;
          case 3:
            path[t.x][t.y] = '<';
            path[tx][ty] = '>';
            break;
        }
        for (int j = 0; j < 4; ++j) {
          int ttx = tx + dx[j], tty = ty + dy[j];
          if (ttx <= 0 || ttx > n || tty <= 0 || tty > m) continue;
          --deg[ttx][tty];
          if (deg[ttx][tty] == 1) q.push(Ntp(ttx, tty));
          if (deg[ttx][tty] == 0) {
            puts("Not unique");
            return;
          }
        }
      }
    }
  }
  if (cnt < sum)
    puts("Not unique");
  else
    print();
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", str + 1);
    for (int j = 1; j <= m; ++j) {
      if (str[j] == '.') {
        ++sum;
        vis[i][j] = false;
        ++deg[i][j - 1];
        ++deg[i][j + 1];
        ++deg[i - 1][j];
        ++deg[i + 1][j];
      } else {
        path[i][j] = '*';
        vis[i][j] = true;
        deg[i][j] = -100;
      }
    }
  }
  work();
  return 0;
}
