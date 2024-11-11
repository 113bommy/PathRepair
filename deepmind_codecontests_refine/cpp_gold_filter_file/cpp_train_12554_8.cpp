#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const int maxn = 110000, BUBEN = 300;
vector<int> e[maxn];
int par[maxn], sz[maxn];
vector<int> d[maxn];
vector<long long> ps[maxn];
int down[maxn], dp[maxn], rad[maxn];
int root(int x) {
  if (x == par[x]) return x;
  return par[x] = root(par[x]);
}
void unite(int x, int y) {
  x = root(x);
  y = root(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  sz[x] += sz[y];
  par[y] = x;
}
void dfs0(int v, int p) {
  for (int u : e[v]) {
    if (u == p) continue;
    dfs0(u, v);
    uax(down[v], down[u] + 1);
  }
}
void upd(int *v, int x) {
  for (int i = 0; i < (int)(2); ++i)
    if (x > v[i]) swap(x, v[i]);
}
int exc(int *v, int x) {
  for (int i = 0; i < (int)(2); ++i) {
    if (v[i] == x)
      x = -1;
    else
      return v[i];
  }
  return -1e9;
}
void dfs_up(int v, int p, int dup, vector<int> &res) {
  dp[v] = max(down[v], dup);
  res.push_back(dp[v]);
  int ds[2] = {};
  for (int i = 0; i < (int)(2); ++i) ds[i] = -1e9;
  for (int u : e[v]) {
    if (u == p) continue;
    upd(ds, down[u]);
  }
  for (int u : e[v]) {
    if (u == p) continue;
    dfs_up(u, v, max(dup, exc(ds, down[u]) + 1) + 1, res);
  }
}
map<pair<int, int>, double> memo;
double pair_up(int i, int j) {
  if (sz[i] < sz[j]) swap(i, j);
  int L = max(d[i].back(), d[j].back());
  double ans = 0.0;
  int K = d[i].size();
  for (int k = 0; k < (int)(d[j].size()); ++k) {
    int x = upper_bound((d[i]).begin(), (d[i]).end(), L - d[j][k] - 1) -
            d[i].begin();
    ans += 1.0 * x * L + (ps[i][K] - ps[i][x]) + 1.0 * (K - x) * (d[j][k] + 1);
  }
  ans /= d[i].size();
  ans /= d[j].size();
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < (int)(n); ++i) par[i] = i, sz[i] = 1;
  for (int i = 0; i < (int)(m); ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    e[x].push_back(y);
    e[y].push_back(x);
    unite(x, y);
  }
  for (int i = 0; i < (int)(n); ++i) {
    if (par[i] != i) continue;
    dfs0(i, -1);
    dfs_up(i, -1, 0, d[i]);
    sort((d[i]).begin(), (d[i]).end());
    int K = d[i].size();
    ps[i].resize(K + 1);
    for (int j = 0; j < (int)(K); ++j) ps[i][j + 1] = ps[i][j] + d[i][j];
  }
  for (int i = 0; i < (int)(q); ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    x = root(x);
    y = root(y);
    if (x == y) {
      cout << -1 << '\n';
      continue;
    }
    if (x > y) swap(x, y);
    if (!memo.count(make_pair(x, y))) memo[{x, y}] = pair_up(x, y);
    cout << memo[{x, y}] << '\n';
  }
  return 0;
}
