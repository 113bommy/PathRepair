#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1, maxn = 1000 + 10;
int n, m;
char c[maxn][maxn];
int f[maxn][maxn];
int qx[maxn * maxn], qy[maxn * maxn];
bool v[maxn][maxn];
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
void setIO(string name) {}
int gI() {
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  int p = 0, flag = 1;
  if (c == '-') flag = -1, c = getchar();
  while (c >= '0' && c <= '9') p = p * 10 + c - '0', c = getchar();
  return p * flag;
}
bool legal(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && v[x][y]);
}
void Run(int x, int y) {
  int l = 0, r = 1;
  bool v2[maxn][maxn];
  memset(v, 0, sizeof(v));
  v2[x][y] = 1;
  f[x][y] = 0;
  qx[1] = x, qy[1] = y;
  while (l ^ r) {
    ++l;
    for (int k = 0; k < 4; ++k) {
      x = qx[l] + dx[k], y = qy[l] + dy[k];
      if (legal(x, y) && !v2[x][y]) {
        f[x][y] = f[qx[l]][qy[l]] + 1;
        ++r;
        v2[qx[r] = x][qy[r] = y] = 1;
      }
    }
  }
}
int main() {
  setIO("test");
  scanf("%d %d\n", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", c[i]);
  memset(f, 0, sizeof(f));
  int x, y;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (c[i][j] == 'E') x = i, y = j;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (c[i][j] == 'T')
        v[i][j] = 0;
      else
        v[i][j] = 1;
  Run(x, y);
  int S, ans = 0;
  ;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (c[i][j] == 'S') S = f[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if ('0' <= c[i][j] && c[i][j] <= '9' && f[i][j] <= S && f[i][j]) {
        ans += c[i][j] - '0';
      }
  printf("%d\n", ans);
  return 0;
}
