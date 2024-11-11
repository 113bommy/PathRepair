#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> dv;
vector<vector<pair<int, int>>> g;
bitset<100004> vis;
int k;
pair<int, int> dfs(int x) {
  vis[x] = 1;
  vector<pair<int, int>> v;
  pair<int, int> p;
  for (auto& u : g[x])
    if (!vis[u.first]) {
      p = dfs(u.first);
      v.emplace_back(u.second + p.first, u.second + p.second);
    }
  sort(v.begin(), v.end(), greater<pair<int, int>>());
  int i, r1 = 0, len = v.size(), r2 = 0;
  if (len > k - 1) {
    for (i = 0; i < k - 1; ++i) r1 += v[i].first;
    for (i = 0; i < k - 1; ++i)
      r2 = max(r2, v[i].second + r1 - v[i].first + v[k - 1].second);
    for (; i < len; ++i) r2 = max(r2, v[i].second + r1);
    return {r1, r2};
  } else {
    for (i = 0; i < len; ++i) r1 += v[i].first;
    for (i = 0; i < len; ++i) r2 = max(r2, v[i].second + r1 - v[i].first);
    return {r1, r2};
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, x, y, c, i;
  cin >> n >> k;
  g.assign(n, dv);
  for (i = 1; i < n; ++i) {
    cin >> x >> y >> c;
    g[x].emplace_back(y, c);
    g[y].emplace_back(x, c);
  }
  cout << dfs(0).second << '\n';
  return 0;
}
