#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O2")
using namespace std;
const int N = 100000 + 10;
const long long MOD = 1000000000 + 7;
const long long INF = 1000000010;
const long long LOG = 18;
struct DP {
  int mx, mx2, mnh, mxh;
};
int par[N][LOG], n, m, h[N], st[N], inv[N], ft[N], Time, sm[N], mnst[N],
    mxst[N], hh[N];
long long seg[N << 2], lazy[N << 2];
bool mark[N];
DP dpu[N], dpd[N];
vector<pair<int, int> > G[N];
void modify(int id, long long x) {
  seg[id] += x;
  lazy[id] += x;
}
void shift(int id) {
  modify(id << 1, lazy[id]);
  modify(id << 1 | 1, lazy[id]);
  lazy[id] = 0;
}
void add(int id, int lq, int rq, long long x, int l, int r) {
  if (rq <= l || r <= lq) return;
  if (lq <= l && r <= rq) {
    modify(id, x);
    return;
  }
  int md = (l + r) >> 1;
  shift(id);
  add(id << 1, lq, rq, x, l, md);
  add(id << 1 | 1, lq, rq, x, md, r);
  seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
int Fi(int id, int x, int l, int r) {
  if (r - l == 1) return l;
  int md = (l + r) >> 1;
  shift(id);
  if (seg[id << 1] == x) return Fi(id << 1, x, l, md);
  return Fi(id << 1 | 1, x, md, r);
}
int Se(int id, int x, int l, int r) {
  if (r - l == 1) return l;
  int md = (l + r) >> 1;
  shift(id);
  if (seg[id << 1] == x) return Se(id << 1, x, l, md);
  return Se(id << 1 | 1, x, md, r);
}
int LCA(int v, int u) {
  if (h[v] < h[u]) swap(v, u);
  int res = h[v] - h[u];
  for (int i = 0; i < LOG; i++)
    if (res & (1 << i)) v = par[v][i];
  if (v == u) return v;
  for (int i = LOG - 1; i >= 0; i--) {
    if (par[v][i] != par[u][i]) v = par[v][i], u = par[u][i];
  }
  return par[v][0];
}
void pre(int v = 1, int p = 0) {
  par[v][0] = p;
  for (int i = 1; i < LOG; i++) par[v][i] = par[par[v][i - 1]][i - 1];
  st[v] = ++Time;
  add(1, st[v], st[v] + 1, hh[v], 1, n + 1);
  inv[Time] = v;
  for (auto u : G[v]) {
    if (u.first == p) continue;
    h[u.first] = h[v] + 1;
    hh[u.first] = h[v] + u.second;
    pre(u.first, v);
  }
  ft[v] = Time + 1;
}
void DFS(int v = 1, int p = 0) {
  dpd[v].mx = (mark[v] ? 0 : -INF);
  vector<int> dp2;
  dp2.push_back(dpd[v].mx);
  mnst[v] = Fi(1, seg[1], 1, n + 1);
  mxst[v] = Se(1, seg[1], 1, n + 1);
  for (auto u : G[v]) {
    if (u.first == p) continue;
    add(1, st[u.first], ft[u.first], -2 * u.second, 1, n + 1);
    add(1, 1, n + 1, +u.second, 1, n + 1);
    DFS(u.first, v);
    add(1, st[u.first], ft[u.first], +2 * u.second, 1, n + 1);
    add(1, 1, n + 1, -u.second, 1, n + 1);
    dp2.push_back(dpd[u.first].mx + u.second);
  }
  dp2.push_back(-INF);
  dp2.push_back(-INF);
  sort(dp2.begin(), dp2.end());
  reverse(dp2.begin(), dp2.end());
  dpd[v].mx = dp2[0];
  dpd[v].mx2 = dp2[1];
}
void DFS2(int v = 1, int p = 0, int c = 0) {
  dpu[v].mx = (mark[v] ? 0 : -INF);
  dpu[v].mnh = v, dpu[v].mxh = v;
  if (p != 0) {
    if (dpu[p].mx > dpu[v].mx) {
      dpu[v] = dpu[p];
      dpu[v].mx = dpu[p].mx + c;
    }
    if (dpd[p].mx == dpd[v].mx + c) {
      if (dpd[p].mx2 + c == dpu[v].mx) {
        dpu[v].mxh = p;
      } else if (dpd[p].mx2 + c > dpu[v].mx) {
        dpu[v].mx = dpd[p].mx2 + c;
        dpu[v].mnh = p;
        dpu[v].mxh = p;
      }
    } else {
      if (dpd[p].mx + c == dpu[v].mx) {
        dpu[v].mxh = p;
      } else if (dpd[p].mx + c > dpu[v].mx) {
        dpu[v].mx = dpd[p].mx + c;
        dpu[v].mxh = p;
        dpu[v].mnh = p;
      }
    }
  }
  for (auto u : G[v]) {
    if (u.first == p) continue;
    DFS2(u.first, v, u.second);
  }
}
void DFS3(int v = 1, int p = 0) {
  for (auto u : G[v]) {
    if (u.first == p) continue;
    DFS3(u.first, v);
    sm[v] += sm[u.first];
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    mark[x] = 1;
  }
  for (int i = 1; i <= n - 1; i++) {
    int v, u, c;
    cin >> v >> u >> c;
    G[v].push_back({u, c});
    G[u].push_back({v, c});
  }
  pre();
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) add(1, st[i], st[i] + 1, -INF, 1, n + 1);
  }
  DFS();
  DFS2();
  for (int i = 1; i <= n; i++) {
    if (mark[i]) {
      if (dpd[i].mx == dpu[i].mx) continue;
      int v, u;
      v = i;
      if (dpu[i].mx > dpd[i].mx && dpu[i].mnh != dpu[i].mxh) {
        u = dpu[i].mxh;
      } else {
        u = LCA(inv[mnst[i]], inv[mxst[i]]);
      }
      sm[v]++;
      sm[u]++;
      sm[par[LCA(v, u)][0]]--;
      sm[LCA(v, u)]--;
    }
  }
  DFS3();
  int mx = 0, ted = 0;
  for (int i = 1; i <= n; i++) {
    if (mark[i]) continue;
    if (sm[i] == mx)
      ted++;
    else if (sm[i] > mx)
      mx = sm[i], ted = 1;
  }
  cout << mx << ' ' << ted;
  return 0;
}
