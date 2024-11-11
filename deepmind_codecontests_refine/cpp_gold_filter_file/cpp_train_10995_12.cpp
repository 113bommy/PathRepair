#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U>
using P = pair<T, U>;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vec<T>>;
template <typename Monoid, typename F>
class SegmentTree {
 private:
  int sz;
  vector<Monoid> seg;
  const F op;
  const Monoid e;

 public:
  SegmentTree(int n, const F op, const Monoid &e) : op(op), e(e) {
    sz = 1;
    while (sz <= n) sz <<= 1;
    seg.assign(2 * sz, e);
  }
  void set(int k, const Monoid &x) { seg[k + sz] = x; }
  void build() {
    for (int i = sz - 1; i > 0; i--) {
      seg[i] = op(seg[2 * i], seg[2 * i + 1]);
    }
  }
  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1) {
      seg[k] = op(seg[2 * k], seg[2 * k + 1]);
    }
  }
  Monoid query(int l, int r) {
    Monoid L = e, R = e;
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = op(L, seg[l++]);
      if (r & 1) R = op(seg[--r], R);
    }
    return op(L, R);
  }
  Monoid operator[](const int &k) const { return seg[k + sz]; }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vec<P<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] = {a, i};
  }
  sort(A.begin(), A.end(), greater<P<int, int>>());
  struct state {
    int ma, id;
  };
  auto op = [](state &L, state &R) { return (L.ma > R.ma ? L : R); };
  SegmentTree<state, decltype(op)> seg(N, op, (state){-2, -1});
  for (int i = 0; i < N - 1; i++) {
    seg.set(i, (state){A[i].first - A[i + 1].first, i});
  }
  seg.set(N - 1, (state){A[N - 1].first, N - 1});
  seg.build();
  vec<int> ma(3, -1), B(3, -1);
  for (int a = 1; a < N; a++)
    for (int b = a + 1; b < N; b++)
      if (a <= 2 * (b - a) && (b - a) <= 2 * a) {
        int cmin = (max(a, b - a) + 1) / 2, cmax = 2 * min(a, b - a);
        cmin = max(1, cmin), cmax = min(cmax, N - b);
        if (cmax < cmin) continue;
        state res = seg.query(b - 1 + cmin, b + cmax);
        if (res.id == -1) continue;
        vec<int> now = {A[a - 1].first - A[a].first,
                        A[b - 1].first - A[b].first, res.ma};
        if (ma < now) {
          ma = now;
          B[0] = a, B[1] = b, B[2] = res.id + 1;
        }
      }
  vec<int> ans(N, -1);
  for (int i = 0; i < N; i++) {
    if (i < B[0])
      ans[A[i].second] = 1;
    else if (i < B[1])
      ans[A[i].second] = 2;
    else if (i < B[2])
      ans[A[i].second] = 3;
  }
  for (int i = 0; i < N; i++) cout << ans[i] << (i != N - 1 ? " " : "\n");
}
