#include <bits/stdc++.h>
using namespace std;
struct ww {
  int a, b;
} e[10010];
int i, j, k, n, m, x, y;
int f[10010][510], h[10010][510], a[510];
int get(int x, int y) { return f[x][y] == y ? y : f[x][y] = get(x, f[x][y]); }
int get_(int x, int y) { return h[x][y] == y ? y : h[x][y] = get_(x, h[x][y]); }
inline void prepare() {
  int i, j;
  for (i = 1; i <= n; i++) f[0][i] = i;
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) f[i][j] = f[i - 1][j];
    f[i][get(i, e[i].a)] = get(i, e[i].b);
    for (j = 1; j <= n; j++) get(i, j);
  }
  for (i = 1; i <= n; i++) h[m + 1][i] = i;
  for (i = m; i; i--) {
    for (j = 1; j <= n; j++) h[i][j] = h[i + 1][j];
    h[i][get_(i, e[i].a)] = get_(i, e[i].b);
    for (j = 1; j <= n; j++) get_(i, j);
  }
}
int get__(int x) { return a[x] == x ? x : a[x] = get__(a[x]); }
inline void work(int x, int y) {
  int i, an = 0;
  for (i = 1; i <= n; i++) a[i] = i;
  for (i = 1; i <= n; i++) a[get__(i)] = get__(f[x - 1][i]);
  for (i = 1; i <= n; i++) a[get__(i)] = get__(h[y + 1][i]);
  for (i = 1; i <= n; i++) an += i == get__(i);
  printf("%d\n", an);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) scanf("%d%d", &e[i].a, &e[i].b);
  prepare();
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    work(x, y);
  }
  return 0;
}
