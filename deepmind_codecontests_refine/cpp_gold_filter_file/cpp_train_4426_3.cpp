#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10, LG = 18, MAX_A = 10;
vector<int> G[MAX_N];
vector<int> people[MAX_N];
int depth[MAX_N];
int up[MAX_N][LG];
vector<int> st[MAX_N][LG];
vector<int> merge(vector<int>& l, vector<int>& r) {
  vector<int> ret;
  merge(begin(l), end(l), begin(r), end(r), back_inserter(ret));
  while (ret.size() > MAX_A) ret.pop_back();
  return ret;
}
void dfs_build(int u, int p, int d) {
  depth[u] = d;
  for (int bit = 1; bit < LG; bit++) {
    int v = up[u][bit - 1];
    if (v == -1) break;
    up[u][bit] = up[v][bit - 1];
    st[u][bit] = merge(st[u][bit - 1], st[v][bit - 1]);
  }
  for (int v : G[u]) {
    if (v == p) continue;
    up[v][0] = u;
    st[v][0] = people[v];
    dfs_build(v, u, d + 1);
  }
}
vector<int> get(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  vector<int> x, y;
  int k = depth[u] - depth[v];
  for (int bit = LG - 1; bit >= 0; bit--) {
    if ((k >> bit) & 1) {
      x = merge(x, st[u][bit]);
      u = up[u][bit];
    }
  }
  if (u == v) return merge(x, people[u]);
  for (int bit = LG - 1; bit >= 0; bit--) {
    if (up[u][bit] != up[v][bit]) {
      x = merge(x, st[u][bit]);
      y = merge(y, st[v][bit]);
      u = up[u][bit];
      v = up[v][bit];
    }
  }
  x = merge(x, people[u]);
  y = merge(y, people[v]);
  int p = up[u][0];
  x = merge(x, people[p]);
  return merge(x, y);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(up, -1, sizeof up);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= m; i++) {
    int c;
    cin >> c;
    people[c].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    while (people[i].size() > MAX_A) people[i].pop_back();
  }
  dfs_build(1, -1, 0);
  while (q--) {
    int u, v, a;
    cin >> u >> v >> a;
    vector<int> ans = get(u, v);
    while (int(ans.size()) > a) ans.pop_back();
    cout << int(ans.size());
    for (int elem : ans) cout << ' ' << elem;
    cout << '\n';
  }
  return (0);
}
