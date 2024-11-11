#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool was[N], isC[N];
int par[N], col[N];
int cnt;
map<pair<int, int>, bool> mp;
void dfs(int v, int p) {
  was[v] = 1;
  par[v] = p;
  for (auto i : g[v]) {
    if (i == par[v])
      continue;
    else if (was[i] && mp[{v, i}]) {
      mp[{v, i}] = mp[{i, v}] = 0;
      int cur = v;
      while (cur != par[i]) {
        col[cur] = cnt;
        cur = par[cur];
      }
      isC[cnt] = 1;
      cnt++;
    } else if (!was[i]) {
      dfs(i, v);
    }
  }
}
const long long mod = 1000000007;
int dp[N];
int h[N], frst[N];
vector<int> ord;
void dfs1(int v, int p) {
  h[v] = h[p] + 1;
  was[v] = 1;
  frst[v] = cnt++;
  par[v] = p;
  ord.push_back(v);
  long long r = 0;
  if (isC[v]) r = 1;
  dp[v] = dp[p] + r;
  for (auto i : g[v]) {
    if (!was[i]) {
      dfs1(i, v);
      ord.push_back(v);
      cnt++;
    }
  }
}
int t[N * 4], num[N * 4];
int P;
void built(int v, int l, int r) {
  if (l == r && l < P) {
    t[v] = h[ord[l]];
    num[v] = ord[l];
    return;
  }
  if (l >= P) {
    return;
  }
  int m = (l + r) / 2;
  built(v * 2, l, m);
  built(v * 2 + 1, m + 1, r);
  if (t[v * 2] <= t[v * 2 + 1]) {
    t[v] = t[v * 2];
    num[v] = num[v * 2];
  } else {
    t[v] = t[v * 2 + 1];
    num[v] = num[v * 2 + 1];
  }
}
pair<int, int> getMin(int v, int l, int r, int lb, int rb) {
  if (r < lb || rb < l) return {N + N, -1};
  if (lb <= l && r <= rb) return {t[v], num[v]};
  int m = (l + r) / 2;
  pair<int, int> p1 = getMin(v * 2, l, m, lb, rb);
  pair<int, int> p2 = getMin(v * 2 + 1, m + 1, r, lb, rb);
  if (p1.first <= p2.first)
    return p1;
  else
    return p2;
}
int X[N], Y[N];
long long POW[N];
void calc() {
  POW[0] = 1;
  for (int i = 1; i < N; i++) {
    POW[i] = (POW[i - 1] * 2) % mod;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  calc();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    mp[{x, y}] = mp[{y, x}] = 1;
    X[i] = x, Y[i] = y;
  }
  cnt = 1;
  dfs(1, -1);
  for (int i = 1; i <= n; i++) {
    if (!col[i]) col[i] = cnt++;
  }
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    g[i].resize(0);
    was[i] = 0;
    par[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int x = X[i], y = Y[i];
    if (col[x] != col[y]) {
      g[col[x]].push_back(col[y]);
      g[col[y]].push_back(col[x]);
    }
  }
  if (isC[1]) dp[1] = 1;
  dfs1(1, 0);
  P = ord.size();
  built(1, 0, N);
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (col[a] == col[b]) {
      cout << "2\n";
      continue;
    }
    a = col[a], b = col[b];
    if (frst[a] > frst[b]) swap(a, b);
    pair<int, int> p = getMin(1, 0, N, frst[a], frst[b]);
    int NUM = p.second;
    assert(NUM != b);
    if (NUM == a) {
      cout << (POW[dp[b] - dp[par[a]]] + mod) % mod << "\n";
    } else {
      long long f1 = POW[dp[b] - dp[par[NUM]]], f2 = POW[dp[a] - dp[NUM]];
      cout << (f1 * f2) % mod << "\n";
    }
  }
}
