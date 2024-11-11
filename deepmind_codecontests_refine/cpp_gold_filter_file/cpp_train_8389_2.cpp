#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long rtn = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch <= '9' && ch >= '0')
    rtn = (rtn << 3) + (rtn << 1) + ch - '0', ch = getchar();
  return rtn;
}
const int N = 110;
int n, m, nx, ny, h, z, tx, ty;
char ch[N][N];
char dir[] = "UDLR";
void go(int x) {
  printf("%c\n", dir[x]);
  fflush(stdout);
  scanf("%d%d", &tx, &ty);
}
int pre[N * N], flag[N * N];
int id(int x, int y) { return (x - 1) * m + y - 1; }
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int s[N];
void bfs(int x, int y) {
  queue<int> q;
  q.push(id(x, y));
  flag[id(x, y)] = 1;
  int fx, fy;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    int kx = k / m + 1, ky = k % m + 1;
    if (ch[kx][ky] == 'F') {
      fx = kx;
      fy = ky;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int xx = kx + dx[i], yy = ky + dy[i];
      if (xx > 0 && xx <= n && yy > 0 && yy <= m && ch[xx][yy] != '*' &&
          !flag[id(xx, yy)]) {
        flag[id(xx, yy)] = 1;
        pre[id(xx, yy)] = k;
        q.push(id(xx, yy));
      }
    }
  }
  for (int i = id(fx, fy);; i = pre[i]) {
    int xx = i / m + 1, yy = i % m + 1;
    if (xx == x && yy == y) break;
    int cx = pre[i] / m + 1, cy = pre[i] % m + 1;
    if (cx == xx) {
      if (yy > cy)
        s[++s[0]] = z > 0 ? 3 : 2;
      else
        s[++s[0]] = z > 0 ? 2 : 3;
    } else {
      if (xx > cx)
        s[++s[0]] = h > 0 ? 1 : 0;
      else
        s[++s[0]] = h > 0 ? 0 : 1;
    }
  }
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) scanf("%s", ch[i] + 1);
  nx = 1, ny = 1;
  while (!h || !z) {
    if (!h && ch[nx + 1][ny] != '*') {
      go(1);
      if (tx != nx + 1)
        h = -1;
      else
        h = 1;
      nx = tx;
      ny = ty;
      if (ch[nx][ny] == 'F') return 0;
      while (!z && ch[nx][ny + 1] == '*') {
        int ff = 0;
        if (ch[nx + 1][ny] == '*') {
          while (nx != 1) {
            if (z == -1)
              go(1);
            else
              go(0);
            nx = tx;
            ny = ty;
          }
          ff = 1;
        }
        if (ff) break;
        if (h == -1)
          go(0);
        else
          go(1);
        nx = tx;
        ny = ty;
        if (ch[nx][ny] == 'F') return 0;
      }
    }
    if (!z && ch[nx][ny + 1] != '*') {
      go(3);
      if (ty != ny + 1)
        z = -1;
      else
        z = 1;
      nx = tx;
      ny = ty;
      if (ch[nx][ny] == 'F') return 0;
      while (!h && ch[nx + 1][ny] == '*') {
        if (z == -1)
          go(2);
        else
          go(3);
        nx = tx;
        ny = ty;
        if (ch[nx][ny] == 'F') return 0;
      }
    }
    if (ch[nx][ny] == 'F') return 0;
  }
  bfs(nx, ny);
  for (int i = s[0]; i; i--) go(s[i]);
  return 0;
}
