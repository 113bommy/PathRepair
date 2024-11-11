#include <bits/stdc++.h>
using namespace std;
int n, par[100005][20], depth[100005], A[100005], B[100005], res[5];
vector<int> e[100005];
void build_lca(int u, int p = 0) {
  if (p) depth[u] = depth[p] + 1;
  par[u][0] = p;
  for (int i = 1; i <= 18; ++i)
    if (par[u][i - 1]) par[u][i] = par[par[u][i - 1]][i - 1];
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (v != p) build_lca(v, u);
  }
}
int get_lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int i = 18; i >= 0; --i)
    if (par[v][i] && depth[par[v][i]] >= depth[u]) v = par[v][i];
  if (u == v) return u;
  for (int i = 18; i >= 0; --i)
    if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
  return par[u][0];
}
int dist(int u, int v) {
  return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int u;
    cin >> u;
    A[i - 1] = u, B[i - 1] = i;
    e[u].push_back(i), e[i].push_back(u);
  }
  build_lca(1);
  int a, b, c, ans;
  for (int i = 1; i < n; ++i) {
    if (i == 1) {
      a = A[i], b = B[i];
      cout << 1 << ' ';
      continue;
    }
    ans = 0;
    c = B[i];
    res[1] = dist(a, b);
    res[2] = dist(b, c);
    res[3] = dist(c, a);
    for (int j = 1; j <= 3; ++j) ans = max(ans, res[j]);
    if (ans == res[1])
      a = a, b = b;
    else if (ans == res[2])
      a = b, b = c;
    else if (ans == res[3])
      a = c, b = c;
    cout << ans << ' ';
  }
  return 0;
}
