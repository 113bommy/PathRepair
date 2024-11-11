#include <bits/stdc++.h>
using namespace std;
const int _ = 200020;
int n, m, temp, fa[_][21], dep[_];
int lca(int x, int y) {
  int i;
  if (dep[x] < dep[y]) swap(x, y);
  for (i = 19; i >= 0; --i)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (i = 19; i >= 0; --i)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int dis(int x, int y) { return dep[x] + dep[y] - dep[lca(x, y)] * 2; }
int main(void) {
  int x = 1, y = 1, ans = 0, i, j, t1, t2;
  scanf("%d", &n);
  for (i = 2; i <= n; ++i) {
    scanf("%d", &fa[i][0]);
    for (j = 1; j <= 19; ++j) fa[i][j] = fa[fa[i][j - 1]][j - 1];
    dep[i] = dep[fa[i][0]] + 1;
    t1 = dis(x, i);
    t2 = dis(y, i);
    if (t1 > ans)
      ans = t1, y = i;
    else if (t2 > ans)
      ans = t2, x = i;
    printf("%d ", ans);
  }
}
