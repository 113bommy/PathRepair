#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int INF = 1e7 + 10;
int n, m;
char s[N][N];
int sx, sy;
bool vis[N][N];
int getr(int cntc) {
  int ed = m;
  for (int j = sy; j < m; ++j) {
    if (s[sx][j] != 'X') {
      ed = j;
      break;
    }
  }
  if (sx + cntc >= n) return 1;
  int bg = -1;
  for (int j = sy; j < ed; ++j) {
    if (s[sx + cntc][j] == 'X') {
      bg = j;
      break;
    }
  }
  if (bg == -1) return 1;
  return ed - bg;
}
int getc(int cntr) {
  int ed = n;
  for (int i = sx; i < n; ++i) {
    if (s[i][sy] != 'X') {
      ed = i;
      break;
    }
  }
  if (sy + cntr >= m) return 1;
  int bg = -1;
  for (int i = sx; i < ed; ++i) {
    if (s[i][sy + cntr] == 'X') {
      bg = i;
      break;
    }
  }
  if (bg == -1) return 1;
  return ed - bg;
}
void setvis(int a, int b, int c, int d) {
  for (int i = a; i <= c; ++i) {
    for (int j = b; j <= d; ++j) {
      vis[i][j] = 1;
    }
  }
}
int check() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vis[i][j] && s[i][j] != 'X') return 0;
      if (!vis[i][j] && s[i][j] == 'X') return 0;
    }
  }
  return 1;
}
int solve(int x, int y, int a, int b, bool f) {
  if (f) {
    int ny = y;
    for (; ny + b - 1 < n; ++ny) {
      if (s[x][ny + b - 1] != 'X') break;
    }
    ny--;
    if (ny <= y) {
      return check();
    }
    setvis(x, y + b, x + a - 1, ny + b - 1);
    return solve(x, ny, a, b, !f);
  } else {
    int nx = x;
    for (; nx + a - 1 < n; ++nx) {
      if (s[nx + a - 1][y] != 'X') break;
    }
    nx--;
    if (nx <= x) {
      return check();
    }
    setvis(x + a, y, nx + a - 1, y + b - 1);
    return solve(nx, y, a, b, !f);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'X') {
        sx = i, sy = j;
        i = n, j = m;
      }
    }
  }
  int cntc = 0;
  for (int i = sx; i < n; ++i) {
    if (s[i][sy] == 'X')
      ++cntc;
    else
      break;
  }
  int cntr = 0;
  for (int j = sy; j < m; ++j) {
    if (s[sx][j] == 'X')
      ++cntr;
    else
      break;
  }
  int len = getr(cntc);
  int ans = INF;
  memset(vis, 0, sizeof(vis));
  if (setvis(sx, sy, sx + cntc - 1, sy + len - 1), solve(sx, sy, cntc, len, 1))
    ans = min(ans, cntc * len);
  len = getc(cntr);
  memset(vis, 0, sizeof(vis));
  if (setvis(sx, sy, sx + len - 1, sy + cntr - 1), solve(sx, sy, len, cntr, 0))
    ans = min(ans, cntr * len);
  printf("%d\n", ans >= INF ? -1 : ans);
  return 0;
}
