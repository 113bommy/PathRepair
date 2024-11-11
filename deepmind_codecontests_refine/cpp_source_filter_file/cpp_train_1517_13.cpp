#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const long double PI = acos(-1);
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
struct edge {
  int u, v;
  long long wt;
};
int n, m;
int vis[N], par[N], sz[N];
long long x[N], dsx[N];
int find(int p) {
  if (par[p] == p)
    return p;
  else {
    int pp = find(par[p]);
    dsx[p] = dsx[p] ^ dsx[par[p]];
    par[p] = pp;
    return pp;
  }
}
bool unite(int u, int v, long long wt) {
  long long du = dsx[u], dv = dsx[v];
  u = find(u), v = find(v);
  if (u == v) return false;
  if (sz[u] > sz[v]) swap(u, v);
  par[u] = v;
  dsx[u] = du ^ dv ^ wt;
  sz[v] += sz[u];
  return true;
}
vector<bitset<60>> num, base;
int gauss_my_friend() {
  int sz = (int)num.size();
  int bs = 0;
  for (int i = 0; i < 60; i++) {
    bool found = false;
    for (int j = bs; j < sz; j++)
      if (num[j][bs]) {
        found = true;
        swap(num[j], num[bs]);
      }
    for (int j = bs + 1; j < sz; j++)
      if (num[j][bs]) {
        num[j] ^= num[bs];
      }
    if (found) base.push_back(num[bs]), bs++;
  }
  return base.size();
}
vector<edge> adj[N];
vector<edge> ed;
void dfs(int u, long long p, int pr) {
  if (vis[u]) return;
  vis[u] = 1;
  x[u] = p;
  for (auto e : adj[u])
    if (e.v != pr) {
      ed.push_back(e);
      dfs(e.v, p ^ e.wt, u);
    }
}
void res(int u) {
  par[u] = u;
  sz[u] = 1;
  dsx[u] = 0;
}
long long solve(vector<edge> ed) {
  vector<int> vtx;
  for (auto e : ed) {
    res(e.u), res(e.v);
    vtx.push_back(e.u);
    vtx.push_back(e.v);
  }
  sort(vtx.begin(), vtx.end());
  long long n = unique(vtx.begin(), vtx.end()) - vtx.begin();
  vtx.resize(n);
  for (auto e : ed) {
    int u = e.u, v = e.v;
    long long wt = e.wt;
    if (!unite(u, v, wt)) {
      num.push_back(wt ^ dsx[u] ^ dsx[v]);
    } else {
    }
  }
  int b = gauss_my_friend();
  long long sum = 0;
  for (int i = 0; i < 60; i++) {
    bool has = false;
    for (auto j : base)
      if (j[i]) has = true;
    long long one = 0, zero = 0;
    for (int j : vtx) {
      if (x[j] & (1ll << i))
        one++;
      else
        zero++;
    }
    if (has) {
      long long term1 = (1ll << i) % MOD;
      long long term2 = (1ll << (b - 1)) % MOD;
      long long term3 = (n * (n - 1)) / 2;
      term1 = (term1 * term2) % MOD;
      term1 = (term1 * term3) % MOD;
      sum = (sum + term1) % MOD;
    } else {
      long long term1 = (1ll << i) % MOD;
      long long term2 = (1ll << b) % MOD;
      term1 = (term1 * term2) % MOD;
      term1 = (term1 * one) % MOD;
      term1 = (term1 * zero) % MOD;
      sum = (sum + term1) % MOD;
    }
  }
  return sum;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    long long t;
    scanf("%d %d %lld", &u, &v, &t);
    edge eu = {u, v, t};
    edge ev = {v, u, t};
    adj[u].push_back(eu);
    adj[v].push_back(ev);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      ed.clear();
      num.clear();
      base.clear();
      dfs(i, 0, 0);
      ans = (ans + solve(ed)) % MOD;
    }
  printf("%lld\n", ans);
  return 0;
}
