#include <bits/stdc++.h>
using namespace std;

// 0-indexed
template <class T, class E>
struct SegmentTreeLaze {
  // a,b:T c,d:E e:E(unit)
  // g(f(a,b),c) = f(g(a,c),g(b,c))
  // g(g(a,c),d) = g(a,h(c,d))
  // g(a,e) = a
  typedef function<T(T, T)> F;
  typedef function<T(T, E)> G;
  typedef function<E(E, E)> H;
  int n, height;
  F f;
  G g;
  H h;
  T tunit;
  E eunit;
  vector<T> dat;
  vector<E> laz;
  SegmentTreeLaze(){};
  SegmentTreeLaze(int newn, F f, G g, H h, T nt, E ne)
      : f(f), g(g), h(h), tunit(nt), eunit(ne) {
    init(newn);
  }
  SegmentTreeLaze(const vector<T> &v, F f, G g, H h, T nt, E ne)
      : f(f), g(g), h(h), tunit(nt), eunit(ne) {
    int _n = v.size();
    init(v.size());
    for (int i = 0; i < _n; ++i) dat[n + i] = v[i];
    for (int i = n - 1; i; --i) dat[i] = f(dat[i << 1], dat[(i << 1) | 1]);
  }
  void init(int newn) {
    n = 1, height = 0;
    while (n < newn) n <<= 1, ++height;
    dat.assign(n << 1, tunit);
    laz.assign(n << 1, eunit);
  }

  inline T reflect(int k) {
    return laz[k] == eunit ? dat[k] : g(dat[k], laz[k]);
  }

  inline void eval(int k) {
    if (laz[k] == eunit) return;
    laz[k << 1] = h(laz[k << 1], laz[k]);
    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = eunit;
  }

  inline void thrust(int k) {
    for (int i = height; i; --i) eval(k >> i);
    // reset query
    // dat[k] = reflect(k);
    // laz[k] = eunit;
  }

  void recalc(int k) {
    while (k >>= 1) dat[k] = f(reflect(k << 1), reflect((k << 1) | 1));
  }
  // [a,b)
  void update(int a, int b, E newdata) {
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] = h(laz[l], newdata), l++;
      if (r & 1) --r, laz[r] = h(laz[r], newdata);
    }
    recalc(a);
    recalc(b);
  }

  void set_val(int k, T newdata) {
    thrust(k += n);
    dat[k] = newdata;
    laz[k] = eunit;
    recalc(k);
  }

  // [a,b)
  T query(int a, int b) {
    thrust(a += n);
    thrust(b += n - 1);
    T vl = tunit, vr = tunit;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f(vl, reflect(l++));
      if (r & 1) vr = f(reflect(--r), vr);
    }
    return f(vl, vr);
  }

  // func(unit) == false
  // min left: st <= res && func(seg.query(res,n))
  template <typename C>
  int find_left(int st, C &func, T acc, int k, int l, int r) {
    if (l + 1 == r) {
      acc = f(acc, reflect(k));
      return func(acc) ? l : -1;
    }
    eval(k);
    int mid = (l + r) >> 1;
    if (mid <= st) return find_left(st, func, acc, (k << 1) | 1, mid, r);
    if (st <= l && !func(f(acc, dat[k]))) {
      acc = f(acc, dat[k]);
      return -1;
    }
    int nres = find_left(st, func, acc, (k << 1), l, mid);
    if (~nres) return nres;
    return find_left(st, func, acc, (k << 1) | 1, mid, r);
  }
  template <typename C>
  int find_left(int st, C &func) {
    T acc = tunit;
    return find_left(st, func, acc, 1, 0, n);
  }

  // max right: res <= st && func(seg.query(0,res))
  template <typename C>
  int find_right(int st, C &func, T acc, int k, int l, int r) {
    if (l + 1 == r) {
      acc = f(reflect(k), acc);
      return func(acc) ? r : -1;
    }
    eval(k);
    int mid = (l + r) >> 1;
    if (st <= mid) return find_right(st, func, acc, k << 1, l, mid);
    if (r <= st && !func(f(dat[k], acc))) {
      acc = f(dat[k], acc);
      return -1;
    }
    int nres = find_right(st, func, acc, (k << 1) | 1, mid, r);
    if (~nres) return nres;
    return find_right(st, func, acc, k << 1, l, mid);
  }
  template <typename C>
  int find_right(int st, C &func) {
    T acc = tunit;
    return find_right(st, func, acc, 1, 0, n);
  }
};
#define fi first
#define se second
#define MOD 998244353
using P = pair<long long, long long>;

long long n, q;
vector<P> v;

int main() {
  cin >> n >> q;
  v.resize(n, {0, 1});
  for (int i = 0; i < n; ++i) cin >> v[i].fi;

  auto f = [](P l, P r) { return make_pair((l.fi + r.fi) % MOD, l.se + r.se); };
  auto g = [](P l, P r) {
    return make_pair((l.fi * r.fi % MOD + l.se * r.se % MOD) % MOD, l.se);
  };
  auto h = [](P l, P r) {
    return make_pair(r.fi * l.fi % MOD, ((r.fi * l.se) % MOD + r.se) % MOD);
  };
  SegmentTreeLaze<P, P> seg(v, f, g, h, {0, 1}, {1, 0});
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t)
      cout << seg.query(l, r).fi << endl;
    else {
      long long b, c;
      cin >> b >> c;
      seg.update(l, r, {b, c});
    }
  }
  return 0;
}
