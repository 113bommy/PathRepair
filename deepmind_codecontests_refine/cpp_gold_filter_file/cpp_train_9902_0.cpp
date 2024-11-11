#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<vector<int> > g(n);
  vector<int> degree(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }
  queue<int> bfs;
  for (int i = 0; i < n; i++) {
    if (degree[i] == 1) bfs.push(i);
  }
  vector<int> depth(n);
  vector<int> curdegree = degree;
  vector<bool> vis(n);
  while (!bfs.empty()) {
    int u = bfs.front();
    bfs.pop();
    degree[u] = 0;
    vis[u] = true;
    for (auto &v : g[u]) {
      if (vis[v]) continue;
      depth[v] = depth[u] + 1;
      degree[v]--;
      if (degree[v] == 1) {
        bfs.push(v);
      }
    }
  }
  map<int, vector<int> > depths;
  for (int i = 0; i < n; i++) {
    depths[depth[i]].push_back(i);
    if (depth[i] > k) {
      cout << "NO" << endl;
      return 0;
    } else if (depth[i] == k) {
      if (curdegree[i] < 3) {
        cout << "NO" << endl;
        return 0;
      }
    } else if (depth[i] > 0 and curdegree[i] < 4) {
      cout << "NO" << endl;
      return 0;
    }
    for (auto &v : g[i]) {
      if (abs(depth[i] - depth[v]) != 1) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  for (int i = 0; i <= k; i++) {
    if (depths[i].size() == 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
