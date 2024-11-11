#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
int dep[MAX], ans[MAX];
vector<vector<int> > adj(MAX);
int n, k;
int dfs(int node, int par) {
  vector<int> v;
  if (adj[node].size() == 1) v.push_back(dep[node]);
  for (auto &child : adj[node]) {
    if (child == par) continue;
    dep[child] = dep[node] + 1;
    v.push_back(dfs(child, node));
    ans[node] += ans[child] - 1;
  }
  sort(v.begin(), v.end());
  ans[node]++;
  for (int i = (int)(v.size()) - 2; i >= 0; --i) {
    if (v[i] + v[i + 1] - 2 * dep[node] <= k) return v[i + 1];
    ans[node]++;
  }
  return v[0];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1);
  cout << ans[1] << "\n";
  return 0;
}
