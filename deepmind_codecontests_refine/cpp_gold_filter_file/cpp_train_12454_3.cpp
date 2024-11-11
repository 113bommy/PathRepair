#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, long long> > > g;
vector<vector<long long> > subtree;
vector<vector<long long> > cum;
int n, m;
void dfs(int u) {
  subtree[u].push_back(0);
  cum[u].push_back(0);
  if (g[u].size() == 0) {
    return;
  }
  for (auto v : g[u]) {
    dfs(v.first);
  }
  if (g[u].size() == 1) {
    for (auto a : subtree[g[u][0].first])
      subtree[u].push_back(a + g[u][0].second);
    for (int i = 1; i < subtree[u].size(); i++) {
      cum[u].push_back(cum[u].back() + subtree[u][i]);
    }
    assert(subtree[u].size() == cum[u].size());
    return;
  }
  int a = g[u][0].first, b = g[u][1].first;
  long long c1 = g[u][0].second, c2 = g[u][1].second;
  int i = 0, j = 0;
  while (i != subtree[a].size() && j != subtree[b].size()) {
    long long d1 = c1 + subtree[a][i];
    long long d2 = c2 + subtree[b][j];
    if (d1 < d2) {
      i++;
      subtree[u].push_back(d1);
    } else {
      j++;
      subtree[u].push_back(d2);
    }
  }
  while (i != subtree[a].size()) {
    long long d1 = c1 + subtree[a][i];
    i++;
    subtree[u].push_back(d1);
  }
  while (j != subtree[b].size()) {
    long long d2 = c2 + subtree[b][j];
    j++;
    subtree[u].push_back(d2);
  }
  for (int i = 1; i < subtree[u].size(); i++) {
    assert(subtree[u][i] >= subtree[u][i - 1]);
    cum[u].push_back(cum[u].back() + subtree[u][i]);
  }
  assert(subtree[u].size() == cum[u].size());
}
long long P[5000000];
int main() {
  cin >> n >> m;
  g.resize(n + 1);
  subtree.resize(n + 1);
  cum.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int l = rand() % 1000 + 1;
    scanf("%d", &l);
    g[(i + 1) / 2].push_back({i + 1, l});
    P[i + 1] = l;
  }
  dfs(1);
  while (m--) {
    int u;
    long long h;
    scanf("%d %I64d", &u, &h);
    long long ans = 0;
    int p = upper_bound(subtree[u].begin(), subtree[u].end(), h) -
            subtree[u].begin();
    ans += 1ll * (h * p) - cum[u][p - 1];
    if (h == 0) {
      cout << 0 << endl;
      continue;
    }
    long long distAssending = 0;
    while (u != 1) {
      distAssending += P[u];
      if (distAssending >= h) break;
      ans += h - distAssending;
      int v;
      if (u & 1) {
        v = u - 1;
      } else
        v = u + 1;
      if (v > n) {
        u /= 2;
        continue;
      }
      long long totatDist = distAssending + P[v];
      if (totatDist > h) {
        u = u / 2;
        continue;
      }
      int p = upper_bound(subtree[v].begin(), subtree[v].end(), h - totatDist) -
              subtree[v].begin();
      ans += ((h - totatDist) * p) - cum[v][p - 1];
      u = u / 2;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
