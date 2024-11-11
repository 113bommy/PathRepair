#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a, b, k, t, x, y, n, q, i, j, up[N][20], ln, dist[N], tin[N], tout[N];
vector<int> v[N];
void dfs(int u, int pr) {
  tin[u] = ++t;
  up[u][0] = pr;
  for (i = 1; i <= ln; ++i) up[u][i] = up[up[u][i - 1]][i - 1];
  for (auto j : v[u])
    if (pr != j) {
      dist[j] = dist[u] + 1;
      dfs(j, u);
    }
  tout[u] = ++t;
}
int check(int x, int y) { return tin[x] <= tin[y] && tout[x] >= tout[y]; }
int lca(int x, int y) {
  if (check(x, y)) return x;
  if (check(y, x)) return y;
  for (j = ln; j >= 0; --j) {
    if (!check(up[x][j], y)) x = up[x][j];
  }
  return up[x][0];
}
int get(int x, int y) {
  int h = lca(x, y);
  return dist[x] + dist[y] - 2 * dist[h];
}
int main() {
  cin >> n;
  for (i = 1; i < n; ++i) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  while ((1 << ln) <= n) ++ln;
  ++ln;
  dfs(1, 1);
  cin >> q;
  for (i = 1; i <= q; ++i) {
    cin >> x >> y >> a >> b >> k;
    vector<int> ans;
    ans.push_back(get(a, b));
    ans.push_back(get(a, x) + get(b, y) + 1);
    ans.push_back(get(a, y) + get(b, x) + 1);
    int f = 0;
    for (auto j : ans) {
      if (j <= k && (k - j) % 2 == 0) f = 1;
    }
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
