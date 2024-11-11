#include <bits/stdc++.h>
using namespace std;
int n, m, d, ans, a[100005], b[100005];
vector<int> g[100005];
void dfs(int x, int y) {
  if (a[x])
    b[x] = 0;
  else
    b[x] = -999999;
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] == y) continue;
    dfs(g[x][i], x);
    b[x] = max(b[x], b[g[x][i]] + 1);
  }
}
void dfs2(int x, int y, int sum) {
  if (a[x]) sum = max(sum, 0);
  int c1 = -999999, c2 = -999999;
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] == y) continue;
    if (b[g[x][i]] + 1 > c2) {
      c2 = b[g[x][i]] + 1;
      if (c2 > c1) swap(c2, c1);
    }
  }
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] == y) continue;
    int z = c1;
    if (z == b[g[x][i]] + 1) z = c2;
    dfs2(g[x][i], x, max(z + 1, sum + 1));
  }
  if (max(b[x], sum) <= d) ans++;
}
int main() {
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    a[--x] = 1;
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[--x].push_back(--y);
    g[y].push_back(x);
  }
  dfs(0, 1);
  dfs2(0, 1, -999999);
  cout << ans;
  return 0;
}
