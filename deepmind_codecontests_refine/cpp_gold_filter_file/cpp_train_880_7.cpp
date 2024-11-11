#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
int n, m, K, q;
pair<int, int> p[N];
struct PP {
  int x1, y1, x2, y2, id;
  bool operator<(const PP& a) const { return x2 < a.x2; }
} a[N];
bool pr[N];
struct SegmentTree {
  int node[N << 2];
  void build(int rt, int l, int r) {
    node[rt] = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
  }
  void modify(int rt, int l, int r, int x, int y) {
    if (l == r) {
      node[rt] = y;
      return;
    }
    int mid = l + r >> 1;
    if (x <= mid)
      modify(rt << 1, l, mid, x, y);
    else
      modify(rt << 1 | 1, mid + 1, r, x, y);
    up(rt);
  }
  void up(int rt) { node[rt] = min(node[rt << 1], node[rt << 1 | 1]); }
  int query(int rt, int l, int r, int L, int R) {
    if (L <= l && R >= r) return node[rt];
    int mid = l + r >> 1;
    int ret = 1e9;
    if (L <= mid) ret = min(ret, query(rt << 1, l, mid, L, R));
    if (R > mid) ret = min(ret, query(rt << 1 | 1, mid + 1, r, L, R));
    return ret;
  }
} tree;
void solve() {
  sort(a, a + q);
  sort(p, p + K);
  tree.build(1, 1, m);
  int cr = 0;
  for (int i = 0; i < q; i++) {
    while (cr < K && p[cr].first <= a[i].x2) {
      tree.modify(1, 1, m, p[cr].second, p[cr].first);
      cr++;
    }
    if (tree.query(1, 1, m, a[i].y1, a[i].y2) >= a[i].x1) {
      pr[a[i].id] = 1;
    }
  }
}
int main() {
  int t;
  scanf("%d%d%d%d", &n, &m, &K, &q);
  for (int i = 0; i < K; i++) {
    scanf("%d%d", &p[i].first, &p[i].second);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    a[i].id = i;
  }
  solve();
  for (int i = 0; i < q; i++) {
    swap(a[i].x1, a[i].y1);
    swap(a[i].x2, a[i].y2);
  }
  for (int i = 0; i < K; i++) swap(p[i].first, p[i].second);
  swap(n, m);
  solve();
  for (int i = 0; i < q; i++) puts(pr[i] ? "YES" : "NO");
  return 0;
}
