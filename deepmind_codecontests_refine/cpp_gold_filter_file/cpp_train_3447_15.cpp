#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double PI = acos(-1);
int n, i, j, k, t;
vector<int> adj[100002];
int lvl[100002], sz[100002];
int p[100002];
int up[100002][20];
int st[100002];
int ed[100002];
int arr[200002];
int q;
int timer;
int treel[400004];
int treer[400004];
void build(int l, int r, int pos) {
  if (l == r) {
    treel[pos] = st[l];
    treer[pos] = ed[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, 2 * pos + 1);
  build(mid + 1, r, 2 * pos + 2);
  treel[pos] = min(treel[pos * 2 + 1], treel[pos * 2 + 2]);
  treer[pos] = max(treer[2 * pos + 1], treer[2 * pos + 2]);
}
pair<int, int> query(int l, int r, int pos, int ql, int qr) {
  if (l > qr || r < ql || ql > qr) return {1e6, -1e6};
  if (l >= ql && r <= qr) {
    return {treel[pos], treer[pos]};
  }
  int mid = (l + r) / 2;
  pair<int, int> a = query(l, mid, 2 * pos + 1, ql, qr);
  pair<int, int> b = query(mid + 1, r, 2 * pos + 2, ql, qr);
  return {min(a.first, b.first), max(a.second, b.second)};
}
void dfs(int v) {
  lvl[v] = 1 + lvl[p[v]];
  arr[timer] = v;
  st[v] = timer++;
  sz[v] = 1;
  up[v][0] = p[v];
  for (int i = 1; i < 20; ++i) {
    up[v][i] = up[up[v][i - 1]][i - 1] == 0 ? 1 : up[up[v][i - 1]][i - 1];
  }
  for (int x : adj[v]) {
    dfs(x);
    sz[v] += sz[x];
  }
  ed[v] = timer;
  arr[timer++] = v;
}
bool is_total(int v, int l, int r) { return st[v] <= l && ed[v] >= r; }
int spt(int v, int l, int r) {
  if (is_total(v, l, r)) return v;
  for (int i = 19; i >= 0; --i) {
    if (!is_total(up[v][i], l, r)) v = up[v][i];
  }
  return up[v][0];
}
int main() {
  memset(up, 0, sizeof up);
  timer = 0;
  scanf("%d %d", &n, &q);
  for (i = 2; i <= n; ++i) {
    scanf("%d", p + i);
    adj[p[i]].push_back(i);
  }
  p[1] = 1;
  lvl[0] = -1;
  dfs(1);
  build(1, n, 0);
  for (i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    int ans = -1, dep = -1;
    pair<int, int> range = query(1, n, 0, l, r);
    int ln = arr[range.first], rn = arr[range.second];
    pair<int, int> tmpa = query(1, n, 0, l, ln - 1);
    pair<int, int> tmpb = query(1, n, 0, ln + 1, r);
    pair<int, int> rangea = {min(tmpa.first, tmpb.first),
                             max(tmpa.second, tmpb.second)};
    int node = spt(arr[rangea.first], rangea.first, rangea.second);
    if (lvl[node] > dep) {
      dep = lvl[node];
      ans = ln;
    }
    tmpa = query(1, n, 0, l, rn - 1);
    tmpb = query(1, n, 0, rn + 1, r);
    pair<int, int> rangeb = {min(tmpa.first, tmpb.first),
                             max(tmpa.second, tmpb.second)};
    node = spt(arr[rangeb.first], rangeb.first, rangeb.second);
    if (lvl[node] > dep) {
      dep = lvl[node];
      ans = rn;
    }
    printf("%d %d\n", ans, dep - 1);
  }
  return 0;
}
