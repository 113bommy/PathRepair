#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long double PI = acosl(-1);
const long long infl = 6e18 + 10;
const int inf = 1e9 + 10;
const int nmax = 5e5 + 5;
const int MAXLG = log2(nmax) + 1;
vector<int> g[nmax];
int durlif[nmax], par[nmax];
vector<int> liflist[nmax];
int upor[nmax];
bool lifnaki[nmax];
vector<int> d2node[nmax];
int cur[nmax], curofson[nmax];
int depth[nmax];
void dfs(int u, int p = 0) {
  par[u] = p;
  depth[u] = depth[p] + 1;
  for (int v : g[u])
    if (v != p) {
      dfs(v, u);
      durlif[u] = max(durlif[u], durlif[v] + 1);
      liflist[u].push_back(durlif[v] + 1);
    }
  if (g[u].size() == 1) lifnaki[u] = true;
}
void dfs2(int u) {
  if (upor[u] > 0) liflist[u].push_back(upor[u]);
  sort(liflist[u].rbegin(), liflist[u].rend());
  if (g[u].size() == 1 and par[u]) return;
  vector<pair<int, int> > tmp;
  for (int v : g[u])
    if (v != par[u]) {
      tmp.push_back({durlif[v] + 1, v});
    }
  sort(tmp.rbegin(), tmp.rend());
  pair<int, int> boro = tmp[0];
  pair<int, int> boro2 = {-1, 0};
  if (tmp.size() >= 2) boro2 = tmp[1];
  for (int v : g[u])
    if (v != par[u]) {
      if (v == boro.second)
        upor[v] = max(upor[u] + 1, boro2.first + 1);
      else
        upor[v] = max(upor[u] + 1, boro.first + 1);
      dfs2(v);
    }
}
bool cmp(int a, int b) { return depth[a] > depth[b]; }
int ans[nmax];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  dfs2(1);
  for (int u = 1; u <= n; u++) {
    ans[1] = max(ans[1], 1 + (int)g[u].size());
    int idx = 1;
    for (int d : liflist[u]) {
      if (idx > 1) {
        ans[d * 2] = max(ans[d * 2], idx);
        ans[d * 2 - 1] = max(ans[d * 2 - 1], idx);
        if (liflist[u][idx - 2] > d) ans[d * 2 + 1] = max(ans[d * 2 + 1], idx);
      }
      idx++;
      d2node[d].push_back(u);
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(d2node[i].begin(), d2node[i].end(), cmp);
  }
  for (int d = n - 1; d >= 1; d--) {
    for (int u : d2node[d]) {
      cur[u]++;
      if (!lifnaki[u] and d * 2 < n) {
        ans[d * 2] = max(ans[d * 2], curofson[u] - 1 + cur[u] - 1);
      }
      int p = par[u];
      curofson[p] = max(curofson[p], cur[u]);
      if (d * 2 < n) ans[d * 2] = max(ans[d * 2], curofson[p] - 1 + cur[p] - 1);
    }
  }
  for (int i = n - 2; i >= 2; i--) ans[i] = max(ans[i], ans[i + 2]);
  for (int i = n; i >= 1; i--) ans[i] = max(ans[i], 1);
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
