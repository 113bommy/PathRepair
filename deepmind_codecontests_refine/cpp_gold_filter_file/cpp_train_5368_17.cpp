#include <bits/stdc++.h>
#pragma ide diagnostic ignored "UnusedMacroInspection"
using namespace std;
vector<long long> graph[100001];
map<pair<long long, long long>, long long> len;
bool is_flour[100001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, m, k, u, v, l, ans = INT64_MAX;
  cin >> n >> m >> k;
  vector<long long> flour_s(k);
  while (m--) {
    cin >> u >> v >> l;
    graph[u].push_back(v);
    graph[v].push_back(u);
    if (len.count({u, v}))
      len[{u, v}] = min(l, len[{u, v}]);
    else
      len[{u, v}] = l;
    if (len.count({v, u}))
      len[{v, u}] = min(l, len[{v, u}]);
    else
      len[{v, u}] = l;
  }
  if (k == 0) {
    cout << -1 << "\n";
    return 0;
  }
  for (auto &i : is_flour) i = true;
  for (long long i = 0; i < k; i++) {
    cin >> u;
    is_flour[u] = false;
  }
  for (long long i = 1; i <= n; i++) {
    if (is_flour[i]) {
      for (auto j : graph[i]) {
        if (!is_flour[j]) ans = min(ans, len[{i, j}]);
      }
    }
  }
  if (ans == INT64_MAX)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
  return 0;
}
