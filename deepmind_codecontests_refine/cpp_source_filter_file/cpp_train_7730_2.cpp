#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 3e5 + 5;
const int INF = 1e9;
pair<int, int> e[MAXN << 1];
vector<int> g[MAXN];
int tin[MAXN], fup[MAXN], br[MAXN];
vector<int> bb;
int tmr = 1;
void dfs_br(int v, int p = -1) {
  tin[v] = fup[v] = tmr++;
  for (int j : g[v]) {
    int i = e[j].second;
    if (i == p) continue;
    if (tin[i]) {
      fup[v] = min(fup[v], tin[i]);
      continue;
    }
    dfs_br(i, v);
    fup[v] = min(fup[v], fup[i]);
    if (fup[i] > tin[v]) {
      br[j] = 1, br[j ^ 1] = 1;
      bb.emplace_back(min(j, j ^ 1));
    }
  }
}
int col[MAXN];
void dfs_col(int v) {
  for (int j : g[v]) {
    if (br[j]) continue;
    int i = e[j].second;
    if (col[i]) continue;
    col[i] = col[v];
    dfs_col(i);
  }
}
vector<int> gn[MAXN];
long long c_sum[MAXN];
int v_sum[MAXN];
long long dp[MAXN];
int k;
void dfs_dp(int v, int p = -1) {
  dp[v] = c_sum[v];
  for (int j : gn[v]) {
    int i = col[e[j].second];
    if (i == p) continue;
    dfs_dp(i, v);
    long long add = 0;
    if (v_sum[i] == k || v_sum[i] == 0) add = dp[i];
    v_sum[v] += v_sum[i];
    add = max(add, dp[i] - e[j].first);
    dp[v] += add;
  }
}
long long ans_dp[MAXN];
void recalc(int v, int p, long long w) {
  long long add = 0;
  if (v_sum[p] == k || v_sum[p] == 0) add = dp[p];
  add = max(add, dp[p] - w);
  dp[v] -= add;
  v_sum[v] -= v_sum[p];
  v_sum[p] += v_sum[v];
  add = 0;
  if (v_sum[v] == k || v_sum[v] == 0) add = dp[v];
  add = max(add, dp[v] - w);
  dp[p] += add;
}
void dfs_ans(int v, int p, long long w) {
  ans_dp[v] = dp[v];
  for (int j : gn[v]) {
    int i = col[e[j].second];
    if (i == p) continue;
    recalc(v, i, e[j].first);
    dfs_ans(i, v, e[j].first);
  }
  assert(ans_dp[v] == dp[v]);
  recalc(v, p, w);
}
int v[MAXN], c[MAXN];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) cin >> v[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  int w;
  for (int i = 0; i < m; i++) {
    cin >> w;
    e[i << 1].first = w;
    e[i << 1 | 1].first = w;
  }
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--, b--;
    e[i << 1].second = b;
    e[i << 1 | 1].second = a;
    g[a].emplace_back(i << 1);
    g[b].emplace_back(i << 1 | 1);
  }
  dfs_br(0);
  int cur_col = 1;
  for (int i = 0; i < n; i++) {
    if (col[i]) continue;
    col[i] = cur_col;
    dfs_col(i);
    cur_col++;
  }
  int N = cur_col;
  for (int u : v) v_sum[col[u - 1]]++;
  for (int i = 0; i < n; i++) c_sum[col[i]] += (long long)c[i];
  for (int i : bb) {
    a = e[i].second, b = e[i ^ 1].second;
    if (col[a] == col[b]) continue;
    gn[col[a]].emplace_back(i ^ 1);
    gn[col[b]].emplace_back(i);
  }
  dfs_dp(1);
  dfs_ans(1, 1, 0LL);
  for (int i = 0; i < n; i++) {
    cout << ans_dp[col[i]] << ' ';
  }
  cout << '\n';
  return 0;
}
