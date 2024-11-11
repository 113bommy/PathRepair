#include <bits/stdc++.h>
using namespace std;
inline int Read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, q, cnt, id[3005][6005], a[3005][6005], fa[18000005], v[9];
int dx[9] = {0, 1, 1, 1, -1, -1, -1, 0, 0};
int dy[9] = {0, 0, 1, -1, 0, 1, -1, 1, -1};
int findfa(int x) { return fa[x] == x ? x : fa[x] = findfa(fa[x]); }
bool chk(int x, int y, int xx, int yy) {
  cnt = 0;
  for (int i = 1; i <= 8; i++) v[i] = 0;
  for (int i = 1; i <= 8; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx == 0 || nx == n + 1) continue;
    if (ny == 0) ny = 2 * m;
    if (ny == 2 * m + 1) ny = 1;
    if (a[nx][ny]) v[++cnt] = findfa(id[nx][ny]);
  }
  for (int i = 1; i <= 8; i++) {
    int nx = xx + dx[i], ny = yy + dy[i];
    if (nx == 0 || nx == n + 1) continue;
    if (ny == 0) ny = 2 * m;
    if (ny == 2 * m + 1) ny = 1;
    if (a[nx][ny]) {
      int Id = findfa(id[nx][ny]);
      for (int i = 1; i <= cnt; i++)
        if (Id == v[i]) return false;
    }
  }
  return true;
}
void Merge(int x, int y) {
  a[x][y] = 1;
  for (int i = 1; i <= 8; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx == 0 || nx == n + 1) continue;
    if (ny == 0) ny = 2 * m;
    if (ny == 2 * m + 1) ny = 1;
    if (a[nx][ny]) {
      int fx = findfa(id[x][y]), fy = findfa(id[nx][ny]);
      if (fx == fy) continue;
      fa[fx] = fy;
    }
  }
}
signed main() {
  n = Read(), m = Read(), q = Read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 2 * m; j++) id[i][j] = ++cnt, fa[cnt] = cnt;
  if (m == 1) {
    puts("0");
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= q; i++) {
    int x = Read(), y = Read();
    if (!chk(x, y, x, y + m)) continue;
    Merge(x, y);
    Merge(x, y + m);
    ++ans;
  }
  cout << ans << endl;
  return 0;
}
