#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
struct node {
  int prefix_bit;
  int prefix_bit_cnt;
  int prefix_total_cnt;
  int suffix_bit;
  int suffix_bit_cnt;
  int suffix_total_cnt;
  int node_cnt;
  int node_rcnt;
  int len;
  node(int x)
      : prefix_bit(x),
        prefix_bit_cnt(1),
        prefix_total_cnt(1),
        suffix_bit(x),
        suffix_bit_cnt(1),
        suffix_total_cnt(1),
        node_cnt(1),
        node_rcnt(1),
        len(1){};
  node()
      : prefix_bit(-1),
        prefix_bit_cnt(0),
        prefix_total_cnt(0),
        suffix_bit(-1),
        suffix_bit_cnt(0),
        suffix_total_cnt(0),
        node_cnt(0),
        node_rcnt(1),
        len(0){};
};
void setnode(node &t, int v) {
  t.prefix_bit = v;
  t.prefix_bit_cnt = 1;
  t.prefix_total_cnt = 1;
  t.suffix_bit = v;
  t.suffix_bit_cnt = 1;
  t.suffix_total_cnt = 1;
  t.node_cnt = 1;
  t.node_rcnt = 1;
  t.len = 1;
}
void flip(node &t) {
  t.prefix_bit = 1 - t.prefix_bit;
  t.suffix_bit = 1 - t.suffix_bit;
  swap(t.node_cnt, t.node_rcnt);
}
void combine(node &t, node a, node b) {
  t.node_rcnt = 0;
  t.node_cnt = 0;
  if (a.suffix_bit == 1 && b.prefix_bit == 0) {
    t.node_rcnt = a.suffix_bit_cnt + b.prefix_bit_cnt;
  }
  if (a.suffix_bit == 0 && b.prefix_bit == 1) {
    t.node_cnt = a.suffix_bit_cnt + b.prefix_bit_cnt;
  }
  if (a.suffix_bit == 0 && b.prefix_bit == 0) {
    t.node_rcnt = a.suffix_total_cnt + b.prefix_bit_cnt;
    t.node_cnt = a.suffix_bit_cnt + b.prefix_total_cnt;
  }
  if (a.suffix_bit == 1 && b.prefix_bit == 1) {
    t.node_cnt = a.suffix_total_cnt + b.prefix_bit_cnt;
    t.node_rcnt = a.suffix_bit_cnt + b.prefix_total_cnt;
  }
  t.node_cnt = max(t.node_cnt, a.node_cnt);
  t.node_cnt = max(t.node_cnt, b.node_cnt);
  t.node_rcnt = max(t.node_rcnt, a.node_rcnt);
  t.node_rcnt = max(t.node_rcnt, b.node_rcnt);
  t.prefix_bit = a.prefix_bit;
  t.prefix_bit_cnt = a.prefix_bit_cnt;
  t.prefix_total_cnt = a.prefix_total_cnt;
  if (a.prefix_bit_cnt == a.len && a.prefix_bit == b.prefix_bit) {
    t.prefix_bit_cnt += b.prefix_bit_cnt;
    t.prefix_total_cnt += b.prefix_total_cnt;
  } else if (a.prefix_total_cnt == a.len && a.prefix_bit != b.prefix_bit) {
    t.prefix_total_cnt += b.prefix_total_cnt;
  }
  t.suffix_bit = b.suffix_bit;
  t.suffix_bit_cnt = b.suffix_bit_cnt;
  t.suffix_total_cnt = b.suffix_total_cnt;
  if (b.suffix_bit_cnt == b.len && b.suffix_bit == a.suffix_bit) {
    t.suffix_bit_cnt += a.suffix_bit_cnt;
    t.suffix_total_cnt += a.suffix_total_cnt;
  } else if (b.suffix_total_cnt == b.len && b.suffix_bit != a.suffix_bit) {
    t.suffix_total_cnt += a.suffix_total_cnt;
  }
  t.len = a.len + b.len;
  if (t.prefix_bit_cnt == t.len) t.node_cnt = t.node_rcnt = t.prefix_bit_cnt;
  if (t.suffix_bit_cnt == t.len) t.node_cnt = t.node_rcnt = t.suffix_bit_cnt;
  if (t.prefix_bit == 0)
    t.node_cnt = max(t.node_cnt, t.prefix_total_cnt);
  else
    t.node_rcnt = max(t.node_rcnt, t.prefix_total_cnt);
  if (t.suffix_bit == 1)
    t.node_cnt = max(t.node_cnt, t.suffix_total_cnt);
  else
    t.node_rcnt = max(t.node_rcnt, t.suffix_total_cnt);
}
const int MAXN = 1e6 + 5;
node t[4 * MAXN];
int lazy[4 * MAXN];
void push(int v) {
  if (lazy[v]) {
    flip(t[v * 2]);
    flip(t[v * 2 + 1]);
    lazy[v * 2] = 1 - lazy[v * 2];
    lazy[v * 2 + 1] = 1 - lazy[v * 2 + 1];
  }
  lazy[v] = 0;
}
void build(vector<int> &a, int v, int tl, int tr) {
  if (tl == tr) {
    setnode(t[v], a[tl]);
  } else {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    combine(t[v], t[v * 2], t[v * 2 + 1]);
  }
}
node query(int v, int tl, int tr, int l, int r) {
  if (l > r) return node();
  if (l == tl && r == tr) {
    return t[v];
  }
  push(v);
  int tm = (tl + tr) / 2;
  node x;
  combine(x, query(v * 2, tl, tm, l, min(r, tm)),
          query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  return x;
}
void update(int v, int tl, int tr, int l, int r) {
  if (l > r) return;
  if (l == tl && tr == r) {
    flip(t[v]);
    lazy[v] = 1 - lazy[v];
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm));
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    combine(t[v], t[v * 2], t[v * 2 + 1]);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  for (int tc = 1; tc <= T; tc++) {
    int N, q;
    cin >> N >> q;
    string s;
    cin >> s;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) arr[i] = s[i] == '<' ? 1 : 0;
    build(arr, 1, 0, N - 1);
    memset(lazy, 0, sizeof(lazy));
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      update(1, 0, N - 1, l, r);
      node ret = query(1, 0, N - 1, l, r);
      int ans = ret.node_cnt;
      cout << ans << "\n";
    }
  }
  return 0;
}
