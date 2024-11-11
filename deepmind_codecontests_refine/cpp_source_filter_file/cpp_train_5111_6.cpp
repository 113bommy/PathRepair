#include <bits/stdc++.h>
using namespace std;
int n, m, sz[1000001], h[1000001], cnt[1000001], ans[1000001];
vector<int> a[1000001], vec[1000001];
vector<pair<int, int>> query[1000001];
set<pair<int, int>> s;
void get_sz(int u, int p) {
  sz[u] = 1;
  for (auto v : a[u])
    if (v != p) {
      h[v] = h[u] + 1;
      get_sz(v, u);
      sz[u] += sz[v];
    }
}
void update(int u) {
  s.erase({-cnt[h[u]], h[u]});
  cnt[h[u]]++;
  s.insert({-cnt[h[u]], h[u]});
}
void dfs(int u, int p, bool keep) {
  int big_sz = -1, big_child = -1;
  for (auto v : a[u])
    if (v != p && big_sz < sz[v]) {
      big_sz = sz[v];
      big_child = v;
    }
  for (auto v : a[u])
    if (v != p && v != big_child) dfs(v, u, false);
  if (big_child != -1) {
    dfs(big_child, u, true);
    swap(vec[u], vec[big_child]);
  }
  vec[u].push_back(u);
  update(u);
  for (auto v : a[u])
    if (v != p && v != big_child)
      for (auto x : vec[v]) {
        vec[u].push_back(x);
        update(x);
      }
  ans[u] = s.begin()->second - h[u];
  if (!keep) {
    for (auto v : vec[u]) cnt[v] = 0;
    s.clear();
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
  memset(cnt, 0, sizeof(cnt));
  h[1] = 0;
  get_sz(1, 0);
  dfs(1, 0, true);
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}
