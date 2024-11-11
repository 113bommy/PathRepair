#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20, LG = 20;
int n, par[N][LG], h[N], hv[N], U, V, sum;
vector<int> gr[N];
bool vis[N], seen[N];
vector<pair<pair<int, int>, int>> ans;
void dfs_find_par(int v) {
  for (int i = 1; i < LG; i++) par[v][i] = par[par[v][i - 1]][i - 1];
  for (auto u : gr[v])
    if (u != par[v][0]) par[u][0] = v, h[u] = h[v] + 1, dfs_find_par(u);
}
void dfs_find_ghotr(int v, int p) {
  for (auto u : gr[v])
    if (u != p) hv[u] = hv[v] + 1, dfs_find_ghotr(u, v);
}
int k_par(int v, int k) {
  for (int i = LG - 1; i >= 0; i--)
    if (k & (1 << i)) v = par[v][i];
  return v;
}
int LCA(int u, int v) {
  if (h[v] > h[u]) swap(u, v);
  u = k_par(u, h[u] - h[v]);
  if (u == v) return v;
  for (int i = LG - 1; i >= 0; i--)
    if (par[v][i] != par[u][i]) u = par[u][i], v = par[v][i];
  return par[v][0];
}
int dis(int u, int v) { return h[v] + h[u] - 2 * h[LCA(u, v)]; }
void vis_ghotr(int u, int v) {
  int l = LCA(u, v);
  vis[l] = true;
  while (u != l) vis[u] = true, u = par[u][0];
  while (v != l) vis[v] = true, v = par[v][0];
}
void get_ord(int v, int p) {
  for (auto u : gr[v])
    if (u != p && !vis[u]) get_ord(u, v);
  if (vis[v]) return;
  int mx = U;
  if (dis(V, v) > dis(U, v)) mx = V;
  sum += dis(v, mx);
  ans.push_back({{mx, v}, v});
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  if (n == 2) return cout << 1 << endl << "1 2 1" << endl, 0;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v), gr[v].push_back(u);
  }
  int root = 1;
  if (gr[1].size() == 1)
    for (int i = 1; i <= n; i++)
      if (gr[i].size() != 1) root = i;
  dfs_find_par(root);
  V = 1;
  for (int i = 1; i <= n; i++)
    if (h[i] > h[V]) V = i;
  dfs_find_ghotr(V, -1);
  U = V;
  for (int i = 1; i <= n; i++)
    if (hv[i] > hv[U]) U = i;
  vis_ghotr(U, V);
  for (int i = 1; i <= n; i++)
    if (vis[i]) get_ord(i, -1);
  int l = LCA(U, V);
  while (U != l) {
    if (U == 0) break;
    sum += dis(U, V);
    ans.push_back({{U, V}, U});
    U = par[U][0];
  }
  while (V != l) {
    if (V == 0) break;
    sum += dis(V, l);
    ans.push_back({{V, l}, V});
    V = par[V][0];
  }
  cout << sum << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first.first << " " << ans[i].first.second << " "
         << ans[i].second << '\n';
  return 0;
}
