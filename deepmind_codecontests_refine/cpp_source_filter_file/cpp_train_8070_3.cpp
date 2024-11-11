#include <bits/stdc++.h>
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
using namespace std;
constexpr int inf = 1e9 + 7, base = 541;
constexpr int mod = 1e9 + 7, N = 1e6 + 7;
vector<pair<int, int> > a[N], b[N];
int n, m;
int xx[] = {0, 0, -1, 1};
int yy[] = {-1, 1, 0, 0};
int o[N], par[N];
vector<int> v[N], yal[N], ans;
void merch(int x, int y) {
  int px = par[x], py = par[y];
  if (px == py) return;
  if ((((int)v[px].size())) + (((int)yal[px].size())) <
      (((int)v[py].size())) + (((int)yal[py].size())))
    swap(px, py);
  for (auto i : v[py]) {
    v[px].push_back(i);
    par[i] = px;
  }
  for (auto i : yal[py]) yal[px].push_back(i);
  yal[py].clear();
  v[py].clear();
}
int vis[N];
bool dfs(int v) {
  vis[v] = true;
  for (int i = 0; i < yal[v].size(); ++i) {
    int to = yal[v][i];
    if (!vis[to]) dfs(to);
  }
  ans.push_back(v);
  return true;
}
int tp[N], an[N];
int32_t main() {
  n = in(), m = in();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = i * m + j;
      o[x] = in();
      a[i].push_back({o[x], x});
      b[j].push_back({o[x], x});
      par[x] = x;
      v[x].push_back(x);
    }
  }
  for (int i = 0; i < n; i++) sort(a[i].begin(), a[i].end());
  for (int j = 0; j < m; j++) sort(b[j].begin(), b[j].end());
  for (int i = 0; i < n; i++)
    for (int j = 1; j < m; j++) {
      if (a[i][j].first == a[i][j - 1].first)
        merch(a[i][j - 1].second, a[i][j].second);
      else
        yal[par[a[i][j].second]].push_back(par[a[i][j - 1].second]);
    }
  for (int i = 0; i < m; i++)
    for (int j = 1; j < n; j++) {
      if (b[i][j].first == b[i][j - 1].first)
        merch(b[i][j - 1].second, b[i][j].second);
      else
        yal[par[b[i][j].second]].push_back(par[b[i][j - 1].second]);
    }
  for (int i = 0; i < n * m; i++)
    if (!vis[par[i]]) dfs(par[i]);
  for (auto i : ans) {
    int mx = 0;
    for (auto j : yal[i]) {
      mx = max(mx, an[par[j]]);
    }
    an[i] = mx + 1;
  }
  for (int i = 0; i < n; i++, cout << '\n')
    for (int j = 0; j < m; j++) cout << an[par[i * m + j]] << ' ';
}
