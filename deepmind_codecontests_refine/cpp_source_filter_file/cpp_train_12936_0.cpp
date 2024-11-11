#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vec<T>>;
template <class T>
class Compress {
  int N;
  map<T, int> idx;
  map<int, T> value;
  vec<T> v;
  vec<T> cmp;

 public:
  Compress() {}
  void add(T x) { v.push_back(x); }
  void build() {
    for (auto &x : v) cmp.push_back(x);
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    N = cmp.size();
    for (int i = 0; i < N; i++) idx[cmp[i]] = i;
  }
  int id(T val) { return idx[val]; }
  T val(int id) { return cmp[id]; }
  int size() { return N; }
};
template <typename Monoid, typename OperatorMonoid, typename F, typename G,
          typename H>
class LazySegmentTree {
 private:
  int sz, height;
  vec<Monoid> data;
  vec<OperatorMonoid> lazy;
  const F op;
  const G homo;
  const H comp;
  const Monoid e;
  const OperatorMonoid Oe;

 public:
  LazySegmentTree(int n, const F op, const G homo, const H comp,
                  const Monoid &e, const OperatorMonoid Oe)
      : op(op), homo(homo), comp(comp), e(e), Oe(Oe) {
    sz = 1;
    height = 0;
    while (sz <= n) sz <<= 1, height++;
    data.assign(2 * sz, e);
    lazy.assign(2 * sz, Oe);
  }
  void set(int k, const Monoid &x) { data[k + sz] = x; }
  void build() {
    for (int k = sz - 1; k > 0; k--) {
      data[k] = op(data[2 * k], data[2 * k + 1]);
    }
  }
  inline void propagate(int k) {
    if (lazy[k] != Oe) {
      lazy[2 * k] = comp(lazy[2 * k], lazy[k]);
      lazy[2 * k + 1] = comp(lazy[2 * k + 1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = Oe;
    }
  }
  inline Monoid reflect(int k) {
    return lazy[k] == Oe ? data[k] : homo(data[k], lazy[k]);
  }
  inline void recalc(int k) {
    while (k >>= 1) data[k] = op(reflect(2 * k), reflect(2 * k + 1));
  }
  inline void thrust(int k) {
    for (int i = height; i > 0; i--) propagate(k >> i);
  }
  void update(int a, int b, const OperatorMonoid &x) {
    thrust(a += sz);
    thrust(b += sz - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lazy[l] = comp(lazy[l], x), ++l;
      if (r & 1) --r, lazy[r] = comp(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }
  Monoid query(int a, int b) {
    thrust(a += sz);
    thrust(b += sz - 1);
    Monoid L = e, R = e;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = op(L, reflect(l++));
      if (r & 1) R = op(reflect(--r), R);
    }
    return op(L, R);
  }
  Monoid operator[](const int &k) { return query(k, k + 1); }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  Compress<int> cmp;
  cmp.add(0);
  vec<int> L(N), R(N), T(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i] >> R[i] >> T[i];
    T[i]--;
    cmp.add(L[i]);
    cmp.add(R[i]);
  }
  cmp.build();
  int M = cmp.size();
  auto op = [](int a, int b) { return max(a, b); };
  auto func = [](int a, int b) { return a + b; };
  auto comp = func;
  LazySegmentTree<int, int, decltype(op), decltype(func), decltype(comp)> seg(
      M, op, func, comp, 0, 0);
  vec<LazySegmentTree<int, int, decltype(op), decltype(func), decltype(comp)>>
      segs;
  for (int i = 0; i < 2; i++) segs.push_back(seg);
  vec<int> idx(N);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int i, int j) {
    return (R[i] != R[j] ? R[i] < R[j] : L[i] < L[j]);
  });
  for (auto &id : idx) {
    int l = cmp.id(L[id]);
    int r = cmp.id(R[id]);
    int val = segs[1 - T[id]].query(0, l) + 1;
    if (val > segs[T[id]][r]) {
      segs[T[id]].update(r, r + 1, -seg[r]);
      segs[T[id]].update(r, r + 1, val);
    }
    segs[1 - T[id]].update(0, l, 1);
  }
  int ans = 0;
  for (int i = 0; i < 2; i++) ans = max(ans, segs[i].query(0, M));
  cout << ans << "\n";
}
