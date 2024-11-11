#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;
const int N = 1e6 + 228;
const int inf = 1e9 + 228;
int t[4 * N];
void push(int v, int len) {
  t[v << 1] = min(t[v << 1], t[v]);
  t[v << 1 | 1] = min(t[v << 1 | 1], t[v] + ((len + 1) >> 1));
}
void upd(int v, int l, int r, int l1, int r1, int x) {
  if (r < l1 || r1 < l) {
    return;
  }
  if (l1 <= l && r <= r1) {
    t[v] = min(t[v], x);
    return;
  }
  push(v, r - l + 1);
  int m = (l + r) >> 1;
  upd(v << 1, l, m, l1, r1, x);
  upd(v << 1 | 1, m + 1, r, l1, r1, x + ((r - l + 1 + 1) >> 1));
}
int get(int v, int l, int r, int pos) {
  if (l == r) {
    return t[v];
  }
  push(v, r - l + 1);
  int m = (l + r) >> 1;
  if (pos <= m) {
    return get(v << 1, l, m, pos);
  }
  return get(v << 1 | 1, m + 1, r, pos);
}
int n;
vector<pair<char, int>> g[N];
int in[N], out[N], timer;
int k;
int ins[N];
vi s;
vi qs;
int dp[N];
void dfs(int v) {
  in[v] = timer++;
  for (auto to : g[v]) {
    dfs(to.second);
  }
  out[v] = timer++;
}
void solve(int v) {
  if (ins[v] != -1) {
    dp[v] = min(dp[v], get(1, 0, N - 1, ins[v]));
  }
  int lf = 0, rg = k - 1;
  while (lf < rg) {
    int md = (lf + rg) >> 1;
    if (in[s[md]] >= in[v]) {
      rg = md;
    } else {
      lf = md + 1;
    }
  }
  int L = lf;
  lf = 0, rg = k - 1;
  while (lf < rg) {
    int md = (lf + rg + 1) >> 1;
    if (in[s[md]] < out[v]) {
      lf = md;
    } else {
      rg = md - 1;
    }
  }
  int R = lf;
  if (L <= R && in[v] <= in[s[L]] && out[s[L]] <= out[v]) {
    upd(1, 0, N - 1, L, R, dp[v] + 1 - L);
  }
  for (auto e : g[v]) {
    int to = e.second;
    dp[to] = dp[v] + 1;
    solve(to);
  }
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int p;
    char c;
    cin >> p >> c;
    g[p].push_back(make_pair(c, i));
  }
  for (int u = 0; u <= n; u++) {
    sort((g[u]).begin(), (g[u]).end());
  }
  dfs(0);
  cin >> k;
  s.resize(k);
  qs.resize(k);
  for (int i = 0; i < k; i++) {
    cin >> s[i];
    qs[i] = s[i];
  }
  sort((s).begin(), (s).end(), [&](int u, int v) { return in[u] < in[v]; });
  memset(ins, -1, sizeof(ins));
  for (int i = 0; i < k; i++) {
    ins[s[i]] = i;
  }
  for (int i = 0; i < 4 * N; i++) {
    t[i] = inf;
  }
  solve(0);
  for (int u : qs) {
    cout << dp[u] << ' ';
  }
}
