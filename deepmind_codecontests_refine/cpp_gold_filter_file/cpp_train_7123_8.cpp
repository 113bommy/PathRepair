#include <bits/stdc++.h>
using namespace std;
const int N = 50 * 1001, SQRT = 321;
int n, m, q, o, id[N], res[N], deg[N];
bool mark[N], is_friend[N][5 * SQRT];
set<int> adj[N];
vector<int> big;
vector<pair<char, pair<int, int>>> query;
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q >> o;
  while (o--) {
    int u;
    cin >> u;
    u--;
    mark[u] = true;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].insert(v);
    adj[v].insert(u);
    deg[u]++, deg[v]++;
  }
  for (int i = 0; i < q; i++) {
    char c;
    cin >> c;
    if (c == 'O') {
      int u;
      cin >> u;
      u--;
      query.push_back({c, {u, -1}});
    } else if (c == 'F') {
      int u;
      cin >> u;
      u--;
      query.push_back({c, {u, -1}});
    } else if (c == 'A') {
      int u, v;
      cin >> u >> v;
      u--, v--;
      deg[u]++, deg[v]++;
      query.push_back({c, {u, v}});
    } else if (c == 'D') {
      int u, v;
      cin >> u >> v;
      u--, v--;
      query.push_back({c, {u, v}});
    } else {
      int u;
      cin >> u;
      u--;
      query.push_back({c, {u, -1}});
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (deg[i] > SQRT) {
      big.push_back(i);
      id[i] = cnt++;
      for (auto v : adj[i]) is_friend[v][id[i]] = true;
    }
    for (auto v : adj[i])
      if (deg[v] <= SQRT) res[i] += mark[v];
  }
  for (auto q : query) {
    char c = q.first;
    int u = q.second.first, v = q.second.second;
    if (c == 'O') {
      mark[u] = true;
      if (deg[u] <= SQRT)
        for (auto v : adj[u]) res[v]++;
    } else if (c == 'F') {
      mark[u] = false;
      if (deg[u] <= SQRT)
        for (auto v : adj[u]) res[v]--;
    } else if (c == 'D') {
      if (deg[u] <= SQRT)
        res[v] -= mark[u];
      else
        is_friend[v][id[u]] = false;
      if (deg[v] <= SQRT)
        res[u] -= mark[v];
      else
        is_friend[u][id[v]] = false;
      adj[u].erase(v);
      adj[v].erase(u);
    } else if (c == 'A') {
      if (deg[u] <= SQRT)
        res[v] += mark[u];
      else
        is_friend[v][id[u]] = true;
      if (deg[v] <= SQRT)
        res[u] += mark[v];
      else
        is_friend[u][id[v]] = true;
      adj[u].insert(v);
      adj[v].insert(u);
    } else {
      int ans = res[u];
      for (int i = 0; i < cnt; i++)
        if (mark[big[i]] && is_friend[u][i]) ans++;
      cout << ans << "\n";
    }
  }
}
