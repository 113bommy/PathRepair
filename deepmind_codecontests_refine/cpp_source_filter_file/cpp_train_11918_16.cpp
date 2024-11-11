#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200005;
long long h[MAXN], d[MAXN], pre[MAXN];
struct Node {
  long long a, ma, mi;
} t[MAXN * 4];
inline long long lc(long long p) { return p << 1; }
inline long long rc(long long p) { return p << 1 | 1; }
Node mergeNode(const Node &l, const Node &r) {
  Node n;
  n.a = max(l.a, max(r.a, r.ma - l.mi));
  n.ma = max(l.ma, r.ma);
  n.mi = min(l.mi, r.mi);
  return n;
}
void pushUp(long long p) { t[p] = mergeNode(t[lc(p)], t[rc(p)]); }
void buildTree(long long p, long long l, long long r) {
  if (l == r) {
    t[p].ma = 2 * h[l] + pre[l];
    t[p].mi = -2 * h[l] + pre[l];
    return;
  }
  int mid = (l + r) / 2;
  buildTree(lc(p), l, mid);
  buildTree(rc(p), mid + 1, r);
  pushUp(p);
}
Node query(long long p, long long l, long long r, long long ql, long long qr) {
  if (ql <= l && r <= qr) {
    return t[p];
  }
  int mid = (l + r) / 2;
  Node n;
  bool hasLeft = false;
  if (ql <= mid) {
    n = query(lc(p), l, mid, ql, qr);
    hasLeft = true;
  }
  if (mid < qr) {
    if (hasLeft) {
      n = mergeNode(n, query(rc(p), mid + 1, r, ql, qr));
    } else {
      n = query(rc(p), mid + 1, r, ql, qr);
    }
  }
  return n;
}
int main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld", &d[i]);
    d[i + n] = d[i];
  }
  for (int i = 1; i <= 2 * n; ++i) {
    pre[i] = pre[i - 1] + d[i - 1];
  }
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld", &h[i]);
    h[i + n] = h[i];
  }
  buildTree(1, 1, n * 2);
  while (m--) {
    long long l, r, a, b;
    scanf("%lld%lld", &a, &b);
    if (a <= b) {
      l = b + 1;
      r = a - 1 + n;
    } else {
      l = a + 1;
      r = b - 1;
    }
    Node ans = query(1, 1, n * 2, l, r);
    printf("%lld\n", ans.a);
  }
  return 0;
}
