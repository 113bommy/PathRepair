#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, mod = 1e9 + 7;
const long long inf = 1e18;
vector<int> v[maxn];
int h[maxn], sp[20][maxn], mxu[20][maxn], mxd[20][maxn], dn[maxn], up[maxn];
int MX[maxn][3];
void dfs(int u, int par = 0) {
  sp[0][u] = par;
  for (int i = 1; i < 20; i++) {
    sp[i][u] = sp[i - 1][sp[i - 1][u]];
  }
  h[u] = h[par] + 1;
  for (int y : v[u]) {
    if (y != par) {
      dfs(y, u);
      dn[u] = max(dn[u], dn[y] + 1);
    }
  }
}
void dfs2(int u, int par = 0) {
  for (int i = 1; i < 20; i++) {
    if (sp[i][u] == 0) continue;
    mxd[i][u] = max(mxd[i - 1][u], -(1 << (i - 1)) + mxd[i - 1][sp[i - 1][u]]);
    mxu[i][u] = max(mxu[i - 1][u], (1 << (i - 1)) + mxu[i - 1][sp[i - 1][u]]);
  }
  int id1 = -1, id2 = -1;
  for (int y : v[u]) {
    if (y == par) continue;
    if (id1 == -1)
      id1 = y;
    else if (dn[y] > dn[id1])
      id2 = id1, id1 = y;
    else if (id2 == -1)
      id2 = y;
    else if (dn[y] > dn[id2])
      id2 = y;
  }
  MX[u][0] = id1, MX[u][1] = id2;
  MX[u][2] = -1;
  for (int y : v[u]) {
    if (y == par || y == id1 || y == id2) continue;
    if (MX[u][2] == -1) MX[u][2] = y;
    if (dn[MX[u][2]] < dn[y]) MX[u][2] = y;
  }
  if (id1 == -1) return;
  for (int y : v[u]) {
    if (y == par || y == id1) continue;
    up[y] = max(up[u] + 1, dn[id1] + 2), mxu[0][y] = dn[id1] + 2,
    mxd[0][y] = dn[id1];
    dfs2(y, u);
  }
  if (id2 == -1)
    up[id1] = up[u] + 1, mxu[0][id1] = 1, mxd[0][id1] = -1, dfs2(id1, u);
  else
    up[id1] = max(up[u] + 1, dn[id2] + 2), mxu[0][id1] = dn[id2] + 2,
    mxd[0][id1] = dn[id2], dfs2(id1, u);
}
int lca(int a, int b) {
  if (h[a] < h[b]) swap(a, b);
  for (int i = 19; i >= 0; i--) {
    if (h[sp[i][a]] >= h[b]) a = sp[i][a];
  }
  if (a == b) return a;
  for (int i = 19; i >= 0; i--) {
    if (sp[i][a] != sp[i][b]) a = sp[i][a], b = sp[i][b];
  }
  return sp[0][a];
}
int solve(int a, int b) {
  int lc = lca(a, b);
  if (h[a] < h[b]) swap(a, b);
  int ans = dn[a];
  if (b != lc) ans = max(ans, dn[b]);
  int x = 0;
  for (int i = 19; i >= 0; i--) {
    if (h[b] - (1 << i) > h[lc]) {
      ans = max(ans, x + mxu[i][a]);
      ans = max(ans, x + mxu[i][b]);
      x += (1 << i);
      a = sp[i][a];
      b = sp[i][b];
    }
  }
  ans = max(ans, x + (b != lc) + up[lc]);
  int aa = a;
  for (int i = 19; i >= 0; i--) {
    if (h[aa] - (1 << i) > h[lc]) aa = sp[i][aa];
  }
  for (int pt = 0; pt < 3 && MX[lc][pt] != -1; pt++) {
    if (MX[lc][pt] != aa && MX[lc][pt] != b)
      ans = max(ans, x + 1 + (b != lc) + dn[MX[lc][pt]]);
  }
  if (b != lc) {
    if (sp[0][a] == lc) return ans;
    ans = max(ans, x + mxu[0][a]), a = sp[0][a];
    b = lc, x++;
  }
  int d = (h[a] - h[b]) / 2;
  int xx = x;
  for (int i = 19; i >= 0; i--) {
    if ((((d) >> (i)) & 1))
      ans = max(ans, xx + mxu[i][a]), a = sp[i][a], xx += (1 << i);
  }
  x += (h[a] - h[b]);
  for (int i = 19; i >= 0; i--) {
    if (h[sp[i][a]] > h[b]) {
      ans = max(ans, x + mxd[i][a]);
      a = sp[i][a];
      x -= (1 << i);
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1), dfs2(1);
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << "\n";
  }
  return 0;
}
