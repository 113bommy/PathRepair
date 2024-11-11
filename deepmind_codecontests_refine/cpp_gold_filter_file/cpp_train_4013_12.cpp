#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f;
const double eps = 1e-9;
const int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int n, m;
int sx, sy, tx, ty;
char s[maxn];
int mp[maxn][maxn];
int vis[maxn][maxn][4];
struct node {
  int x, y, time, st;
} now, nex;
int change(char x) {
  if (x == '*') return 0;
  if (x == '<') return 1;
  if (x == 'v') return 2;
  if (x == '>') return 4;
  if (x == '^') return 8;
  if (x == '-') return 5;
  if (x == '|') return 10;
  if (x == 'U') return 7;
  if (x == 'R') return 11;
  if (x == 'D') return 13;
  if (x == 'L') return 14;
  if (x == '+') return 15;
}
bool inbound(const node &a) {
  return a.x >= 1 && a.x <= n && a.y >= 1 && a.y <= m;
}
int bfs() {
  memset((vis), (0), sizeof(vis));
  now.x = sx;
  now.y = sy;
  now.time = 0;
  now.st = 0;
  queue<node> q;
  q.push(now);
  vis[now.x][now.y][now.st] = 1;
  while (q.size()) {
    now = q.front();
    q.pop();
    if (now.x == tx && now.y == ty) {
      return now.time;
    }
    if (vis[now.x][now.y][(now.st + 1) % 4] == 0) {
      q.push(node{now.x, now.y, now.time + 1, (now.st + 1) % 4});
      vis[now.x][now.y][(now.st + 1) % 4] = 1;
    }
    for (int i = 0; i < 4; i++) {
      nex.x = now.x + dir[i][0];
      nex.y = now.y + dir[i][1];
      if (mp[nex.x][nex.y] != 0) {
        nex.st = now.st;
        if (inbound(nex) && (mp[now.x][now.y] & (1 << (i + now.st) % 4)) &&
            (mp[nex.x][nex.y] & (1 << (i + 2 + nex.st) % 4))) {
          if (vis[nex.x][nex.y][nex.st] == 0) {
            nex.time = now.time + 1;
            vis[nex.x][nex.y][nex.st] = 1;
            q.push(nex);
          }
        }
      }
    }
  }
  return -1;
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++) {
      scanf("%s", s + 1);
      for (int j = 1; j <= m; j++) {
        mp[i][j] = change(s[j]);
      }
    }
    scanf("%d%d", &sx, &sy);
    scanf("%d%d", &tx, &ty);
    int ans = bfs();
    printf("%d\n", ans);
  }
  return 0;
}
