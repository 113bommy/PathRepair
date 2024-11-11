#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)2e5 + 5;
vector<pair<int, int>> g[MAXN];
vector<int> from[MAXN];
int dist[MAXN];
int n, m, k;
int ost;
bool ans[MAXN];
void build(int pos) {
  if (pos == n + 1) {
    for (int i = 1; i <= m; i++) {
      cout << ans[i];
    }
    cout << endl;
    ost--;
    if (!ost) {
      exit(0);
    }
    return;
  } else {
    for (int el : from[pos]) {
      ans[el] = 1;
      build(pos + 1);
      ans[el] = 0;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  queue<int> q;
  vector<bool> used(n + 1, false);
  q.push(1);
  dist[1] = 0;
  used[1] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto to : g[v]) {
      if (!used[to.first]) {
        q.push(to.first);
        used[to.first] = 1;
        dist[to.first] = dist[v] + 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto to : g[i]) {
      if (dist[i] + 1 == dist[to.first]) {
        from[to.first].push_back(to.second);
      }
    }
  }
  from[1].push_back(0);
  long long mult = 1;
  bool ok = false;
  for (int i = 1; i <= n; i++) {
    mult *= (int)from[i].size();
    if (mult >= k) {
      ok = true;
      break;
    }
  }
  if (ok) {
    cout << k << endl;
    ost = k;
  } else {
    cout << mult << endl;
    ost = mult;
  }
  build(1);
}
