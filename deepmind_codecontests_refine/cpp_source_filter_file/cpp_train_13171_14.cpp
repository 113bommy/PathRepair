#include <bits/stdc++.h>
using namespace std;
const int maxn = 200200;
int n, k;
int a[maxn];
vector<int> g[maxn];
int sz[maxn];
int dpd[maxn], dpu[maxn];
int mxd[maxn], mxu[maxn];
int mark[maxn], cnt[maxn];
int mxc[maxn], N;
int ans;
void dfs(int v, int par = -1) {
  sz[v] = 1;
  cnt[v] = mark[v];
  int c = 0;
  for (int u : g[v])
    if (u != par) {
      dfs(u, v);
      cnt[v] += cnt[u];
      sz[v] += sz[u];
      if (!cnt[u]) {
        dpd[v] += dpd[u];
        mxd[v] += dpd[u];
      } else
        c = max(c, mxd[u]);
    }
  if (mark[v])
    dpd[v] = 0, mxd[v] = 0;
  else
    dpd[v]++, mxd[v] += c;
}
void gfs(int v, int par = -1) {
  if (cnt[v] == N) dpu[v] = n - sz[v];
  if (!mark[v]) {
    mxu[v] += mxc[v];
    int d, c;
    if (cnt[v] == N)
      d = dpu[v] + 1, c = 0;
    else
      d = 1, c = mxu[v];
    for (int u : g[v])
      if (u != par) {
        mxu[u] += d;
        mxc[u] = max(mxc[u], c);
        if (!cnt[u])
          d += dpd[u];
        else
          c = max(c, mxd[u]);
      }
    reverse(g[v].begin(), g[v].end());
    d = 0, c = 0;
    for (int u : g[v])
      if (u != par) {
        mxu[u] += d;
        mxc[u] = max(mxc[u], c);
        if (!cnt[u])
          d += dpd[u];
        else
          c = max(c, mxd[u]);
      }
  } else
    dpu[v] = mxu[v] = 0;
  for (int u : g[v])
    if (u != par) gfs(u, v);
}
bool check(int x) {
  N = 0;
  memset(sz, 0, sizeof sz);
  memset(dpd, 0, sizeof dpd);
  memset(dpu, 0, sizeof dpu);
  memset(mxc, 0, sizeof mxc);
  memset(mxd, 0, sizeof mxd);
  memset(mxu, 0, sizeof mxu);
  for (int i = 0; i < n; i++) mark[i] = (a[i] < x);
  for (int i = 0; i < n; i++) N += mark[i];
  dfs(0);
  gfs(0);
  for (int i = 0; i < n; i++)
    if (!mark[i])
      if (mxd[i] + dpu[i] >= k or mxu[i] + dpd[i] >= k) return true;
  return false;
}
void solve() {
  int l = 1, r = 1000001;
  int mid;
  while (l != r - 1) {
    mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  ans = l;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int v, u, i = 0; i < n - 1; i++) {
    cin >> v >> u;
    v--, u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  solve();
  cout << ans << endl;
  return 0;
}
