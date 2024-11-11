#include <bits/stdc++.h>
using namespace std;
template <typename _Tp>
bool maximize(_Tp &__a, _Tp __b) {
  if (__a < __b) {
    __a = __b;
    return true;
  }
  return false;
}
template <typename _Tp>
bool minimize(_Tp &__a, _Tp __b) {
  if (__a > __b) {
    __a = __b;
    return true;
  }
  return false;
}
const int siz = 1e5 + 2;
const int SIZ = 1e6 + 2;
const int mod = 1e9 + 7;
const int maxx = 1e9;
const long long MAXX = 1e18;
const string file = "3";
vector<vector<int> > adj_list;
int dep[siz], anc[siz][20];
int tin[siz], tout[siz], cur;
void dfs(int u, int p) {
  tin[u] = ++cur;
  for (auto v : adj_list[u]) {
    if (v == p) {
      continue;
    }
    dep[v] = dep[u] + 1;
    anc[v][0] = u;
    dfs(v, u);
  }
  tout[u] = cur;
}
bool is_anc(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }
int lca(int u, int v) {
  if (is_anc(u, v)) {
    return u;
  }
  if (is_anc(v, u)) {
    return v;
  }
  for (int i = 19; i >= 0; i--) {
    if (anc[u][i] != -1 && !is_anc(anc[u][i], v)) {
      u = anc[u][i];
    }
  }
  return anc[u][0];
}
int lca(int r, int u, int v) {
  if (is_anc(r, u) && is_anc(r, v)) {
    return lca(u, v);
  }
  if (is_anc(r, u) || is_anc(r, v)) {
    return r;
  }
  int p = lca(r, u), q = lca(r, v);
  if (p == q) {
    return lca(u, v);
  }
  return (dep[p] > dep[q]) ? p : q;
}
int lift(int u, int k) {
  int d = dep[u] - k;
  assert(d >= 0);
  for (int i = 19; i >= 0; i--) {
    if (anc[u][i] != -1 && dep[anc[u][i]] >= d) {
      u = anc[u][i];
    }
  }
  return u;
}
struct segment_tree {
  struct node {
    long long sum, lazy;
    node(long long val) : sum(val), lazy(0) {}
    node() : sum(0), lazy(0) {}
    node operator+(const node &oth) const { return node(sum + oth.sum); }
  };
  int s, e;
  vector<node> smt;
  segment_tree(int s, int e) : s(s), e(e) {
    assert(0 <= s && s <= e);
    smt.assign(4 * (e - s + 1), node());
  }
  segment_tree() : s(-1), e(-1) {}
  void propagate(int nd, int st, int ed) {
    if (smt[nd].lazy != node().lazy) {
      smt[nd].sum += ((ed - st + 1) * smt[nd].lazy);
      if (st != ed) {
        smt[2 * nd].lazy += smt[nd].lazy;
        smt[2 * nd + 1].lazy += smt[nd].lazy;
      }
      smt[nd].lazy = node().lazy;
    }
  }
  void pos_update(int nd, int st, int ed, int pos, int val) {
    propagate(nd, st, ed);
    if (pos < st || ed < pos) {
      return;
    }
    if (st == ed) {
      smt[nd].sum += val;
      return;
    }
    int mid = (st + ed) / 2;
    pos_update(2 * nd, st, mid, pos, val);
    pos_update(2 * nd + 1, mid + 1, ed, pos, val);
    smt[nd] = smt[2 * nd] + smt[2 * nd + 1];
  }
  void range_update(int nd, int st, int ed, int lt, int rt, int val) {
    propagate(nd, st, ed);
    if (rt < st || ed < lt) {
      return;
    }
    if (lt <= st && ed <= rt) {
      smt[nd].lazy = val;
      propagate(nd, st, ed);
      return;
    }
    int mid = (st + ed) / 2;
    range_update(2 * nd, st, mid, lt, rt, val);
    range_update(2 * nd + 1, mid + 1, ed, lt, rt, val);
    smt[nd] = smt[2 * nd] + smt[2 * nd + 1];
  }
  node range_query(int nd, int st, int ed, int lt, int rt) {
    propagate(nd, st, ed);
    if (rt < st || ed < lt) {
      return node();
    }
    if (lt <= st && ed <= rt) {
      return smt[nd];
    }
    int mid = (st + ed) / 2;
    node s_l = range_query(2 * nd, st, mid, lt, rt);
    node s_r = range_query(2 * nd + 1, mid + 1, ed, lt, rt);
    return (s_l + s_r);
  }
  void pos_update(int pos, int val) {
    assert(s <= pos && pos <= e);
    pos_update(1, s, e, pos, val);
  }
  void range_update(int lt, int rt, int val) {
    assert(s <= lt && lt <= rt && rt <= e);
    range_update(1, s, e, lt, rt, val);
  }
  node range_query(int lt, int rt) {
    assert(s <= lt && lt <= rt && rt <= e);
    return range_query(1, s, e, lt, rt);
  }
};
int a[siz];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int u = (int)(1); u <= (int)(n); u++) {
    cin >> a[u];
  }
  adj_list.assign(n + 1, vector<int>());
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }
  int r = 1;
  memset(anc, -1, sizeof(anc));
  dfs(r, 0);
  for (int i = (int)(1); i <= (int)(19); i++) {
    for (int u = (int)(1); u <= (int)(n); u++) {
      if (anc[u][i - 1] != -1 && anc[anc[u][i - 1]][i - 1] != -1) {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
      }
    }
  }
  segment_tree seg(1, n);
  for (int u = (int)(1); u <= (int)(n); u++) {
    seg.pos_update(tin[u], a[u]);
  }
  while (q--) {
    int tk;
    cin >> tk;
    if (tk == 1) {
      cin >> r;
    } else if (tk == 2) {
      int u, v, x;
      cin >> u >> v >> x;
      int l = lca(r, u, v);
      if (l == r) {
        seg.range_update(1, n, x);
      } else if (is_anc(l, r)) {
        seg.range_update(1, n, x);
        int v = lift(r, dep[r] - dep[l] - 1);
        seg.range_update(tin[v], tout[v], -x);
      } else {
        seg.range_update(tin[l], tout[l], x);
      }
    } else {
      int u;
      cin >> u;
      long long ans;
      if (u == r) {
        ans = seg.range_query(1, n).sum;
      } else if (is_anc(u, r)) {
        ans = seg.range_query(1, n).sum;
        int v = lift(r, dep[r] - dep[u] - 1);
        ans -= seg.range_query(tin[v], tout[v]).sum;
      } else {
        ans = seg.range_query(tin[u], tout[u]).sum;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
