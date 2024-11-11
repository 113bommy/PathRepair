#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int INF = 1e18;
int n, sub[maxn], q, h[maxn], ans[maxn];
string c[maxn];
vector<int> g[maxn], roots;
vector<pair<int, int> > qu[maxn], vec[maxn];
set<string> cnt[maxn];
map<pair<int, string>, int> cnt2;
void dfs(int v, int p) {
  sub[v] = 1;
  for (auto u : g[v]) {
    if (u != p) {
      h[u] = h[v] + 1;
      dfs(u, v);
      sub[v] += sub[u];
    }
  }
}
void gooni(int v, int p, bool keep) {
  int mx = -1, bigch = -1;
  for (auto u : g[v])
    if (u != p)
      if (sub[u] > mx) mx = sub[u], bigch = u;
  for (auto u : g[v])
    if (u != p && u != bigch) gooni(u, v, 0);
  if (bigch != -1) {
    gooni(bigch, v, 1);
    swap(vec[v], vec[bigch]);
  }
  for (auto u : g[v]) {
    if (u != p && u != bigch) {
      for (auto x : vec[u]) {
        vec[v].push_back(x);
        cnt[x.second].insert(c[x.first]);
        cnt2[make_pair(x.second, c[x.first])]++;
      }
    }
  }
  vec[v].push_back({v, h[v]});
  cnt[h[v]].insert(c[v]);
  cnt2[make_pair(h[v], c[v])]++;
  for (auto qq : qu[v]) {
    int k = qq.first, ind = qq.second;
    ans[ind] = cnt[h[v] + k].size();
  }
  if (keep == 0) {
    for (auto x : vec[v]) {
      cnt2[make_pair(x.second, c[x.first])]--;
      if (cnt2[make_pair(x.second, c[x.first])] == 0)
        cnt[x.second].erase(c[x.first]);
    }
  }
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> c[i] >> v;
    if (v == 0) {
      h[i] = 1;
      roots.push_back(i);
    } else {
      g[v].push_back(i);
      g[i].push_back(v);
    }
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int v, k;
    cin >> v >> k;
    qu[v].push_back({k, i});
  }
  for (auto v : roots) dfs(v, 0);
  for (auto v : roots) gooni(v, 0, 0);
  for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
  return 0;
}
