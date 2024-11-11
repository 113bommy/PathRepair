#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
vector<pair<int, int>> v, st[4 * N];
int in[N], out[N], val[N], dep[N];
vector<int> adj[N];
int timer = 0;
void dfs(int u, int p) {
  if (p != -1)
    dep[u] = dep[p] + 1;
  else
    dep[u] = 0;
  in[u] = timer++;
  v.emplace_back(dep[u], val[u]);
  for (int c : adj[u]) {
    if (c == p) continue;
    dfs(c, u);
  }
  out[u] = timer - 1;
}
void build(int p, int l, int r) {
  if (l == r) {
    st[p] = {v[l]};
  } else {
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    merge(st[p * 2].begin(), st[p * 2].end(), st[p * 2 + 1].begin(),
          st[p * 2 + 1].end(), back_inserter(st[p]));
    for (int i = 1; i < st[p].size(); ++i)
      st[p][i].second = min(st[p][i].second, st[p][i - 1].second);
  }
}
int query(int p, int l, int r, int i, int j, int mxDep) {
  if (r < i || l > j || i > j) return 2e9;
  if (l >= i && r <= j) {
    auto it =
        upper_bound((st[p]).begin(), (st[p]).end(), make_pair(mxDep, (int)2e9));
    if (it == st[p].begin()) return 2e9;
    return (--it)->second;
  }
  int mid = (l + r) / 2;
  int p1 = query(p * 2, l, mid, i, j, mxDep);
  int p2 = query(p * 2 + 1, mid + 1, r, i, j, mxDep);
  return min(p1, p2);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, r;
  cin >> n >> r;
  for (int i = 1; i <= n; ++i) cin >> val[i];
  for (int i = 1; i < n; ++i) {
    int u, c;
    cin >> u >> c;
    adj[u].push_back(c);
    adj[c].push_back(u);
  }
  dfs(r, -1);
  build(1, 0, n - 1);
  int q, last = 0;
  cin >> q;
  while (q--) {
    int x, k;
    cin >> x >> k;
    x = (x + last) % n + 1;
    k = (k + last) % n;
    last = query(1, 0, n - 1, in[x], out[x], dep[x] + k);
    cout << last << "\n";
  }
}
