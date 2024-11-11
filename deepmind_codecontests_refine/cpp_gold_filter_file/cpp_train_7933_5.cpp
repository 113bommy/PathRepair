#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, step;
} now, nex;
char a[10][10];
int vis[10][10];
vector<int> mp[10][10];
int fx[9] = {0, 0, 1, -1, 0, 1, 1, -1, -1};
int fy[9] = {1, -1, 0, 0, 0, 1, -1, 1, -1};
int n = 8, m = 8;
void Bfs(int sx, int sy) {
  queue<node> s;
  now.x = sx;
  now.y = sy;
  s.push(now);
  memset(vis, 0, sizeof(vis));
  vis[sx][sy] = 1;
  while (!s.empty()) {
    now = s.front();
    if (a[now.x][now.y] == 'A') {
      printf("WIN\n");
      return;
    }
    s.pop();
    for (int i = 0; i < 9; i++) {
      nex.x = now.x + fx[i];
      nex.y = now.y + fy[i];
      nex.step = now.step;
      if (nex.x >= 0 && nex.x < n && nex.y >= 0 && nex.y < m) {
        if (i != 4 && vis[nex.x][nex.y] == 1) continue;
        int flag = 0;
        for (int k = 0; k < mp[nex.x][nex.y].size(); k++) {
          if (nex.step == mp[nex.x][nex.y][k] ||
              nex.step + 1 == mp[nex.x][nex.y][k])
            flag = 1;
        }
        if (flag == 0) {
          nex.step += 1;
          s.push(nex);
          vis[nex.x][nex.y] = 1;
        }
      }
    }
  }
  printf("LOSE\n");
  return;
}
int main() {
  for (int i = 0; i < 8; i++) {
    scanf("%s", a[i]);
  }
  int sx, sy;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (a[i][j] == 'M') {
        sx = i;
        sy = j;
      }
      if (a[i][j] == 'S') {
        mp[i][j].push_back(0);
        for (int k = 1; k < 8; k++) {
          int xx = i + k;
          int y = j;
          if (xx < 8) {
            mp[xx][y].push_back(k);
          }
        }
      }
    }
  }
  Bfs(sx, sy);
}
