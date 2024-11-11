#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;
const int nax = (int)1e5 + 5;
int n, m, k;
vector<int> adj[nax], pos(nax, -1), order, cycle;
vector<vector<int> > bipartite(2);
bool dfs(int u, int color) {
  pos[u] = order.size();
  bipartite[color].push_back(u);
  order.push_back(u);
  int lowest_ancestor = MOD;
  for (int v : adj[u]) {
    if (pos[v] != -1 && pos[u] - pos[v] > 1) {
      lowest_ancestor = min(lowest_ancestor, pos[v]);
    }
  }
  if (lowest_ancestor != MOD) {
    for (ll i = lowest_ancestor; i < pos[u] + 1; i++) {
      cycle.push_back(order[i]);
    }
    return true;
  }
  for (int v : adj[u]) {
    if (pos[v] == -1) {
      if (dfs(v, 1 - color)) return true;
    }
  }
  order.pop_back();
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  int u, v;
  for (ll i = 0; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0);
  if (cycle.empty()) {
    if (bipartite[0].size() < bipartite[1].size())
      swap(bipartite[0], bipartite[1]);
    cout << "1\n";
    for (ll i = 0; i < (k + 1) / 2; i++) {
      cout << 1 + bipartite[0][i] << ' ';
    }
  } else if ((int)cycle.size() <= k) {
    cout << "2\n";
    cout << cycle.size() << '\n';
    for (ll i = 0; i < (ll)cycle.size(); i++) {
      cout << 1 + cycle[i] << ' ';
    }
  } else {
    cout << "1\n";
    for (ll i = 0; i < (k + 1) / 2; i++) {
      cout << 1 + cycle[2 * i] << ' ';
    }
  }
  cout << '\n';
  return 0;
}
