#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<pair<int, int>>> hor(n), ver(m);
  for (int i = 0; i < q; i++) {
    int first, second;
    cin >> first >> second;
    first--, second--;
    hor[first].push_back({first, second});
    ver[second].push_back({first, second});
  }
  int res = 0;
  int cntn = 0, cntm = 0;
  for (int i = 0; i < m; i++) {
    if (ver[i].empty()) cntm++;
  }
  res = cntn + cntm;
  vector<int> p(m), sz(m, 1);
  for (int i = 0; i < m; i++) p[i] = i;
  auto get = [&](int v) {
    while (p[v] != v) v = p[v];
    return p[v];
  };
  auto unite = [&](int v, int u) {
    v = get(v), u = get(u);
    if (sz[v] > sz[u]) swap(v, u);
    if (u != v) sz[u] += sz[v];
    p[v] = u;
  };
  for (int i = 0; i < n; i++) {
    if (hor[i].empty()) continue;
    int k = hor[i][0].second;
    for (pair<int, int> j : hor[i]) {
      unite(j.second, k);
    }
  }
  res--;
  set<int> have;
  for (int i = 0; i < n; i++) have.insert(get(i));
  res += have.size();
  cout << res;
  return 0;
}
