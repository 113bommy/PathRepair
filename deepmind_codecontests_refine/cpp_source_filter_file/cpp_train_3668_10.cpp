#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, a[maxn], cost[maxn], ans[maxn];
vector<int> adj[maxn];
void readf() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = (a[i] > 0) ? a[i] : -1;
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
}
void DFS(int u, int pu) {
  cost[u] = a[u];
  for (auto v : adj[u])
    if (pu != v) DFS(v, u);
  for (auto v : adj[u])
    if (pu != v && cost[v] > 0) cost[u] += cost[v];
}
void ANS(int u, int pu, int val) {
  ans[u] = max(0, val) + cost[u];
  for (auto v : adj[u])
    if (pu != v) ANS(v, u, val + cost[u] - (cost[v] > 0) * cost[v]);
}
void solve() {
  DFS(1, 0);
  ANS(1, 0, 0);
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}
int main() {
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  readf();
  solve();
}
