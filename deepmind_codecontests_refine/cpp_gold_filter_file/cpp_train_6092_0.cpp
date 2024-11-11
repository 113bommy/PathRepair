#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
const int INF = 2000000000;
const ll LLINF = 9000000000000000000;
struct T {
  ld mat[2][2];
  ld dx = 0, dy = 0;
  T() {
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) mat[i][j] = i == j;
  }
  T(const T &o) {
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) mat[i][j] = o.mat[i][j];
    dx = o.dx;
    dy = o.dy;
  }
};
T op(T l, T r) {
  T m;
  m.mat[0][0] = l.mat[0][0] * r.mat[0][0] + l.mat[0][1] * r.mat[1][0];
  m.mat[0][1] = l.mat[0][0] * r.mat[0][1] + l.mat[0][1] * r.mat[1][1];
  m.mat[1][0] = l.mat[1][0] * r.mat[0][0] + l.mat[1][1] * r.mat[1][0];
  m.mat[1][1] = l.mat[1][0] * r.mat[0][1] + l.mat[1][1] * r.mat[1][1];
  m.dx = l.mat[0][0] * r.dx + l.mat[0][1] * r.dy + l.dx;
  m.dy = l.mat[1][0] * r.dx + l.mat[1][1] * r.dy + l.dy;
  return m;
}
T ident;
struct SegmentTree {
  struct Node {
    T val;
    int l, r;
    Node(T _val, int _l, int _r) : val(_val), l(_l), r(_r){};
  };
  int n;
  vector<Node> tree;
  SegmentTree(int p, vector<T> &init) : n(1 << p) {
    tree.assign(2 * n, Node(ident, 0, n - 1));
    for (int j = 1; j < n; ++j) {
      int m = (tree[j].l + tree[j].r) / 2;
      tree[2 * j].l = tree[j].l;
      tree[2 * j].r = m;
      tree[2 * j + 1].l = m + 1;
      tree[2 * j + 1].r = tree[j].r;
    }
    for (int j = 2 * n - 1; j > 0; --j) {
      if (j >= n)
        tree[j].val = init[j - n];
      else
        tree[j].val = op(tree[2 * j].val, tree[2 * j + 1].val);
    }
  }
  void update(int i, T val) {
    for (tree[i + n].val = val, i = (i + n) / 2; i > 0; i /= 2)
      tree[i].val = op(tree[2 * i].val, tree[2 * i + 1].val);
  }
  T query(int l, int r) {
    T lhs, rhs;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lhs = op(lhs, tree[l++].val);
      if (!(r & 1)) rhs = op(tree[r--].val, rhs);
    }
    return op(l == r ? op(lhs, tree[l].val) : lhs, rhs);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int p = 1;
  while ((1 << p) < 2 * n) ++p;
  vector<T> init(1 << p, T());
  for (int i = 0; i < n; ++i) {
    init[2 * i + 1].dx = 1;
  }
  SegmentTree st(p, init);
  vector<ld> curdeg(n, 0.0);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    --y;
    if (x == 1) {
      T cur = st.query(2 * y + 1, 2 * y + 1);
      cur.dx += z;
      st.update(2 * y + 1, cur);
    } else {
      curdeg[y] -= ld(z) / 180.0 * 3.14159265358979323846;
      T m;
      m.mat[0][0] = m.mat[1][1] = cos(curdeg[y]);
      m.mat[1][0] = sin(curdeg[y]);
      m.mat[0][1] = -m.mat[1][0];
      st.update(2 * y, m);
    }
    T f = st.query(0, 2 * n - 1);
    printf("%.7lf %.7lf\n", double(f.dx), double(f.dy));
  }
  return 0;
}
