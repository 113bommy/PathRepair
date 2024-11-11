#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
vector<pair<int, int>> g[N];
vector<int> deg, ans;
vector<pair<int, int>> edge;
set<pair<int, int>> good;
vector<bool> in_good;
void f(int k, int iteration) {
  while (!good.empty() && good.begin()->first < k) {
    int v = good.begin()->second;
    for (auto j : g[v]) {
      int i = j.first;
      int it = j.second;
      if (iteration <= it) continue;
      if (in_good[i]) {
        good.erase({deg[i], i});
        deg[i]--;
        good.insert({deg[i], i});
      }
    }
    good.erase({deg[v], v});
    in_good[v] = false;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  deg.resize(n, 0);
  edge.resize(m);
  in_good.resize(n, true);
  ans.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[i] = {a, b};
    deg[a]++;
    deg[b]++;
    g[a].push_back({b, i});
    g[b].push_back({a, i});
  }
  for (int i = 0; i < n; i++) {
    good.insert({deg[i], i});
  }
  f(k, m);
  for (int i = m - 1; i >= 0; i--) {
    ans[i] = good.size();
    if (i == 0) break;
    int v = edge[i].first;
    int u = edge[i].second;
    if (!in_good[v] || !in_good[u]) continue;
    good.erase({deg[v], v});
    deg[v]--;
    good.insert({deg[v], v});
    good.erase({deg[u], u});
    deg[u]--;
    good.insert({deg[u], u});
    f(k, i);
  }
  for (int i = 0; i < m; i++) cout << ans[i] << endl;
  return 0;
}
