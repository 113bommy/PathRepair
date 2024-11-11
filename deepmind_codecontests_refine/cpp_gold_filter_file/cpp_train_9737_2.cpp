#include <bits/stdc++.h>
using namespace std;
int x, y, p[1000010], a[1000010], b[1000010], c[1000010], d[1000010],
    fa[2][1000010], ct, n;
vector<int> vc[2][1000010];
int fd(int x) { return p[x] == x ? x : p[x] = fd(p[x]); }
void dfs(int x, int y, int ff) {
  for (auto i : vc[y][x])
    if (i != ff) {
      fa[y][i] = x;
      dfs(i, y, x);
    }
}
void gt(int x, int ff) {
  for (auto i : vc[0][x])
    if (i != ff) {
      gt(i, x);
      if (x != fa[1][i] && i != fa[1][x]) {
        a[++ct] = i;
        b[ct] = x;
        c[ct] = fd(i);
        d[ct] = fa[1][fd(i)];
      }
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    vc[0][x].push_back(y);
    vc[0][y].push_back(x);
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    vc[1][x].push_back(y);
    vc[1][y].push_back(x);
  }
  dfs(1, 0, 0);
  dfs(1, 1, 0);
  p[1] = 1;
  for (int i = 2; i <= n; i++) {
    int x = fa[1][i];
    if (x == fa[0][i] || i == fa[0][x])
      p[i] = x;
    else
      p[i] = i;
  }
  gt(1, 0);
  printf("%d\n", ct);
  for (int i = 1; i <= ct; i++) printf("%d %d %d %d\n", a[i], b[i], c[i], d[i]);
}
