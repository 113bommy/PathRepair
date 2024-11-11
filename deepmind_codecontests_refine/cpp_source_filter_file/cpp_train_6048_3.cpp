#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m;
long long d[2][N];
pair<long long, int> val[N];
vector<pair<int, int>> adj[N];
bool mark[N];
void dfs(int u, int p, int id) {
  for (auto& v : adj[u]) {
    if (v.first == p) continue;
    d[id][v.first] = d[id][u] + 1ll * v.second;
    dfs(v.first, u, id);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  dfs(1, 0, 0);
  dfs(n, 0, 1);
  for (int i = 1; i <= n; i++) val[i] = make_pair(d[0][i] - d[1][i], i);
  sort(val + 1, val + n + 1);
  long long mx = 0;
  set<pair<long long, int>> s;
  for (int i = 1; i <= n; i++) {
    int v = val[i].second;
    mark[v] = true;
    for (auto& u : adj[v]) mark[u.first] = true;
    int max_value = -1;
    for (auto& x : s) {
      if (!mark[x.second]) {
        max_value = -x.first;
        break;
      }
    }
    if (max_value != -1) mx = max(mx, max_value + d[1][v]);
    s.insert(make_pair(-d[0][v], v));
    mark[v] = false;
    for (auto& u : adj[v]) mark[u.first] = false;
  }
  while (m--) {
    int len;
    cin >> len;
    cout << min(mx + len, d[0][n]) << '\n';
  }
}
