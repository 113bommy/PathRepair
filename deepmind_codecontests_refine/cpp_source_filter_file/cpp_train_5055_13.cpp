#include <bits/stdc++.h>
const int kN = 200000 + 5;
struct Unit {
  int zero;
  long long sum;
  int len;
  long long v[2];
  void show() const {
    printf("zero = %d, sum = %I64d, len = %d, v[0] = %I64d, v[1] = %I64d\n",
           zero, sum, len, v[0], v[1]);
  }
};
Unit operator+(const Unit &lhs, const Unit &rhs) {
  Unit ret;
  ret.zero = lhs.zero + rhs.zero;
  ret.sum = lhs.sum + ((lhs.len & 1) ? -rhs.sum : rhs.sum);
  ret.len = lhs.len + rhs.len;
  ret.v[0] = lhs.v[0];
  ret.v[1] = lhs.v[1];
  if (lhs.len & 1) {
    ret.v[0] = std::min(ret.v[0], -lhs.sum + rhs.v[1]);
    ret.v[1] = std::min(ret.v[1], lhs.sum + rhs.v[0]);
  } else {
    ret.v[0] = std::min(ret.v[0], -lhs.sum + rhs.v[0]);
    ret.v[1] = std::min(ret.v[1], lhs.sum + rhs.v[1]);
  }
  return ret;
}
struct SegmentTree {
  Unit t[kN << 2];
  long long lazy[kN << 2];
  void apply(Unit &w, long long k) {
    if (k == 0) return;
    w.zero = 0;
    if (w.len & 1) {
      w.sum += k;
    }
    w.v[0] += k;
  }
  void build(const std::vector<int> &A, int l, int r, int rt) {
    if (l == r) {
      int val = A[l];
      t[rt].zero = val == 0;
      t[rt].sum = val - 1;
      t[rt].len = 1;
      t[rt].v[0] = val - 1;
      t[rt].v[1] = static_cast<long long>(1e18);
      return;
    }
    int mid = l + r >> 1;
    build(A, l, mid, rt << 1);
    build(A, mid + 1, r, rt << 1 | 1);
    t[rt] = t[rt << 1] + t[rt << 1 | 1];
  }
  void down(int rt) {
    if (lazy[rt] == 0) return;
    apply(t[rt << 1], lazy[rt]);
    lazy[rt << 1] += lazy[rt];
    apply(t[rt << 1 | 1], lazy[rt]);
    lazy[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
  }
  void modify(int L, int R, int k, int l, int r, int rt) {
    if (L <= l && r <= R) {
      apply(t[rt], k);
      lazy[rt] += k;
      return;
    }
    int mid = l + r >> 1;
    down(rt);
    if (L <= mid) modify(L, R, k, l, mid, rt << 1);
    if (mid < R) modify(L, R, k, mid + 1, r, rt << 1 | 1);
    t[rt] = t[rt << 1] + t[rt << 1 | 1];
  }
  Unit query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
      return t[rt];
    }
    int mid = l + r >> 1;
    down(rt);
    if (L <= mid && mid < R)
      return query(L, R, l, mid, rt << 1) +
             query(L, R, mid + 1, r, rt << 1 | 1);
    else if (L <= mid)
      return query(L, R, l, mid, rt << 1);
    else
      return query(L, R, mid + 1, r, rt << 1 | 1);
  }
} sgt;
bool judge(Unit w) {
  if (w.len == 1) {
    return w.sum <= 1;
  }
  return w.zero == 0 && w.sum == 0 && w.v[0] >= 0 && w.v[1] >= 0;
}
int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
  }
  sgt.build(A, 0, n - 1, 1);
  int q;
  scanf("%d", &q);
  for (int _ = 0; _ < q; ++_) {
    int op, a, b;
    scanf("%d%d%d", &op, &a, &b);
    if (op == 1) {
      int k;
      scanf("%d", &k);
      sgt.modify(a, b, k, 0, n - 1, 1);
    } else {
      printf("%d\n", judge(sgt.query(a, b, 0, n - 1, 1)));
    }
  }
}
