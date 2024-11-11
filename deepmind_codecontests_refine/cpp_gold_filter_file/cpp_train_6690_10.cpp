#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> adj;
vector<long long> depth;
vector<long long> parent;
vector<bool> visited;
vector<vector<long long>> depth_wise_nodes;
void dfs(long long u, long long p, long long d) {
  depth[u] = d;
  parent[u] = p;
  visited[u] = true;
  depth_wise_nodes[depth[u]].push_back(u);
  for (long long v : adj[u]) {
    if (!visited[v]) {
      dfs(v, u, d + 1);
    }
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    adj.clear(), depth.clear(), visited.clear(), depth_wise_nodes.clear(),
        parent.clear();
    adj.resize(n);
    depth.resize(n);
    parent.assign(n, -1);
    visited.assign(n, false);
    depth_wise_nodes.resize(n);
    for (long long i = 0; i < m; i++) {
      long long a, b;
      cin >> a >> b;
      a--, b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    dfs(0, -1, 0);
    long long min_path_len = n / 2;
    if (n % 2 == 1) min_path_len += 1;
    long long max_depth = 0;
    long long max_depth_node = -1;
    for (long long i = 0; i < n; i++) {
      if (depth[i] > max_depth) {
        max_depth = depth[i];
        max_depth_node = i;
      }
    }
    if (max_depth + 1 >= min_path_len) {
      cout << "PATH"
           << "\n";
      vector<long long> path;
      while (max_depth_node != -1) {
        path.push_back(max_depth_node);
        max_depth_node = parent[max_depth_node];
      }
      cout << path.size() << "\n";
      for (long long n : path) {
        cout << n + 1 << " ";
      }
      cout << "\n";
    } else {
      cout << "PAIRING"
           << "\n";
      vector<array<long long, 2>> res;
      for (long long i = 0; i < max_depth + 1; i++) {
        for (long long j = 0; j + 1 < depth_wise_nodes[i].size(); j += 2) {
          res.push_back({depth_wise_nodes[i][j], depth_wise_nodes[i][j + 1]});
        }
      }
      cout << res.size() << "\n";
      for (array<long long, 2> i : res) {
        cout << i[0] + 1 << " " << i[1] + 1 << "\n";
      }
    }
  }
  return 0;
}
