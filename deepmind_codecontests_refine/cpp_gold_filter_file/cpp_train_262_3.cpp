#include <bits/stdc++.h>
using namespace std;
vector<int> e[400040];
int ans[400040], sz[400040], uz[400040], dz[400040], n;
void dfs(int x, int fa) {
  int i, y;
  sz[x] = 1;
  for (i = 0; i < e[x].size(); i++) {
    y = e[x][i];
    if (y == fa) continue;
    dfs(y, x);
    if (sz[y] - dz[y] > n / 2) ans[x] = 0;
    sz[x] += sz[y];
    dz[x] = max(dz[x], dz[y]);
  }
  if (sz[x] <= n / 2) dz[x] = sz[x];
}
void dfs1(int x, int fa) {
  if (n - sz[x] - uz[x] > n / 2) ans[x] = 0;
  if (n - sz[x] <= n / 2) uz[x] = n - sz[x];
  int i, y, mx = uz[x], p = -1, m = 0;
  for (i = 0; i < e[x].size(); i++) {
    y = e[x][i];
    if (y == fa) continue;
    if (dz[y] > mx) {
      p = y;
      m = mx;
      mx = dz[y];
    } else if (dz[y] > m)
      m = dz[y];
  }
  for (i = 0; i < e[x].size(); i++) {
    y = e[x][i];
    if (y == fa) continue;
    if (y == p)
      uz[y] = m;
    else
      uz[y] = mx;
    dfs1(y, x);
  }
}
void solve() {
  int i, x, y;
  cin >> n;
  for (i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (i = 1; i <= n; i++) ans[i] = 1;
  dfs(1, 0);
  dfs1(1, 0);
  for (i = 1; i <= n; i++) printf("%d ", ans[i]);
}
int main(void) {
  int T = 1;
  while (T--) {
    solve();
  }
}
