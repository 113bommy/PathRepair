#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 12, lg = 20, MOD = 998244353;
long long n, k;
long long dp1[N], dp2[N];
long long par[N][lg], h[N];
long long col[N], NX[N];
vector<long long> ad[N], vec[N], g[N];
long long mul(long long, long long);
long long sum(long long, long long);
long long POW(long long, long long);
void init();
void dfs_1(long long, long long);
long long LCA(long long, long long);
void solve_1();
void solve_2();
void dfs_2(long long, long long);
long long inv(long long);
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  dfs_1(0, -1);
  solve_1();
  solve_2();
  dfs_2(1, -1);
  cout << dp2[1];
  return 0;
}
void dfs_2(long long root, long long P) {
  for (long long i : g[root])
    if (i != P) dfs_2(i, root);
  if (root <= k) {
    dp1[root] = 0;
    dp2[root] = 1;
    for (long long i : g[root]) {
      if (i != P) dp2[root] = mul(dp2[root], sum(dp1[i], dp2[i]));
    }
    return;
  }
  long long val = 1;
  for (long long i : g[root])
    if (i != P) val = mul(val, sum(dp1[i], dp2[i]));
  dp1[root] = val;
  for (long long i : g[root])
    if (i != P) {
      dp2[root] =
          sum(dp2[root], mul(mul(val, inv(sum(dp1[i], dp2[i]))), dp2[i]));
    }
  return;
}
void solve_2() {
  long long CHANGE = k + 1;
  for (long long i = 0; i < n; i++) {
    NX[i] = col[i];
    if (NX[i] == 0) {
      NX[i] = CHANGE;
      CHANGE++;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j : ad[i]) {
      if (NX[i] == NX[j]) continue;
      g[NX[i]].push_back(NX[j]);
      g[NX[j]].push_back(NX[i]);
    }
  }
  for (long long i = 1; i < CHANGE; i++) {
    sort(g[i].begin(), g[i].end());
    g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
  }
  return;
}
void solve_1() {
  for (long long i = 1; i <= k; i++) {
    long long L = vec[i][0];
    for (long long j = 1; j < vec[i].size(); j++) L = LCA(L, vec[i][j]);
    for (long long j = 0; j < vec[i].size(); j++) {
      long long v = vec[i][j];
      while (v != L) {
        v = par[v][0];
        if (col[v] && col[v] != i) {
          cout << 0;
          exit(0);
        }
        if (col[v]) break;
        col[v] = i;
      }
    }
  }
  return;
}
long long LCA(long long a, long long b) {
  if (h[a] > h[b]) swap(a, b);
  for (long long i = 0; i < lg; i++)
    if ((h[b] - h[a]) & (1 << i)) b = par[b][i];
  if (a == b) return a;
  for (long long i = lg - 1; i >= 0; i--)
    if (par[a][i] != par[b][i]) {
      a = par[a][i];
      b = par[b][i];
    }
  return par[a][0];
}
void dfs_1(long long root, long long P) {
  par[root][0] = P;
  for (long long i = 1; i < lg; i++)
    if (par[root][i - 1] == -1)
      par[root][i] = -1;
    else
      par[root][i] = par[par[root][i - 1]][i - 1];
  for (long long i : ad[root])
    if (i != P) {
      h[i] = h[root] + 1;
      dfs_1(i, root);
    }
  return;
}
void init() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> col[i];
    if (col[i]) vec[col[i]].push_back(i);
  }
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    u--, v--;
    ad[u].push_back(v);
    ad[v].push_back(u);
  }
  return;
}
long long mul(long long a, long long b) { return (a * b) % MOD; }
long long sum(long long a, long long b) {
  a += b;
  while (a < 0) a += MOD;
  while (a >= MOD) a -= MOD;
  return a;
}
long long POW(long long a, long long p) {
  if (p == 0) return 1;
  long long b = POW(a, p / 2);
  b = mul(b, b);
  if (p % 2) b = mul(b, a);
  return b;
}
long long inv(long long a) { return POW(a, MOD - 2); }
