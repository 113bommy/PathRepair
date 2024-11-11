#include <bits/stdc++.h>
using namespace std;
const int N = 100100, L = 18;
const int INF = 1000 * 1000 * 1000LL;
vector<pair<int, int> > adj[N];
vector<int> vc;
int lazy[N * 4], st[N], en[N], p[N][L], ans[N], dp[N], ds[N], dist[N], a[N],
    h[N], rst[N], start, n;
bool mark[N];
pair<int, int> mi[2][N * 4];
void shift(int ind) {
  int a = lazy[ind];
  for (int z = 0; z < 2; z++) {
    mi[0][ind * 2 + z].first += a;
    mi[1][ind * 2 + z].first += a;
    lazy[ind * 2 + z] += a;
  }
  lazy[ind] = 0;
  return;
}
void add(int l, int r, int val, int b = 0, int e = N, int ind = 1) {
  if (l <= b && e <= r) {
    lazy[ind] += val;
    mi[0][ind].first += val;
    mi[1][ind].first += val;
    return;
  }
  int mid = (b + e) / 2;
  shift(ind);
  if (l < mid) add(l, r, val, b, mid, ind * 2);
  if (r > mid) add(l, r, val, mid, e, ind * 2 + 1);
  mi[0][ind] = (mi[0][ind * 2].first == mi[0][ind * 2 + 1].first
                    ? mi[0][ind * 2]
                    : max(mi[0][ind * 2], mi[0][ind * 2 + 1]));
  mi[1][ind] = max(mi[1][ind * 2], mi[1][ind * 2 + 1]);
  return;
}
pair<int, int> get(int sgn, int l, int r, int b = 0, int e = N, int ind = 1) {
  if (l <= b && e <= r) return mi[sgn][ind];
  int mid = (b + e) / 2;
  shift(ind);
  pair<int, int> ret = {-INF - 10, -INF}, a;
  if (l < mid) ret = get(sgn, l, r, b, mid, ind * 2);
  if (r > mid) {
    pair<int, int> a = get(sgn, l, r, mid, e, ind * 2 + 1);
    if (a.first > ret.first)
      ret = a;
    else if (a.first == ret.first && sgn)
      ret = a;
  }
  return ret;
}
int LCA(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  int t = h[u] - h[v];
  for (int i = 0; i < L; i++)
    if (((1 << i) & t)) u = p[u][i];
  if (u == v) return u;
  for (int i = L - 1; i >= 0; i--)
    if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
  return p[u][0];
}
void DFS0(int v, int par, int w) {
  st[v] = start;
  rst[start++] = v;
  h[v] = h[par] + 1;
  dist[v] = dist[par] + w;
  p[v][0] = par;
  for (int i = 1; i < L; i++) p[v][i] = p[p[v][i - 1]][i - 1];
  for (auto u : adj[v])
    if (u.first != par) DFS0(u.first, v, u.second);
  en[v] = start;
  add(st[v], en[v], w);
  return;
}
void DFS1(int v, int par, int w) {
  add(0, n, w);
  add(st[v], en[v], -2 * w);
  pair<int, int> mns = get(0, st[v], en[v]), mxs = get(1, st[v], en[v]);
  pair<int, int> a = get(0, 0, st[v]), b = get(0, en[v], n),
                 mnt = (a.first == b.first ? a : max(a, b));
  pair<int, int> mxt = max(get(1, 0, st[v]), get(1, en[v], n));
  dp[v] = mns.first, ds[v] = mnt.first;
  if (!mark[v])
    int tmp = 0;
  else if (mxs.first > mxt.first) {
    int x = rst[mns.second], y = rst[mxs.second], z = LCA(x, y);
    ans[z]++;
    ans[v]--;
  } else if (mxt.first > mxs.first) {
    pair<int, int> x = get(1, 0, st[v]), y = get(0, st[v], n);
    int z;
    if (x.first > y.first)
      z = LCA(rst[x.second], v);
    else if (y.first > x.first)
      z = LCA(rst[y.second], v);
    else {
      int xx = LCA(v, rst[x.second]), yy = LCA(v, rst[y.second]);
      if (h[xx] < h[yy])
        z = yy;
      else
        z = xx;
    }
    if (z) ans[p[0][z]]--;
    ans[v]++;
    if (ds[z] + dist[v] - dist[z] < mxt.first) {
      int a = rst[get(0, st[z], en[z]).second],
          b = rst[get(1, st[z], en[z]).second], c = LCA(a, b);
      ans[c]++, ans[z]--;
    }
  }
  for (auto u : adj[v])
    if (u.first != par) DFS1(u.first, v, u.second);
  add(0, n, -w);
  add(st[v], en[v], 2 * w);
  return;
}
void DFS2(int v, int par) {
  for (auto u : adj[v])
    if (u.first != par) DFS2(u.first, v), ans[v] += ans[u.first];
  return;
}
void build(int b = 0, int e = N, int ind = 1) {
  mi[0][ind] = {0, b};
  mi[1][ind] = {0, e - 1};
  if (b + 1 == e) return;
  int mid = (b + e) / 2;
  build(b, mid, ind * 2);
  build(mid, e, ind * 2 + 1);
  return;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int m, u, v, w;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    mark[--a[i]] = 1;
  }
  for (int i = 1; i < n; i++) {
    cin >> u >> v >> w;
    adj[--u].push_back({--v, w});
    adj[v].push_back({u, w});
  }
  build();
  DFS0(0, 0, 0);
  for (int i = 0; i < n; i++)
    if (!mark[i]) add(st[i], st[i] + 1, -INF);
  DFS1(0, 0, 0);
  DFS2(0, 0);
  int mx(0), cnt(0);
  for (int i = 0; i < n; i++) {
    if (!mark[i]) {
      if (ans[i] > mx)
        mx = ans[i], cnt = 1;
      else if (ans[i] == mx)
        cnt++;
    }
  }
  cout << mx << " " << cnt << endl;
  return 0;
}
