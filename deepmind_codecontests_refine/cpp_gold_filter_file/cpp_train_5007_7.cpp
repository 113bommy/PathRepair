#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e6 + 10;
const long long inf = 1e15;
vector<int> adj[mxn], radj[mxn], ans;
bool taken[mxn], marked[mxn];
void dfs(int u) {
  taken[u] = marked[u] = true;
  for (auto v : adj[u]) marked[v] = true;
}
void ok(int n) {
  for (int i = n; i >= 1; i--) {
    if (taken[i])
      for (auto v : radj[i]) {
        if (taken[v]) taken[i] = false;
      }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    radj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!marked[i]) {
      dfs(i);
    }
  }
  ok(n);
  for (int i = 1; i <= n; i++) {
    if (taken[i]) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (auto v : ans) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}
