#include <bits/stdc++.h>
using namespace std;
constexpr int Maxn = 2e5 + 5;
int n, q;
int a[Maxn];
template <typename _Tp>
class range {
 public:
 public:
  range() : l(0), r(0), v(_Tp()) {}
  range(int l, int r, const _Tp &v) : l(l), r(r), v(v) {}
  range(const range &x) : l(x.l), r(x.r), v(x.v) {}
  friend bool operator<(const range &x, const range &y) { return x.l < y.l; }
  inline int left(void) const { return l; }
  inline int right(void) const { return r; }
  inline _Tp value(void) const { return v; }

 private:
  int l, r;
  mutable _Tp v;
};
template <typename _Tp>
class range_tree {
 public:
  typedef
      typename set<range<_Tp>>::const_reverse_iterator const_reverse_iterator;

 private:
  void insert_to(const range<_Tp> &_r);
  void erase_from(const range<_Tp> &_r);

 public:
  range_tree() : T() {}
  range_tree(const range_tree &x) : T(x.T) {}
  void insert(const range<_Tp> &_r) {
    T.insert(_r);
    insert_to(_r);
  }
  void erase(const range<_Tp> &_r) {
    T.erase(_r);
    erase_from(_r);
  }
  typename set<range<_Tp>>::iterator split(int p) {
    auto x = prev(T.upper_bound(range<_Tp>(p, -1, _Tp())));
    if (x->left() == p)
      return x;
    else if (p > x->right())
      return T.end();
    else {
      range<_Tp> t = *x;
      erase(t);
      insert(range<_Tp>(t.left(), p - 1, t.value()));
      insert(range<_Tp>(p, t.right(), t.value()));
      return T.find(range<_Tp>(p, t.right(), t.value()));
    }
  }
  std::pair<typename set<range<_Tp>>::iterator,
            typename set<range<_Tp>>::iterator>
  split_range(int l, int r) {
    auto itr = split(r + 1), itl = split(l);
    return {itl, itr};
  }
  void assign(int l, int r, _Tp v) {
    typename set<range<_Tp>>::iterator itl, itr;
    tie(itl, itr) = split_range(l, r);
    for (typename set<range<_Tp>>::iterator p = itl; p != itr; ++p)
      erase_from(*p);
    T.erase(itl, itr);
    insert(range<_Tp>(l, r, v));
  }

 private:
  std::set<range<_Tp>> T;
};
template <typename _Tp>
class fenwick_tree {
 public:
 private:
  int N;
  std::vector<_Tp> X, Y;
  inline void _M_check(int idx) {
    if (__builtin_expect(idx >= N || idx < 0, false)) {
      throw std::out_of_range("<Fenwick-tree::add> range error");
    }
  }
  inline void _M_check(int l, int r) {
    if (__builtin_expect(l > r || r >= N || l < 0, false)) {
      throw std::out_of_range("<Fenwick-tree::add> range error");
    }
  }
  void _M_add(std::vector<_Tp> &b, int idx, _Tp delta) {
    for (; idx < N; idx = idx | (idx + 1)) b[idx] = b[idx] + delta;
  }
  _Tp _M_sum(std::vector<_Tp> &b, int idx) {
    _Tp ret = 0;
    for (; idx >= 0; idx = (idx & (idx + 1)) - 1) ret = ret + b[idx];
    return ret;
  }

 public:
  fenwick_tree() { clear(); }
  fenwick_tree(int N) { resize(N, 0); }
  fenwick_tree(const fenwick_tree &arr) : N(arr.N), X(arr.X), Y(arr.Y) {}
  fenwick_tree(fenwick_tree &&arr) {
    N = arr.N, arr.N = 0;
    X.swap(arr.X), arr.X.clear();
    Y.swap(arr.Y), arr.Y.clear();
  }
  fenwick_tree(const std::vector<_Tp> &arr) { resize(arr); }
  inline void clear() { resize(0); }
  void resize(int len, _Tp val = _Tp(0)) {
    N = len;
    X.resize(N, _Tp(0));
    Y.resize(N, _Tp(0));
    if (val != _Tp(0)) add(0, N - 1, val);
  }
  void resize(const std::vector<_Tp> &arr) {
    N = (int)arr.size();
    X.resize(N, _Tp(0));
    Y.resize(N, _Tp(0));
    for (int i = 0; i < (int)arr.size(); ++i) add(i, i, arr[i]);
  }
  void add(int l, int r, _Tp val) {
    _M_check(l, r);
    _M_add(X, l, val);
    _M_add(Y, l, val * static_cast<_Tp>(l));
    if (r != N - 1) {
      _M_add(X, r + 1, -val);
      _M_add(Y, r + 1, -val * static_cast<_Tp>(r + 1));
    }
  }
  inline _Tp prefix_sum(int idx) {
    _M_check(idx);
    return _M_sum(X, idx) * static_cast<_Tp>(idx + 1) - _M_sum(Y, idx);
  }
  inline _Tp sum(int l, int r) {
    _M_check(l, r);
    _Tp _ans = prefix_sum(r);
    if (l != 0) _ans = _ans - prefix_sum(l - 1);
    return _ans;
  }
};
fenwick_tree<int64_t> f1(Maxn), f2(Maxn);
inline void modify(int k, int64_t v) {
  f1.add(k, n, -k * v);
  f2.add(k, n, v);
}
inline int64_t query(int k) { return f1.sum(k, k) + f2.sum(k, k) * k; }
set<range<int>> st[Maxn];
template <>
void range_tree<int>::insert_to(const range<int> &x) {
  int l = x.left(), r = x.right(), c = x.value();
  if (!st[c].empty()) {
    modify(st[c].begin()->left(), -1);
    modify(n - st[c].rbegin()->right() + 1, -1);
  }
  st[c].insert(x);
  modify(st[c].begin()->left(), 1);
  modify(n - st[c].rbegin()->right() + 1, 1);
  if (l != r) modify(1, r - l);
  auto it = st[c].find(x);
  if (it != st[c].begin()) modify(l - prev(it)->right(), 1);
  if (next(it) != st[c].end()) modify(next(it)->left() - r, 1);
  if (it != st[c].begin() && next(it) != st[c].end())
    modify(next(it)->left() - prev(it)->right(), -1);
}
template <>
void range_tree<int>::erase_from(const range<int> &x) {
  int l = x.left(), r = x.right(), c = x.value();
  if (l != r) modify(1, -(r - l));
  auto it = st[c].find(x);
  if (it != st[c].begin()) modify(l - prev(it)->right(), -1);
  if (next(it) != st[c].end()) modify(next(it)->left() - r, -1);
  if (it != st[c].begin() && next(it) != st[c].end())
    modify(next(it)->left() - prev(it)->right(), 1);
  modify(n - st[c].rbegin()->right() + 1, -1);
  modify(st[c].begin()->left(), -1);
  st[c].erase(x);
  if (!st[c].empty()) {
    modify(st[c].begin()->left(), 1);
    modify(n - st[c].rbegin()->right() + 1, 1);
  }
}
int64_t calc(int k) {
  int64_t ans = 1LL * k * n;
  ans -= query(k);
  return ans;
}
std::int32_t main(int argc, const char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cout << std::fixed << std::setprecision(12);
  std::cerr << std::boolalpha;
  auto get_id = [&](int x) -> int {
    static std::unordered_map<int, int> mp;
    if (mp.find(x) == mp.end()) mp[x] = (int)mp.size() + 1;
    return mp[x];
  };
  cin >> n >> q;
  range_tree<int> T;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = get_id(a[i]);
    T.insert(range<int>(i, i, a[i]));
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      x = get_id(x);
      T.assign(l, r, x);
    } else {
      int x;
      cin >> x;
      cout << calc(x) << endl;
    }
  }
  std::exit(EXIT_SUCCESS);
}
