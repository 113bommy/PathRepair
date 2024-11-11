#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int MAX = 1e3 + 5;
const long long MAX2 = 11;
const int MOD = 1000000000 + 7;
const long long INF = 20000;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
const double pi = acos(-1);
const double EPS = 1e-9;
int n, m, a, b, p[MAX], res, tmp, vis[MAX], cen[MAX], cnt[MAX], ct, st;
vector<pair<int, int> > ans;
vector<int> v[MAX], u[MAX];
int par(int z) { return p[z] = (p[z] == z) ? z : par(p[z]); }
void clr(int nw) {
  vis[nw] = 0;
  for (auto i : v[nw])
    if (vis[i]) clr(i);
  return;
}
void dfs(int nw) {
  if (vis[nw] > ct) ct = vis[nw], st = nw;
  for (auto i : v[nw]) {
    if (vis[i]) continue;
    vis[i] = 1 + vis[nw];
    dfs(i);
  }
  for (auto i : u[nw]) {
    if (vis[i]) continue;
    vis[i] = 1 + vis[nw];
    dfs(i);
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cnt[i] = 1e9, p[i] = i;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
    p[par(a)] = par(b);
  }
  for (int i = 1; i <= n; i++) {
    clr(i);
    ct = 0;
    vis[i] = 1;
    dfs(i);
    if (cnt[par(i)] > ct) cnt[par(i)] = ct, cen[par(i)] = i;
  }
  res = 1e9;
  for (int i = 1; i <= n; i++) {
    if (cen[i]) {
      for (int j = 1; j <= n; j++) u[j].clear();
      for (int j = 1; j <= n; j++)
        if (cen[j] && i != j)
          u[cen[i]].push_back(cen[j]), u[cen[j]].push_back(cen[i]);
      memset(vis, 0, sizeof vis);
      ct = 0;
      vis[cen[i]] = 1;
      dfs(cen[i]);
      memset(vis, 0, sizeof vis);
      ct = 0;
      vis[st] = 1;
      dfs(st);
      ct--;
      if (ct < res) {
        res = ct;
        ans.clear();
        for (auto j : u[cen[i]]) ans.push_back({cen[i], j});
      }
    }
  }
  cout << res << "\n";
  for (auto i : ans) cout << i.first << ' ' << i.second << "\n";
  return 0;
}
