#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
struct Node {
  long long cnt, mnv0, mnv1, sum;
  Node() {
    cnt = sum = 0;
    mnv0 = mnv1 = 1e18;
  }
  inline void init(int v) {
    sum = v;
    cnt = 1;
    mnv0 = 1e18;
    mnv1 = v;
  }
  inline void addit(int v) {
    sum += (cnt & 1) * v;
    mnv1 += v;
  }
  inline bool check() { return mnv1 >= 1 && mnv0 >= 0 && sum == (cnt & 1); }
};
inline Node Merge(Node l, Node r) {
  Node ans;
  ans.cnt = l.cnt + r.cnt;
  ans.sum = r.sum;
  if (r.cnt & 1)
    ans.sum -= l.sum;
  else
    ans.sum += l.sum;
  if (l.cnt & 1)
    ans.mnv1 = min(l.mnv1, r.mnv0 + l.sum),
    ans.mnv0 = min(l.mnv0, r.mnv1 - l.sum);
  else
    ans.mnv1 = min(l.mnv1, r.mnv1 - l.sum),
    ans.mnv0 = min(l.mnv0, r.mnv0 + l.sum);
  return ans;
}
int a[maxn], n, q;
struct Segment_tree {
  Node v[maxn << 2];
  int addv[maxn << 2];
  inline void pushup(int p) { v[p] = Merge(v[(p << 1)], v[(p << 1 | 1)]); }
  inline void setadd(int p, int val) {
    addv[p] += val;
    v[p].addit(val);
  }
  inline void pushdown(int p) {
    if (addv[p])
      setadd((p << 1), addv[p]), setadd((p << 1 | 1), addv[p]), addv[p] = 0;
  }
  inline void build(int p, int l, int r) {
    if (l == r) return (void)(v[p].init(a[l]));
    int mid = (l + r) >> 1;
    build((p << 1), l, mid);
    build((p << 1 | 1), mid + 1, r);
    pushup(p);
  }
  inline void Add(int p, int l, int r, int ql, int qr, int v) {
    if (ql <= l && qr >= r) return (void)setadd(p, v);
    int mid = (l + r) >> 1;
    pushdown(p);
    if (ql <= mid) Add((p << 1), l, mid, ql, qr, v);
    if (qr > mid) Add((p << 1 | 1), mid + 1, r, ql, qr, v);
    pushup(p);
  }
  inline Node Query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) return v[p];
    int mid = (l + r) >> 1;
    pushdown(p);
    if (qr <= mid) return Query((p << 1), l, mid, ql, qr);
    if (ql > mid) return Query((p << 1 | 1), mid + 1, r, ql, qr);
    return Merge(Query((p << 1), l, mid, ql, qr),
                 Query((p << 1 | 1), mid + 1, r, ql, qr));
  }
} seg;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  seg.build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    int opt, l, r, v;
    scanf("%d%d%d", &opt, &l, &r);
    l++, r++;
    if (opt == 1)
      scanf("%d", &v), seg.Add(1, 1, n, l, r, v);
    else
      puts(seg.Query(1, 1, n, l, r).check() ? "Yes" : "No");
  }
  return 0;
}
