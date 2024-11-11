#include <bits/stdc++.h>
using namespace std;
const long long int N = 4e5;
long long int n, m, k;
long long int arrival[N], edge[N], departure[N], c[N];
vector<pair<long long int, long long int> > g[N];
vector<long long int> ans;
void dijkstra() {
  long long int source = 1;
  for (long long int i = 1; i <= n; i++) {
    arrival[i] = 1e16;
    departure[i] = 1e16;
  }
  arrival[source] = 0;
  set<pair<long long int, long long int> > s;
  s.insert({0, source});
  edge[1] = -1;
  while (!s.empty()) {
    if (ans.size() == k) return;
    auto x = *(s.begin());
    s.erase(x);
    departure[x.second] = arrival[x.second];
    if (edge[x.second] != -1) ans.push_back(edge[x.second]);
    for (auto &it : g[x.second]) {
      if (arrival[it.first] > departure[x.second] + c[it.second]) {
        s.erase({arrival[it.first], it.first});
        arrival[it.first] = departure[x.second] + c[it.second];
        edge[it.first] = it.second;
        s.insert({arrival[it.first], it.first});
      }
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k;
  for (long long int i = 1; i <= m; i++) {
    long long int u, v, w;
    cin >> u >> v >> w;
    c[i] = w;
    g[u].push_back(make_pair(v, i));
    g[v].push_back(make_pair(u, i));
  }
  dijkstra();
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (auto &it : ans) cout << it << " ";
  return 0;
}
