#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long Inf = 1e18;
const int mod = 1;
template <typename T = int>
T gi() {
  T x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
template <typename T>
bool chkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
};
template <typename T>
bool chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
};
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
void inc(int &a, int b) { a = (a + b >= mod ? a + b - mod : a + b); }
void dec(int &a, int b) { a = (a - b < 0 ? a - b + mod : a - b); }
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + "," + to_string(p.second) + ")";
}
template <typename T>
string to_string(T v) {
  int fst = 1;
  string ret = "{";
  for (auto x : v) {
    if (!fst) ret += ",";
    fst = 0, ret += to_string(x);
  }
  ret += "}";
  return ret;
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  dbg_out(T...);
}
template <typename T>
int qpow(int a, T b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1ll * ret * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return ret;
}
struct node {
  int mx = 0, tag = 0;
  void apply(int l, int r, int add) { mx += add; }
};
struct segtree {
  int n = 0;
  vector<node> tr;
  segtree(int n) : n(n) {
    int N = n + 10;
    tr.resize(N << 2);
  }
  void pushdown(int x, int l, int r) {}
  node merge(node a, node b) {
    node ret;
    ret.mx = max(a.mx, b.mx);
    return ret;
  }
  template <typename... T>
  void _build(int x, int l, int r, T *...a) {
    if (l == r) {
      tr[x].apply(l, r, a[l]...);
      return;
    }
    int mid = (l + r) >> 1;
    _build((x << 1), l, mid, a...), _build((x << 1 | 1), mid + 1, r, a...);
    pushup(x);
  }
  void pushup(int x) { tr[x] = merge(tr[(x << 1)], tr[(x << 1 | 1)]); }
  template <typename... T>
  void _modify(int x, int l, int r, int L, int R, T... v) {
    if (L <= l && r <= R) return tr[x].apply(l, r, v...);
    pushdown(x, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) _modify((x << 1), l, mid, L, R, v...);
    if (R > mid) _modify((x << 1 | 1), mid + 1, r, L, R, v...);
    pushup(x);
  }
  node _query(int x, int l, int r, int L, int R) {
    if (L <= l && r <= R) return tr[x];
    pushdown(x, l, r);
    int mid = (l + r) >> 1;
    if (R <= mid)
      return _query((x << 1), l, mid, L, R);
    else if (L > mid)
      return _query((x << 1 | 1), mid + 1, r, L, R);
    else
      return merge(_query((x << 1), l, mid, L, R),
                   _query((x << 1 | 1), mid + 1, r, L, R));
  }
  template <typename... T>
  void build(T *...a) {
    _build(1, 1, n, a...);
  }
  template <typename... T>
  void modify(int l, int r, T... v) {
    _modify(1, 1, n, l, r, v...);
  }
  node query(int l, int r) { return _query(1, 1, n, l, r); }
};
const int N = 6e5 + 10;
int n, C, f[N], g[N], emp, c[N], q[N], mx, ans[N], st[N], tp = 0;
map<pair<int, int>, int> h;
vector<tuple<int, int, int>> eve;
vector<int> vq;
set<int> s;
int find(int x) { return lower_bound(st + 1, st + tp + 1, x) - st; }
int main() {
  n = gi(), C = gi();
  for (int i = 1; i <= n; i++) {
    int l = gi(), r = gi();
    c[i] = gi();
    eve.push_back(make_tuple(l, 1, i));
    eve.push_back(make_tuple(r, -1, i));
    st[++tp] = c[i];
    if (c[i] <= C) st[++tp] = C - c[i];
  }
  sort(st + 1, st + tp + 1);
  tp = unique(st + 1, st + tp + 1) - st - 1;
  eve.push_back(make_tuple(2e9, 0, 0));
  sort(eve.begin(), eve.end());
  int m = gi();
  for (int i = 1; i <= m; i++) q[i] = gi(), vq.push_back(i);
  sort(vq.begin(), vq.end(), [&](int a, int b) { return q[a] > q[b]; });
  int lst = 0;
  segtree tr(tp);
  for (auto p : eve) {
    int x, op, i;
    tie(x, op, i) = p;
    int len = x - lst;
    if (s.empty())
      emp += len;
    else if (int(s.size()) == 1) {
      int x = *s.begin();
      if (c[x] <= C) {
        f[x] += len, g[x] += len;
        tr.modify(find(c[i]), find(c[i]), len);
        chkmax(mx, g[x]);
      }
    } else if (int(s.size()) == 2) {
      int x = *s.begin(), y = *s.rbegin();
      if (c[x] + c[y] <= C) {
        h[make_pair(x, y)] += len;
        chkmax(g[x], f[x] + f[y] + h[make_pair(x, y)]);
        chkmax(g[y], f[x] + f[y] + h[make_pair(x, y)]);
        chkmax(mx, g[x]), chkmax(mx, g[y]);
      }
    }
    while (!vq.empty() && 1ll * emp + mx >= q[vq.back()]) {
      ans[vq.back()] = x - (1ll * emp + mx - q[vq.back()]);
      vq.pop_back();
    }
    if (vq.empty()) break;
    if (op == 1) {
      s.insert(i);
      if (c[i] <= C) {
        g[i] = tr.query(1, find(C - c[i])).mx;
        chkmax(mx, g[i]);
      }
    } else
      s.erase(i);
    lst = x;
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
