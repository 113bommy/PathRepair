#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 1e5 + 500;
const int mod = 1e9 + 7;
struct matrix {
  int r, c, ele[2][2];
  void init(int r_, int c_) {
    r = r_, c = c_;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < 2; ++j) ele[i][j] = 0;
  }
  void clear() { ele[0][0] = ele[1][1] = 1, ele[0][1] = ele[1][0] = 0; }
  friend ostream& operator<<(ostream& os, const matrix& s) {
    for (int i = 0; i < s.r; ++i) {
      for (int j = 0; j < s.c; ++j) os << s.ele[i][j] << " ";
      os << endl;
    }
    return os;
  }
};
matrix mul(const matrix& a, const matrix& b) {
  matrix rs;
  rs.init(a.r, b.c);
  for (int i = 0; i < a.r; ++i)
    for (int j = 0; j < b.c; ++j) {
      long long ret = 0;
      for (int k = 0; k < a.c; ++k) ret += 1LL * a.ele[i][k] * b.ele[k][j];
      if (ret >= mod) ret -= mod;
      rs.ele[i][j] = ret;
    }
  return rs;
}
matrix power(matrix a, int n) {
  matrix rs;
  rs.init(a.r, a.c);
  rs.clear();
  while (n) {
    if (n & 1) rs = mul(rs, a);
    n >>= 1;
    a = mul(a, a);
  }
  return rs;
}
matrix add(const matrix& a, const matrix& b) {
  matrix rs;
  rs.init(a.r, a.c);
  for (int i = 0; i < a.r; ++i)
    for (int j = 0; j < a.c; ++j) {
      rs.ele[i][j] = a.ele[i][j] + b.ele[i][j];
      if (rs.ele[i][j] >= mod) rs.ele[i][j] -= mod;
    }
  return rs;
}
matrix Upd, base;
int a[maxn], n, m;
struct Sgtree {
  struct node {
    int l, r, opr;
    matrix rs, lazy;
    void Update(const matrix& s) {
      opr = 1;
      rs = mul(rs, s);
      lazy = mul(lazy, s);
    }
  } tree[maxn << 2];
  void PushDown(int o) {
    if (tree[o].opr) {
      tree[o].opr = 0;
      tree[o << 1].Update(tree[o].lazy);
      tree[o << 1 | 1].Update(tree[o].lazy);
      tree[o].lazy.clear();
    }
  }
  void PushUp(int o) { tree[o].rs = add(tree[o << 1].rs, tree[o << 1 | 1].rs); }
  void Build(int l, int r, int o) {
    tree[o].l = l, tree[o].r = r, tree[o].rs.init(2, 2),
    tree[o].lazy.init(2, 2);
    tree[o].lazy.clear();
    if (r > l) {
      int mid = l + r >> 1;
      Build(l, mid, o << 1);
      Build(mid + 1, r, o << 1 | 1);
      PushUp(o);
    } else
      tree[o].rs = power(base, a[l]);
  }
  void Update(int ql, int qr, int o) {
    int l = tree[o].l, r = tree[o].r;
    if (ql <= l && r <= qr)
      tree[o].Update(Upd);
    else {
      int mid = l + r >> 1;
      PushDown(o);
      if (ql <= mid) Update(ql, qr, o << 1);
      if (qr > mid) Update(ql, qr, o << 1 | 1);
      PushUp(o);
    }
  }
  matrix ask(int ql, int qr, int o) {
    int l = tree[o].l, r = tree[o].r;
    if (ql <= l && r <= qr)
      return tree[o].rs;
    else {
      int mid = l + r >> 1;
      PushDown(o);
      matrix ret;
      ret.init(2, 2);
      if (ql <= mid) {
        matrix ls = ask(ql, qr, o << 1);
        ret = add(ret, ls);
      }
      if (qr > mid) {
        matrix rs = ask(ql, qr, o << 1 | 1);
        ret = add(ret, rs);
      }
      PushUp(o);
      return ret;
    }
  }
} Sgtree;
int main(int argc, char* argv[]) {
  base.init(2, 2);
  base.ele[0][1] = base.ele[1][0] = base.ele[1][1] = 1;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  Sgtree.Build(1, n, 1);
  while (m--) {
    int op = read(), l = read(), r = read(), x;
    if (op == 1) {
      x = read();
      Upd.init(2, 2);
      Upd.ele[0][1] = Upd.ele[1][0] = Upd.ele[1][1] = 1;
      Upd = power(Upd, x);
      Sgtree.Update(l, r, 1);
    } else {
      matrix ret = Sgtree.ask(l, r, 1);
      printf("%d\n", ret.ele[1][0]);
    }
  }
  return 0;
}
