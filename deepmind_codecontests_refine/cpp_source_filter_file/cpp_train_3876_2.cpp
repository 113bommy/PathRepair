#include <bits/stdc++.h>
inline long long ceil_div(long long a, long long b) { return (a + b - 1) / b; }
using namespace std;
inline int qr() {
  int f = 0, fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fu = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + (c & 15);
    c = getchar();
  }
  return f * fu;
}
const int N = 305, M = 2e6 + 10;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int a[N][N], id[N][N], ans[M], n, m, q, tot, num;
struct node {
  int x, y, c, p;
} op[M];
struct UF {
  int fa[M << 1];
  int get(int x) { return x == fa[x] ? x : (fa[x] = get(fa[x])); }
  inline void merge(int x, int y) {
    if (same(x, y)) return;
    num--, fa[get(x)] = get(y);
  }
  inline bool same(int x, int y) { return get(x) == get(y); }
} U;
inline void merge(int x, int y) {
  for (int i = 0, nx, ny; i < 4; i++) {
    nx = x + dx[i], ny = y + dy[i];
    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
    if (a[x][y] == a[nx][ny]) {
      U.merge(id[x][y], id[nx][ny]);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1, x, y, c; i <= q; i++) {
    scanf("%d%d%d", &x, &y, &c);
    op[i] = {x, y, c, a[x][y]}, a[x][y] = c;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = 0;
  for (int i = 1, x, y; i <= q; i++) {
    if (op[i].c == op[i].p) continue;
    x = op[i].x, y = op[i].y, num = 0;
    a[x][y] = op[i].c, id[x][y] = ++tot, U.fa[tot] = tot;
    merge(x, y), ans[i] += num;
  }
  tot = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) id[i][j] = ++tot, U.fa[tot] = tot;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) merge(i, j);
  for (int i = q, x, y; i >= 1; i--) {
    if (op[i].c == op[i].p) continue;
    x = op[i].x, y = op[i].y, num = 0;
    a[x][y] = op[i].p, id[x][y] = ++tot, U.fa[tot] = tot;
    merge(x, y), ans[i] -= num;
  }
  ans[0] = 1;
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i] += ans[i - 1]);
}
