#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
static const auto do_fast_io = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
vector<int> chain;
vector<vector<int>> graph;
void dfs_recursion(int s, int p) {
  chain.push_back(s);
  for (auto i : graph[s]) {
    if (i != p) {
      dfs_recursion(i, s);
    }
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> perm = {0, 1, 2};
  vector<vector<int>> c(n + 1, vector<int>(3));
  graph.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> c[i][0];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i][1];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i][2];
  }
  for (int i = 1; i <= n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
    if (graph[x].size() > 2 || graph[y].size() > 2) {
      cout << -1 << endl;
      return 0;
    }
  }
  int root = 0;
  for (int i = 1; i <= n; ++i) {
    if (graph[i].size() == 1) {
      root = i;
    }
  }
  dfs_recursion(root, 0);
  long long min_cost = LONG_LONG_MAX;
  vector<int> best_perm;
  do {
    long long cost = 0;
    for (int i = 0; i < n; ++i) {
      cost += c[chain[i]][perm[i % 3]];
    }
    if (cost < min_cost) {
      min_cost = cost;
      best_perm = perm;
    }
  } while (next_permutation(perm.begin(), perm.end()));
  cout << min_cost << endl;
  vector<int> min_cost_node_colors(n + 1);
  for (int i = 0; i < n; ++i) {
    min_cost_node_colors[chain[i]] = perm[i % 3] + 1;
  }
  for (int i = 1; i <= n; ++i) {
    cout << min_cost_node_colors[i] << " ";
  }
  cout << endl;
  return 0;
}
