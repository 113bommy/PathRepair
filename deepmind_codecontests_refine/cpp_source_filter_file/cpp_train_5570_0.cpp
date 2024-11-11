#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
int n, m, a[N], vis[N] = {0}, ans = 0;
vector<int> adj[N];
int dfs(int parent, int cat) {
  vis[parent] = 1;
  for (auto child : adj[parent]) {
    if (a[child] == 1 and !vis[child]) {
      a[child] += a[parent];
      if (a[child] > m) {
        continue;
      }
    }
    if (adj[child].size() == 1 and child != 1) {
      ans++;
      continue;
    }
    if (!vis[child]) dfs(child, a[child]);
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cout << dfs(1, a[1]) << endl;
  ;
}
