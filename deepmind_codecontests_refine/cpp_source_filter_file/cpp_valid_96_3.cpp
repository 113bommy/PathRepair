#include <bits/stdc++.h>
using std::max;
using std::min;
const int maxn = 2e5 + 10;
int n, m, a[maxn];
struct node {
  int len[2], s, e, size;
  long long sum;
};
class Segtree {
 private:
  int bound;
  node data[maxn << 2];
  inline node unite(const node &x, const node &y) {
    node res;
    res.s = x.s, res.e = y.e;
    res.sum = x.sum + y.sum;
    res.size = x.size + y.size;
    if (x.e <= y.s) {
      if (x.len[0] == x.size)
        res.len[0] = x.len[0] + y.len[0];
      else
        res.len[0] = x.len[0];
      if (y.len[1] == y.size)
        res.len[1] = x.len[1] + y.len[1];
      else
        res.len[0] = y.len[1];
      res.sum += 1ll * x.len[1] * y.len[0];
    } else {
      res.len[0] = x.len[0];
      res.len[1] = y.len[1];
    }
    return res;
  }
  inline void pushup(int u) { data[u] = unite(data[u << 1], data[u << 1 | 1]); }
  void build(int s, int e, int u) {
    if (s == e) {
      data[u].s = a[s], data[u].e = a[e];
      data[u].len[0] = 1, data[u].len[1] = 1;
      data[u].size = 1, data[u].sum = 1;
      return;
    }
    int mid = (s + e) >> 1;
    build(s, mid, u << 1), build(mid + 1, e, u << 1 | 1);
    pushup(u);
  }
  void modify(int s, int e, int u, int pos, int key) {
    if (s == e) {
      a[pos] = key;
      data[u].s = key, data[u].e = key;
      return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid)
      modify(s, mid, u << 1, pos, key);
    else
      modify(mid + 1, e, u << 1 | 1, pos, key);
    pushup(u);
  }
  node query(int s, int e, int u, int ql, int qr) {
    if (ql <= s && e <= qr) {
      return data[u];
    }
    int mid = (s + e) >> 1;
    if (ql <= mid && qr > mid) {
      return unite(query(s, mid, u << 1, ql, qr),
                   query(mid + 1, e, u << 1 | 1, ql, qr));
    } else if (ql <= mid)
      return query(s, mid, u << 1, ql, qr);
    return query(mid + 1, e, u << 1 | 1, ql, qr);
  }

 public:
  inline void build(int n) {
    bound = n;
    build(1, bound, 1);
  }
  inline void modify(int pos, int key) { modify(1, bound, 1, pos, key); }
  inline long long query(int ql, int qr) {
    return query(1, bound, 1, ql, qr).sum;
  }
} tree;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  tree.build(n);
  int opt, x, y;
  while (m--) {
    scanf("%d%d%d", &opt, &x, &y);
    if (opt == 1)
      tree.modify(x, y);
    else
      printf("%lld\n", tree.query(x, y));
  }
  return 0;
}
