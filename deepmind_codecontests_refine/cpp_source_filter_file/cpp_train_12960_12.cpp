#include <bits/stdc++.h>
inline int read() {
  int data = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
  return data * w;
}
const int N(505);
struct node {
  int p, l, r;
} a[N];
int n, f[N][N], g[N], b[N], cnt;
int Pos(int x) { return std::lower_bound(b, b + cnt, x) - b; }
int main() {
  n = read(), b[cnt++] = -1e9;
  for (int i = 1, p, l; i <= n; i++)
    p = read(), l = read(), a[i] = (node){p, p - l, p + l}, b[cnt++] = p,
    b[cnt++] = p - l, b[cnt++] = p + l;
  std::sort(b, b + cnt), cnt = std::unique(b, b + cnt) - b;
  for (int i = 1; i <= n; i++)
    a[i].p = Pos(a[i].p), a[i].l = Pos(a[i].l), a[i].r = Pos(a[i].r);
  std::sort(a + 1, a + n + 1, [](node x, node y) { return x.p < y.p; });
  for (int i = 1; i <= n; i++) {
    std::memcpy(f[i], f[i - 1], sizeof f[i]), std::memset(g, 0, sizeof g);
    int l = a[i].l, r = a[i].r, p = a[i].p, r1 = p;
    g[r1] = f[i - 1][l] + b[r1] - b[l];
    for (int j = i - 1; j; j--)
      r1 = std::max(r1, a[j].r),
      g[r1] = std::max(g[r1], f[j - 1][l] + b[r1] - b[l]);
    for (int j = cnt; j >= l; j--)
      f[i][j] = std::max(f[i][j], g[j]),
      g[j - 1] = std::max(g[j - 1], g[j] - b[j] + b[j - 1]);
    for (int j = p; j <= r; j++)
      f[i][j] = std::max(f[i][j], f[i - 1][p] + b[j] - b[p]);
    for (int j = 1; j <= cnt; j++) f[i][j] = std::max(f[i][j], f[i][j - 1]);
  }
  printf("%d\n", f[n][cnt]);
  return 0;
}
