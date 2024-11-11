#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
struct node {
  int ne, to, id, val;
} e[2 * N];
int he[N], tot = 0, v[N], vis[N], n, m, ans[N], fa[N];
void add(int x, int y, int id, int val) {
  e[++tot].ne = he[x];
  he[x] = tot;
  e[tot].to = y;
  e[tot].id = id;
  e[tot].val = val;
}
int find(int x) {
  if (fa[x] != x) fa[x] = find(fa[x]);
  return fa[x];
}
int dfs(int x, int ft) {
  int i, y, sum = 0, tmp;
  vis[x] = 1;
  for (i = he[x]; i; i = e[i].ne) {
    y = e[i].to;
    if (y != ft) {
      tmp = dfs(y, x);
      sum += tmp;
      ans[e[i].id] = e[i].val * tmp;
    }
  }
  return sum - v[x];
}
int main() {
  int i, j, k;
  int x, y, x1, y1;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (i = 1; i <= n; i++) fa[i] = i;
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    x1 = find(x);
    y1 = find(y);
    if (x1 != y1) {
      fa[x1] = y1;
      add(x, y, i, 1);
      add(y, x, i, -1);
    }
  }
  bool fl = 1;
  for (i = 1; i <= n; i++)
    if (!vis[i])
      if (dfs(i, 0) != 0) {
        fl = 0;
        break;
      }
  if (!fl) {
    printf("Impossible\n");
    return 0;
  }
  printf("Possible\n");
  for (i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
