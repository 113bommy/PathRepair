#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return pair<int, int>(a.first - b.first, a.second - b.second);
}
int cross(pair<int, int> a, pair<int, int> b) {
  ll z = (ll)a.first * b.second - (ll)a.second * b.first;
  return (z > 0) - (z < 0);
}
int clockwise(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return cross(b - a, c - a);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<vector<int> > E(n);
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> sz(n);
  function<void(int, int)> prepare = [&](int u, int p) {
    sz[u] = 1;
    for (auto &v : E[u]) {
      if (v == p) continue;
      prepare(v, u);
      sz[u] += sz[v];
    }
  };
  prepare(0, -1);
  vector<pair<int, int> > b(n);
  for (auto &e : b) cin >> e.first >> e.second;
  vector<int> id(n);
  iota((id).begin(), (id).end(), 0);
  vector<int> ord, perm;
  function<void(int, int, int)> dfs = [&](int u, int p, int curpos) {
    int minpos = min_element(id.begin() + curpos, id.begin() + curpos + sz[u],
                             [&](int x, int y) { return b[x] < b[y]; }) -
                 id.begin();
    if (minpos != curpos) swap(id[minpos], id[curpos]);
    perm.push_back(u);
    ord.push_back(id[curpos]);
    int z = curpos + 1;
    int w = id[curpos];
    sort(id.begin() + curpos + 1, id.begin() + curpos + sz[u],
         [&](int x, int y) { return clockwise(b[w], b[x], b[y]) > 0; });
    for (auto &v : E[u]) {
      if (v == p) continue;
      dfs(v, u, z);
      z += sz[v];
    }
  };
  dfs(0, -1, 0);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[perm[i]] = ord[i];
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " \n"[i == n - 1];
  }
  return 0;
}
