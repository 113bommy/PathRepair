#include <bits/stdc++.h>
using namespace std;
int n, m, ans[1000005], fa[1000005], f[1000005], x[1000005], y[1000005], cnt;
struct node {
  int num, id, x, y;
  bool operator<(const node &a) const { return num < a.num; }
} a[1000005];
int root(int u) {
  if (fa[u] == u) return u;
  return fa[u] = root(fa[u]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, p; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &p);
      ++cnt;
      a[cnt] = (node){p, cnt, i, j + n};
    }
  sort(a + 1, a + cnt + 1);
  for (int i = 1, j, rt1, rt2; i <= cnt; i = j) {
    for (j = i; a[j].num == a[i].num; ++j)
      ;
    for (int k = i; k < j; ++k) {
      fa[a[k].x] = a[k].x, fa[a[k].y] = a[k].y;
      f[a[k].x] = f[a[k].y] = 0;
    }
    for (int k = i; k < j; ++k) {
      rt1 = root(a[k].x), rt2 = root(a[k].y);
      fa[rt1] = rt2;
      f[rt2] = max(f[rt2], max(f[rt1], max(x[a[k].x], y[a[k].y])));
    }
    for (int k = i; k < j; ++k) {
      ans[a[k].id] = max(f[root(a[k].x)], f[root(a[k].y)]) + 1;
      x[a[k].x] = max(x[a[k].x], ans[a[k].id]),
      y[a[k].y] = max(y[a[k].y], ans[a[k].id]);
    }
  }
  cnt = 0;
  for (int i = 1; i <= n; ++i, puts(""))
    for (int j = 1; j <= m; ++j) printf("%d ", ans[++cnt]);
  return 0;
}
