#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 5e5 + 9, MOD = 1e9 + 7;
string str[N];
vector<int> adj[N];
vector<pair<int, int>> query[N];
int depth[N], sz[N], big[N], ans[N];
set<string> st[N];
void dfs(int node, int par, int dep) {
  sz[node]++;
  depth[node] = dep;
  for (auto it : adj[node]) {
    if (it == par) continue;
    dfs(it, node, dep + 1);
    sz[node] += sz[it];
  }
}
void add(int node, int par, int type) {
  if (type == 1)
    st[depth[node]].insert(str[node]);
  else if (st[depth[node]].count(str[node]))
    st[depth[node]].erase(str[node]);
  for (auto it : adj[node]) {
    if (it == par || big[it]) continue;
    add(it, node, type);
  }
}
void solve(int node, int par, int keep) {
  int bigChild = -1;
  for (auto it : adj[node]) {
    if (it == par) continue;
    if (bigChild == -1)
      bigChild = it;
    else if (sz[it] > sz[bigChild])
      bigChild = it;
  }
  for (auto it : adj[node]) {
    if (it == par || it == bigChild) continue;
    solve(it, node, 0);
  }
  if (bigChild != -1) solve(bigChild, node, 1), big[bigChild] = 1;
  add(node, par, 1);
  for (auto it : query[node]) {
    ans[it.second] = st[it.first].size();
  }
  if (bigChild != -1) big[bigChild] = 0;
  if (!keep) add(node, par, -1);
}
void runtestcase() {
  int n, par, dep;
  cin >> n;
  vector<int> roots;
  for (int i = 1; i <= n; ++i) {
    cin >> str[i] >> par;
    if (!par) {
      roots.push_back(i);
      continue;
    }
    adj[i].push_back(par);
    adj[par].push_back(i);
  }
  for (auto root : roots) dfs(root, root, 1);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> par >> dep;
    dep += depth[par];
    query[par].push_back({dep, i});
  }
  for (auto root : roots) solve(root, root, 0);
  for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
}
int main() {
  cout << fixed << setprecision(12), ios::sync_with_stdio(false),
      cin.tie(nullptr), cout.tie(nullptr);
  int t = 1, tt = 1;
  while (t) {
    runtestcase();
    --t, ++tt;
  }
}
