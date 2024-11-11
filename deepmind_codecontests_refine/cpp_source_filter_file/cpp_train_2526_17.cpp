#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
vector<vector<int> > adj(N);
int n, a, b, da, db, diam, dist[N];
int dfs(int u, int p) {
  int len = 0;
  for (auto v : adj[u]) {
    if (v != p) {
      dist[v] = dist[u] + 1;
      int cur = 1 + dfs(v, u);
      diam = max(diam, len + cur);
      len = max(len, cur);
    }
  }
  return len;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> a >> b >> da >> db;
    for (int i = 0; i < N; i++) adj[i].clear();
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(dist, -1, sizeof(dist));
    diam == 0;
    dist[a] = 0;
    dfs(a, -1);
    if (dist[b] <= da || 2 * da >= diam) {
      cout << "Alice\n";
    } else if (db > 2 * da) {
      cout << "Bob\n";
    } else
      cout << "Alice\n";
  }
  return 0;
}
