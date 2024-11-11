#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O3")
using namespace std;
const int N = 2e5 + 500;
int n, ans;
int c[N], f[N], pw[N];
vector<int> g[N];
bool mrk[N];
void dfs(int v, int pr, int col) {
  bool isleaf = 1;
  for (auto u : g[v]) {
    if (u == pr) continue;
    dfs(u, v, col);
    f[v] = max(f[u], f[v]);
    isleaf = 0;
  }
  if (isleaf)
    f[v] = (c[v] == col || c[v] == 0) ? 0 : 1;
  else
    f[v]++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[v].push_back(u);
      g[u].push_back(v);
    }
    if (n == 1) {
      cout << "1" << '\n';
      continue;
    }
    for (int nc = 1; nc <= 2; nc++) {
      int cur = 0;
      set<pair<int, int> > se[3];
      for (int i = 1; i <= n; i++) {
        pw[i] = (int)g[i].size();
        se[c[i]].insert({pw[i], i});
        mrk[i] = 0;
      }
      int c_now = nc;
      int cnt_v = 0;
      while (cnt_v < n) {
        int cnt = 0;
        if ((int)se[0].size()) {
          if ((*se[0].begin()).first <= 1) {
            int v = (*se[0].begin()).second;
            mrk[v] = 1;
            se[0].erase(se[0].begin());
            cnt_v++;
            for (auto u : g[v]) {
              if (mrk[u]) continue;
              se[c[u]].erase({pw[u], u});
              pw[u]--;
              se[c[u]].insert({pw[u], u});
            }
          } else
            cnt++;
        } else
          cnt++;
        if ((int)se[c_now].size()) {
          if ((*se[c_now].begin()).first <= 1) {
            int v = (*se[c_now].begin()).second;
            mrk[v] = 1;
            cnt_v++;
            se[c_now].erase(se[c_now].begin());
            for (auto u : g[v]) {
              if (mrk[u]) continue;
              se[c[u]].erase({pw[u], u});
              pw[u]--;
              se[c[u]].insert({pw[u], u});
            }
          } else
            cnt++;
        } else
          cnt++;
        if (cnt == 2) c_now = (c_now % 2) + 1, cur++;
      }
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
}
