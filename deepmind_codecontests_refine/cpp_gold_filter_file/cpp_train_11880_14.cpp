#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> g[], int n, int at, vector<int>& res, vector<bool>& vis) {
  vis[at] = 1;
  res.push_back(at);
  if (at == n) {
    for (int x : res) {
      cout << x << " ";
    }
    return;
  }
  for (auto i = g[at].begin(); i != g[at].end(); i++) {
    if (!vis[*i]) {
      dfs(g, n, *i, res, vis);
    }
    res.erase(res.end() - 1, res.end());
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> g[n];
  vector<bool> vis(2000000);
  vector<int> res;
  fill(vis.begin(), vis.end(), 0);
  for (int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    g[u].push_back(i);
  }
  dfs(g, n, 1, res, vis);
}
