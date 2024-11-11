#include <bits/stdc++.h>
using namespace std;
vector<int> leaves;
vector<int> g[250001];
int parent[250001];
int depth[250001];
void dfs(int node, int par, int dep) {
  parent[node] = par;
  depth[node] = dep;
  bool b = 1;
  for (int i = 0; i < g[node].size(); i++) {
    if (parent[g[node][i]] == 0) {
      dfs(g[node][i], node, dep + 1);
      b = 0;
    }
  }
  if (b && (node != 1)) {
    leaves.push_back(node);
  }
  return;
}
void solve() {
  leaves.resize(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(parent, 0, sizeof(parent));
  dfs(1, -1, 0);
  int goal = n / k + (n % k != 0);
  for (int i = 1; i <= n; i++) {
    if (depth[i] + 1 >= goal) {
      cout << "PATH\n";
      cout << goal << "\n";
      int index = i;
      while (index != -1) {
        cout << index << " ";
        index = parent[index];
      }
      return;
    }
  }
  cout << "CYCLES\n";
  for (int i = 0; i < k; i++) {
    int leaf = leaves[i];
    int u = 0, v = 0;
    for (int j = 0; j < 3; j++) {
      if (g[leaf][j] != parent[leaf]) {
        if (u == 0) {
          u = g[leaf][j];
        } else {
          v = g[leaf][j];
        }
      }
    }
    if (depth[u] > depth[v]) {
      int temp = u;
      u = v;
      v = temp;
    }
    if ((-depth[u] + depth[leaf] + 1) % 3 != 0) {
      cout << depth[leaf] - depth[u] + 1 << "\n";
      int index = leaf;
      while (index != u) {
        cout << index << " ";
        index = parent[index];
      }
      cout << u << "\n";
      continue;
    }
    if ((-depth[v] + depth[leaf] + 1) % 3 != 0) {
      cout << depth[leaf] - depth[v] + 1 << "\n";
      int index = leaf;
      while (index != v) {
        cout << index << " ";
        index = parent[index];
      }
      cout << v << "\n";
      continue;
    }
    if ((depth[v] - depth[u] + 2) % 3 != 0) {
      cout << depth[v] - depth[u] + 2 << "\n";
      cout << leaf << " ";
      int index = v;
      while (index != u) {
        cout << index << " ";
        index = parent[index];
      }
      cout << u << "\n";
      continue;
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
