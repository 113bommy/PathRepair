#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
using namespace std;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 500010, LOG = 20;
int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], deg[MAXN];
int par[MAXN], h[MAXN], parid[MAXN];
long long F[MAXN], ans = 1;
int f[MAXN][2], nex2[MAXN], bad[MAXN];
bool mark[MAXN];
vector<pair<int, int> > G[MAXN];
map<pair<int, int>, int> mp;
map<int, int> nex[MAXN];
set<pair<int, int> > st;
void dfs(int node) {
  h[node] = h[par[node]] + 1;
  for (pair<int, int> p : G[node])
    if (p.first != par[node]) {
      par[p.first] = node;
      parid[p.first] = p.second;
      dfs(p.first);
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  F[0] = 1;
  for (int i = 1; i < MAXN; i++) F[i] = F[i - 1] * i % mod;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    mp[{u, v}] = mp[{v, u}] = i;
    G[u].push_back({v, i});
    G[v].push_back({u, i});
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    if (!A[i]) continue;
    int v = i, u = A[i];
    if (u == v) return cout << 0 << '\n', 0;
    vector<int> v1, v2;
    while (u != v) {
      if (h[u] < h[v]) {
        v1.push_back(v);
        v = par[v];
      } else {
        v2.push_back(u);
        u = par[u];
      }
    }
    v1.push_back(u);
    reverse(v2.begin(), v2.end());
    for (int x : v2) v1.push_back(x);
    for (int i = 1; i < v1.size(); i++) {
      pair<int, int> p = {v1[i - 1], v1[i]};
      if (st.count(p)) return cout << 0 << '\n', 0;
      st.insert(p);
      int id = mp[{v1[i - 1], v1[i]}];
      if (i == 1) f[v1[i - 1]][0] = id;
      if (i == v1.size() - 1) f[v1[i]][1] = id;
      if (1 < i && i < v1.size() - 1) {
        if (f[v1[i]][1] == id) return cout << 0 << '\n', 0;
        if (f[v1[i - 1]][0] == id) return cout << 0 << '\n', 0;
      }
    }
    for (int i = 1; i + 1 < v1.size(); i++) {
      int x = mp[{v1[i - 1], v1[i]}];
      int y = mp[{v1[i + 1], v1[i]}];
      if (nex[v1[i]][x]) return cout << 0 << '\n', 0;
      nex[v1[i]][x] = y;
    }
  }
  for (int i = 1; i <= n; i++) {
    int ted = G[i].size() - (f[i][0] > 0) - (f[i][1] > 0) - nex[i].size();
    for (pair<int, int> p : nex[i]) nex2[p.first] = p.second, bad[p.second] = 1;
    if (f[i][0] && f[i][1]) {
      int v = f[i][0], l = 0;
      while (nex2[v]) v = nex2[v], l++;
      if (v == f[i][1] && l < G[i].size() - 1) return cout << 0 << '\n', 0;
    }
    for (pair<int, int> p : G[i]) {
      int v = p.second;
      if (bad[v]) continue;
      while (1) {
        if (mark[v]) return cout << 0 << '\n', 0;
        mark[v] = 1;
        if (!nex2[v]) break;
        v = nex2[v];
      }
    }
    for (pair<int, int> p : G[i])
      if (!mark[p.second]) return cout << 0 << '\n', 0;
    ans = ans * F[max(ted, 0)] % mod;
    for (pair<int, int> p : G[i])
      nex2[p.second] = mark[p.second] = bad[p.second] = 0;
  }
  cout << ans << "\n";
  return 0;
}
