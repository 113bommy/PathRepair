#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
const int N = (1 << 20) + 5;
int cur[N], in[N], out[N], rev[N], owo[N], col[N], n, Q, x, y;
vector<pair<int, int> > e[N];
namespace tree {
int d[N], in[N], out[N];
int mn[N][21], lg[N], clk, clk2;
int Min(int x, int y) { return d[x] < d[y] ? x : y; }
void dfs1(int u, int fa) {
  d[u] = d[fa] + 1;
  mn[in[u] = ++clk][0] = u;
  ::rev[::in[u] = ++clk2] = u;
  for (auto v : e[u]) {
    if (v.first == fa) continue;
    cur[v.second] = v.first;
    col[v.first] = col[u] ^ owo[v.second];
    dfs1(v.first, u);
    mn[++clk][0] = u;
  }
  out[u] = clk;
  ::out[u] = clk2;
}
void init() {
  dfs1(1, 0);
  lg[0] = -1;
  for (int i = (1); i <= (clk); i++) {
    lg[i] = lg[i >> 1] + 1;
  }
  for (int i = (clk); i >= (1); i--) {
    for (int j = 1; i + (1 << j) - 1 <= clk; j++) {
      mn[i][j] = Min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int lca(int x, int y) {
  x = in[x], y = in[y];
  if (x > y) swap(x, y);
  int t = lg[y - x + 1];
  return Min(mn[x][t], mn[y - (1 << t) + 1][t]);
}
int dist(int x, int y) {
  if (!x || !y) return -1;
  return d[x] + d[y] - 2 * d[lca(x, y)];
}
void upd(pair<int, int> &res, int x) {
  int mx = dist(res.first, res.second);
  int t1 = dist(res.first, x);
  int t2 = dist(res.second, x);
  if (t1 >= mx && t1 >= t2)
    res.second = x;
  else if (t2 >= mx)
    res.first = x;
}
pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  pair<int, int> res = a;
  if (!res.first) res = b;
  if (b.first) upd(res, b.first);
  if (b.second) upd(res, b.second);
  return res;
}
}  // namespace tree
namespace seg {
pair<pair<int, int>, pair<int, int> > T[N << 2];
int tag[N];
void up(int o) {
  T[o].first = tree::merge(T[(o << 1)].first, T[(o << 1 | 1)].first);
  T[o].second = tree::merge(T[(o << 1)].second, T[(o << 1 | 1)].second);
}
void app(int o) {
  swap(T[o].first, T[o].second);
  tag[o] = 1;
}
void down(int o) {
  if (tag[o]) {
    app((o << 1)), app((o << 1 | 1));
    tag[o] = 0;
  }
}
void upd(int o, int l, int r, int x, int y) {
  if (l == x && y == r) {
    app(o);
    return;
  }
  down(o);
  if (x <= ((l + r) >> 1))
    upd((o << 1), l, ((l + r) >> 1), x, min(y, ((l + r) >> 1)));
  if (((l + r) >> 1) < y)
    upd((o << 1 | 1), ((l + r) >> 1) + 1, r, max(((l + r) >> 1) + 1, x), y);
  up(o);
}
void build(int o, int l, int r) {
  if (l == r) {
    if (!col[rev[l]]) {
      T[o].first = make_pair(rev[l], rev[l]);
      T[o].second = make_pair(0, 0);
    } else {
      T[o].second = make_pair(rev[l], rev[l]);
      T[o].first = make_pair(0, 0);
    }
    return;
  }
  build((o << 1), l, ((l + r) >> 1));
  build((o << 1 | 1), ((l + r) >> 1) + 1, r);
  up(o);
}
}  // namespace seg
int main() {
  read(n);
  for (int i = (1); i <= (n - 1); i++) {
    read(x), read(y), read(owo[i]);
    e[x].push_back(make_pair(y, i));
    e[y].push_back(make_pair(x, i));
  }
  tree::init();
  seg::build(1, 1, n);
  read(Q);
  while (Q--) {
    read(x);
    seg::upd(1, 1, n, in[cur[x]], out[cur[x]]);
    pair<pair<int, int>, pair<int, int> > ret = seg::T[1];
    int ans1 = tree::dist(ret.first.first, ret.first.second);
    int ans2 = tree::dist(ret.second.first, ret.second.second);
    printf("%d\n", max(ans1, ans2));
  }
  return 0;
}
