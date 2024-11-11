#include <bits/stdc++.h>
const int N = 1e5;
int n, m;
inline long long ABS(long long x) { return x < 0 ? -x : x; }
struct SegTree {
  struct Node {
    long long v, lt;
  };
  Node t[(N << 2) + 10];
  inline void pushUp(int i) { t[i].v = t[(i << 1)].v + t[(i << 1 | 1)].v; }
  inline void pushDown(int i, int l, int r) {
    if (t[i].lt) {
      int mid = (l + r) >> 1;
      t[(i << 1)].lt += t[i].lt;
      t[(i << 1 | 1)].lt += t[i].lt;
      t[(i << 1)].v += (mid - l + 1) * t[i].lt;
      t[(i << 1 | 1)].v += (r - mid) * t[i].lt;
      t[i].lt = 0;
    }
  }
  void modify(int i, int l, int r, int ml, int mr, long long v) {
    if (ml <= l && r <= mr) {
      t[i].lt += v;
      t[i].v += (r - l + 1) * v;
      return;
    }
    int mid = (l + r) >> 1;
    pushDown(i, l, r);
    if (ml <= mid) modify((i << 1), l, mid, ml, mr, v);
    if (mr > mid) modify((i << 1 | 1), mid + 1, r, ml, mr, v);
    pushUp(i);
  }
  long long query(int i, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return t[i].v;
    int mid = (l + r) >> 1;
    pushDown(i, l, r);
    long long res = 0;
    if (ql <= mid) res += query((i << 1), l, mid, ql, qr);
    if (qr > mid) res += query((i << 1 | 1), mid + 1, r, ql, qr);
    return res;
  }
} segt;
struct ODT {
  struct Node {
    int l, r;
    mutable int v;
    Node(int _l, int _r = -1, int _v = 0) : l(_l), r(_r), v(_v) {}
    inline bool operator<(const Node& x) const { return l < x.l; }
  };
  std::set<Node> s;
  inline std::set<Node>::iterator split(int pos) {
    std::set<Node>::iterator it = s.lower_bound(Node(pos));
    if (it != s.end() && it->l == pos) return it;
    it--;
    int l = it->l, r = it->r, v = it->v;
    s.erase(it);
    s.insert(Node(l, pos - 1, v));
    return s.insert(Node(pos, r, v)).first;
  }
  inline void assign(int l, int r, int v) {
    std::set<Node>::iterator itr = split(r + 1), itl = split(l);
    for (std::set<Node>::iterator it = itl; it != itr; it++)
      segt.modify(1, 1, n, it->l, it->r, ABS(1LL * v - it->v));
    s.erase(itl, itr);
    s.insert(Node(l, r, v));
  }
} odt;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) odt.s.insert(ODT::Node(i, i, i));
  while (m--) {
    int opt, l, r, v;
    scanf("%d%d%d", &opt, &l, &r);
    if (opt == 1)
      scanf("%d", &v), odt.assign(l, r, v);
    else
      printf("%lld\n", segt.query(1, 1, n, l, r));
  }
  return 0;
}
