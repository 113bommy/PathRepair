#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct four {
  int x, y, where;
  double w;
} edge[maxn];
int n, m, k, ec;
int ll[maxn], fa[maxn], x[maxn], y[maxn], z[maxn];
bool cmp(const four &a, const four &b) {
  if (a.w == b.w) return a.where < b.where;
  return a.w < b.w;
}
int doit(double noww) {
  for (int i = 1; i <= m; i++) {
    edge[i].x = x[i];
    edge[i].y = y[i];
    edge[i].where = i;
    edge[i].w = z[i];
    if ((x[i] == 1) || (y[i] == 1)) edge[i].w += noww;
  }
  sort(edge + 1, edge + m + 1, cmp);
  int use = 0, xc, yc, uc, uv;
  memset(ll, 0, sizeof(ll));
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    xc = edge[i].x;
    yc = edge[i].y;
    while (fa[xc] != xc) xc = fa[xc];
    while (fa[yc] != yc) yc = fa[yc];
    if (xc != yc) {
      if ((edge[i].x == 1) || (edge[i].y == 1)) ++use;
      fa[xc] = yc;
      ll[edge[i].where] = 1;
      uc = edge[i].x;
      while (fa[uc] != yc) {
        uv = fa[uc];
        fa[uc] = yc;
        uc = uv;
      }
      uc = edge[i].y;
      while (fa[uc] != yc) {
        uv = fa[uc];
        fa[uc] = yc;
        uc = uv;
      }
    }
  }
  return use;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; i++) scanf("%d %d %d", &x[i], &y[i], &z[i]);
  double left, right, mid;
  left = -(1e6);
  right = (1e6);
  for (int tt = 1; tt <= 100; tt++) {
    mid = (left + right) / 2;
    ec = doit(mid);
    if (ec == k) break;
    if (ec > k)
      left = mid;
    else
      right = mid;
  }
  if (ec != k) {
    cout << -1 << endl;
    return 0;
  }
  printf("%d\n", n - 1);
  ec = doit(mid);
  for (int i = 1; i <= m; i++)
    if (ll[i] == 1) printf("%d ", i);
  printf("\n");
  return 0;
}
