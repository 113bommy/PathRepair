#include <bits/stdc++.h>
using namespace std;
struct LazySegmentTree {
  int sz;
  long long *tree, *lazy;
  LazySegmentTree(int pre_sz) {
    sz = 1 << (int)ceil(log2(pre_sz));
    tree = new long long[2 * sz];
    lazy = new long long[2 * sz];
    memset(tree, 0, 2 * sz * sizeof(long long));
    memset(lazy, 0, 2 * sz * sizeof(long long));
  }
  void propogateLazy(int idx) {
    tree[2 * idx] += lazy[idx];
    tree[2 * idx + 1] += lazy[idx];
    lazy[2 * idx] += lazy[idx];
    lazy[2 * idx + 1] += lazy[idx];
    lazy[idx] = 0;
  }
  void update(int idx, int s, int e, int l, int r, long long v) {
    if (l == s && r == e) {
      tree[idx] += v;
      lazy[idx] += v;
      return;
    }
    propogateLazy(idx);
    int mid = (s + e) >> 1;
    if (l < mid) update(2 * idx, s, mid, l, min(r, mid), v);
    if (r > mid) update(2 * idx + 1, mid, e, max(l, mid), r, v);
    tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
  }
  void update(int l, int r, long long v) { update(1, 0, sz, l, r, v); }
  long long query(int idx, int s, int e, int l, int r) {
    if (l == s && r == e) return tree[idx];
    propogateLazy(idx);
    int mid = (s + e) >> 1;
    if (l < mid && r > mid)
      return min(query(2 * idx, s, mid, l, min(mid, r)),
                 query(2 * idx + 1, mid, e, max(mid, l), r));
    else if (l < mid)
      return query(2 * idx, s, mid, l, min(mid, r));
    else
      return query(2 * idx + 1, mid, e, max(mid, l), r);
  }
  long long query(int l, int r) { return query(1, 0, sz, l, r); }
};
LazySegmentTree st1(200000), st2(200000);
int n, m, q;
long long currA[200000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 0; i < (n - 1); i++) {
    long long a, b;
    cin >> a >> b;
    st1.update(i, i + 1, a);
    currA[i + 1] = a;
    st2.update(i + 1, i + 2, b);
  }
  vector<tuple<int, int, long long>> v;
  for (int i = 0; i < (m); i++) {
    int x, y;
    long long z;
    cin >> x >> y >> z;
    x--, y--;
    v.push_back(make_tuple(x, y, z));
  }
  sort(v.begin(), v.end());
  int curr = 0;
  for (int i = 0; i < (n); i++) {
    while (curr < m && get<0>(v[curr]) == i) {
      st2.update(0, get<1>(v[curr]) + 1, get<2>(v[curr]));
      curr++;
    }
    st1.update(i, i + 1, st2.query(0, n));
  }
  cout << st1.query(0, n) << endl;
  for (int i = 0; i < (q); i++) {
    int x;
    long long w;
    cin >> x >> w;
    x--;
    st1.update(x, x + 1, w - currA[x]);
    currA[x] = w;
    cout << st1.query(0, n) << endl;
  }
  return 0;
}
