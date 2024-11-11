#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const double eps = 1e-8;
const int INF32 = 0x3f3f3f3f;
const long long INF64 = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const unsigned long long mod2 = 1610612741;
const int N = 1e6 + 5;
const int sz = (1 << 20);
namespace data_struct {
class segment_tree {
 public:
  struct segment_node {
    int l, r, val, ct;
    bool f;
    int tag;
    void update(int x) {
      f = true;
      tag += x;
      val += x;
      ct += x;
    }
  };
  int nn;
  vector<segment_node> node;
  void pushup(int now) {
    node[now].val = max(node[now << 1].val, node[now << 1 | 1].val);
    node[now].ct = min(node[now << 1].ct, node[now << 1 | 1].ct);
  };
  void pushdown(int now) {
    if (node[now].f) {
      node[now << 1].update(node[now].tag);
      node[now << 1 | 1].update(node[now].tag);
      node[now].tag = 0;
      node[now].f = false;
    }
  }
  void build(int s, int t, int now = 1) {
    node[now].l = s, node[now].r = t;
    if (s == t) {
      return;
    }
    build(s, (s + t) >> 1, now << 1);
    build(((s + t) >> 1) + 1, t, now << 1 | 1);
    pushup(now);
  }
  void update(int s, int t, int x, int now = 1) {
    if (s <= node[now].l && t >= node[now].r) {
      node[now].update(x);
      return;
    }
    pushdown(now);
    if (s <= ((node[now].l + node[now].r) >> 1)) update(s, t, x, now << 1);
    if (t > ((node[now].l + node[now].r) >> 1)) update(s, t, x, now << 1 | 1);
    pushup(now);
  }
  int querymx(int s, int t, int now = 1) {
    if (s <= node[now].l && t >= node[now].r) {
      return node[now].val;
    }
    int ret = 0;
    pushdown(now);
    if (s <= ((node[now].l + node[now].r) >> 1)) {
      ret = querymx(s, t, now << 1);
    }
    if (t > ((node[now].l + node[now].r) >> 1)) {
      ret = max(ret, querymx(s, t, now << 1 | 1));
    }
    return ret;
  }
  int querymi(int s, int t, int now = 1) {
    if (s <= node[now].l && t >= node[now].r) {
      return node[now].val;
    }
    int ret = INF32;
    pushdown(now);
    if (s <= ((node[now].l + node[now].r) >> 1)) {
      ret = querymi(s, t, now << 1);
    }
    if (t > ((node[now].l + node[now].r) >> 1)) {
      ret = min(ret, querymx(s, t, now << 1 | 1));
    }
    return ret;
  }
  explicit segment_tree(int nnn) {
    nn = nnn;
    node.resize(nn << 2 | 3);
    build(1, nn);
  }
};
}  // namespace data_struct
using namespace data_struct;
int state[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  segment_tree tree(n);
  char op;
  for (int i = 0, idx = 1; i < n; ++i) {
    cin >> op;
    if (op == 'L') {
      idx = max(--idx, 1);
    } else if (op == 'R')
      ++idx;
    else {
      if (state[idx] == '(')
        tree.update(idx, n, -1);
      else if (state[idx] == ')')
        tree.update(idx, n, 1);
      if (op == '(') {
        tree.update(idx, n, 1);
      } else if (op == ')')
        tree.update(idx, n, -1);
      state[idx] = op;
    }
    if (tree.node[1].ct < 0 || tree.querymx(n, n) != 0)
      cout << -1 << ' ';
    else
      cout << tree.node[1].val << ' ';
  }
  cout << '\n';
  return 0;
}
