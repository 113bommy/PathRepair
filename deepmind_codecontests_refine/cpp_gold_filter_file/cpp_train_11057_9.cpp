#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
void sd() {
  int n;
  cin >> n;
  n = 2 * n;
  vector<vector<pair<int, long long>>> adj(n + 1);
  vector<int> cnt(n + 1, 1);
  int i;
  for (i = 0; i < n - 1; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    adj[u].emplace_back(v, t);
    adj[v].emplace_back(u, t);
  }
  vector<int> parent(n + 1, -1), topo(1, 1);
  vector<long long> cost(n + 1, 0);
  parent[1] = 1;
  stack<int> st;
  st.push(1);
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    for (auto [v, c] : adj[u]) {
      if (parent[v] == -1) {
        parent[v] = u;
        cost[v] = c;
        topo.push_back(v);
        st.push(v);
      }
    }
  }
  reverse(topo.begin(), topo.end());
  long long G, B;
  G = B = 0;
  for (int u : topo) {
    cnt[parent[u]] += cnt[u];
    B += cost[u] * min(cnt[u], n - cnt[u]);
    G += cost[u] * (cnt[u] % 2 == 1);
  }
  cout << G << " " << B << endl;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    sd();
  }
}
