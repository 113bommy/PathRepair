#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int MAXN = 100010, LOG = 20;
long long tav10[MAXN];
long long inv10[MAXN];
long long mod;
long long calc(vector<long long> &vecin,
               vector<pair<long long, long long> > vecout) {
  map<long long, int> mp;
  for (long long x : vecin) mp[x]++;
  long long res = 0;
  for (pair<long long, long long> p : vecout)
    res += mp[(mod - p.second) * inv10[p.first] % mod];
  return res;
}
long long n, m, k, u, v, x, y, t, a, b, ans;
bool dead[MAXN];
int sz[MAXN], h[MAXN];
long long val_down[MAXN], val_up[MAXN];
vector<int> G[MAXN];
vector<pair<int, int> > G2[MAXN];
int dfs_sz(int node, int par) {
  sz[node] = 1;
  for (int i : G[node])
    if (!dead[i] && i != par) sz[node] += dfs_sz(i, node);
  return sz[node];
}
int centroid(int node, int par, int n) {
  for (int v : G[node])
    if (sz[v] * 2 > n && v != par && !dead[v]) return centroid(v, node, n);
  return node;
}
void dfs_path(int node, int par, vector<long long> &vecin,
              vector<pair<long long, long long> > &vecout) {
  vecin.push_back(val_up[node]);
  vecout.push_back({h[node] = h[par] + 1, val_down[node]});
  for (pair<int, int> p : G2[node])
    if (p.first != par && !dead[p.first]) {
      val_up[p.first] = (tav10[h[node]] * p.second + val_up[node]) % mod;
      val_down[p.first] = (val_down[node] * 10ll + p.second) % mod;
      dfs_path(p.first, node, vecin, vecout);
    }
}
void solve(int node) {
  dfs_sz(node, node);
  int root = centroid(node, node, sz[node]);
  dead[root] = 1;
  h[root] = 0;
  vector<long long> vecin;
  vector<pair<long long, long long> > vecout;
  for (pair<int, int> p : G2[root])
    if (!dead[p.first]) {
      long long v = p.first, w = p.second;
      val_down[v] = val_up[v] = w;
      vector<long long> vecin_tmp;
      vector<pair<long long, long long> > vecout_tmp;
      dfs_path(v, root, vecin_tmp, vecout_tmp);
      ans -= calc(vecin_tmp, vecout_tmp);
      for (long long tmp : vecin_tmp) vecin.push_back(tmp);
      for (pair<long long, long long> tmp : vecout_tmp) vecout.push_back(tmp);
    }
  vecin.push_back(0);
  vecout.push_back({0, 0});
  ans += calc(vecin, vecout) - 1;
  for (int v : G[root])
    if (!dead[v]) solve(v);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> mod;
  tav10[0] = inv10[0] = 1;
  for (int i = 1; i < MAXN; i++) tav10[i] = tav10[i - 1] * 10 % mod;
  for (long long i = 1; i < 11; i++)
    if ((i * mod + 1) % 10 == 0) inv10[1] = (i * mod + 1) / 10;
  for (int i = 2; i < MAXN; i++) inv10[i] = inv10[1] * inv10[i - 1] % mod;
  for (int i = 1; i < n; i++) {
    cin >> u >> v >> x;
    x %= mod;
    u++;
    v++;
    G[u].push_back(v);
    G[v].push_back(u);
    G2[u].push_back({v, x});
    G2[v].push_back({u, x});
  }
  solve(1);
  cout << ans << '\n';
  return 0;
}
