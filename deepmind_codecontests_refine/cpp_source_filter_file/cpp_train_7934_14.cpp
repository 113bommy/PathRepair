#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, step;
} now, nex;
char a[10][10];
vector<int> mp[10][10];
int fx[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
int fy[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int n = 8, m = 8;
int winday = -1;
int daedday = 10;
void Bfs(int sx, int sy) {
  queue<node> s;
  now.x = sx;
  now.y = sy;
  now.step = 0;
  s.push(now);
  while (!s.empty()) {
    now = s.front();
    if (a[now.x][now.y] == 'A' || now.step == winday) {
      printf("WIN\n");
      return;
    }
    s.pop();
    for (int i = 0; i < 9; i++) {
      nex.x = now.x + fx[i];
      nex.y = now.y + fy[i];
      nex.step = now.step + 1;
      if (nex.x >= 0 && nex.x < n && nex.y >= 0 && nex.y < m) {
        bool flag = true;
        for (int k = 0; k < mp[nex.x][nex.y].size(); k++) {
          if (nex.step == mp[nex.x][nex.y][k] - 1 ||
              nex.step == mp[nex.x][nex.y][k]) {
            flag = false;
            break;
          }
        }
        if (flag) s.push(nex);
      }
    }
  }
  printf("LOSE\n");
  return;
}
int main() {
  for (int i = 0; i < 8; i++) scanf("%s", a[i]);
  int sx, sy;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (a[i][j] == 'M') {
        sx = i;
        sy = j;
      } else if (a[i][j] == 'S') {
        winday = max(winday, 8 - i);
        for (int k = 0; i + k < 8; k++) mp[i + k][j].push_back(k);
      }
    }
  }
  Bfs(sx, sy);
}
