#include <bits/stdc++.h>
using namespace std;
int n, m, h;
vector<int> vals;
vector<set<int>> adj;
vector<set<int>> adjr;
vector<bool> used;
vector<int> order, component;
vector<set<int>> adj2(1e5 + 1);
void dfs1(int v) {
  used[v] = true;
  for (auto node : adj[v])
    if (!used[node]) dfs1(node);
  order.push_back(v);
}
void dfs2(int v) {
  used[v] = true;
  component.push_back(v);
  for (auto node : adjr[v])
    if (!used[node]) dfs2(node);
}
void solve() {
  cin >> n >> m >> h;
  vals.resize(n + 1);
  adj.resize(n + 1);
  adjr.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> vals[i];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if ((vals[x] + 1) % h == vals[y]) {
      adj[x].insert(y);
    }
    if ((vals[y] + 1) % h == vals[x]) {
      adj[y].insert(x);
    }
  }
  for (int i = 1; i <= n; i++)
    for (auto node : adj[i]) adjr[node].insert(i);
  used.assign(n + 1, false);
  for (int i = 1; i <= n; i++)
    if (!used[i]) dfs1(i);
  used.assign(n + 1, false);
  vector<int> roots(n + 1, 0);
  vector<int> root_nodes;
  vector<int> comp_sizes(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int v = order[n - i - 1];
    if (!used[v]) {
      dfs2(v);
      int root = component.front();
      for (auto node : component) roots[node] = root;
      comp_sizes[root] = component.size();
      root_nodes.push_back(root);
      component.clear();
    }
  }
  for (int child = 1; child <= n; child++)
    for (auto neigh : adj[child]) {
      int root_node2 = roots[neigh];
      int root_node = roots[child];
      assert(root_node and root_node2);
      if (root_node2 != root_node) adj2[root_node].insert(root_node2);
    }
  int ans = INT_MAX, ans_node = -1;
  for (auto root_node : root_nodes)
    if (adj2[root_node].empty()) {
      int sz = comp_sizes[root_node];
      if (ans > sz) {
        ans = sz;
        ans_node = root_node;
      }
    }
  assert(ans < INT_MAX);
  cout << ans << "\n";
  for (int i = 1; i <= n; i++)
    if (roots[i] == ans_node) cout << i << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
