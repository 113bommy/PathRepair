#include <bits/stdc++.h>
namespace lib {
const double pi = acos(-1);
using namespace std;
class fastio {
 private:
  char _num[111], _ch;
  int _f, _head;
  bool _useSTD;

 public:
  fastio() { _f = 0, _head = 0, _useSTD = 0, SUF = _ch = ' '; }
  char SUF;
  inline void ioSTD() {
    _useSTD = 1;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
  }
  inline void gc(char& _c) {
    if (_useSTD)
      cin >> _c;
    else
      _c = getchar();
  }
  inline void pc(char _c) {
    if (_useSTD)
      cout << _c;
    else
      putchar(_c);
  }
  template <typename _T>
  inline fastio& operator-(_T& _x) {
    if (_useSTD)
      cin >> _x;
    else {
      _x = 0;
      while (!isdigit(_ch)) _f |= _ch == '-', gc(_ch);
      while (isdigit(_ch)) _x = (_x << 1) + (_x << 3) + (_ch ^ 48), gc(_ch);
      _f && (_x = -_x, _f = 0);
    }
    return *this;
  }
  template <typename _T>
  inline fastio& operator+(_T _x) {
    if (_useSTD)
      cout << _x << SUF;
    else {
      _T _k;
      if (_x == 0) {
        pc('0'), pc(SUF);
        return *this;
      }
      if (_x < 0) pc('-'), _x = -_x;
      while (_x > 0)
        _k = _x / 10, ++_head, _num[_head] = (_x - (_k << 1) - (_k << 3)) ^ 48,
        _x = _k;
      while (_head > 0) pc(_num[_head]), --_head;
      pc(SUF);
    }
    return *this;
  }
  template <typename _T>
  inline fastio& operator>>(_T& _x) {
    cin >> _x;
    return *this;
  }
  template <typename _T>
  inline fastio& operator<<(_T _x) {
    cout << _x;
    return *this;
  }
} io;
inline void fileio(string _r, string _w) {
  if (_r[0] != '-') freopen(_r.c_str(), "r", stdin);
  if (_w[0] != '-') freopen(_w.c_str(), "w", stdout);
}
}  // namespace lib
using namespace lib;
namespace cla {
template <typename Tp_, typename Compare_ = less<Tp_> >
class monotone_queue {
 private:
  class Tnode_ {
   public:
    unsigned long long num_;
    Tp_ value_;
  } t_;
  deque<Tnode_> dq_;
  Compare_ cmp_;
  unsigned long long front_, back_;

 public:
  monotone_queue() {
    dq_.empty();
    front_ = 1;
    back_ = 0;
  }
  inline bool push(Tp_ node_) {
    t_.num_ = ++back_;
    t_.value_ = node_;
    while (!dq_.empty() && cmp_(node_, dq_.back().value_)) dq_.pop_back();
    dq_.push_back(t_);
    return false;
  }
  inline bool pop() {
    ++front_;
    while (!dq_.empty() && dq_.front().num_ < front_) dq_.pop_front();
    return false;
  }
  Tp_ query() { return dq_.front().value_; }
  inline void clear() {
    dq_.empty();
    front_ = 1;
    back_ = 0;
  }
};
template <int Size_>
class PSU {
 private:
  int fa_[Size_ + 1];

 public:
  PSU() {
    for (register int i = 1; i <= Size_; ++i) fa_[i] = i;
  }
  inline int find(int i) {
    while (i != fa_[i]) i = fa_[i] = fa_[fa_[i]];
    return i;
  }
  inline void merge(int x, int y) { fa_[find(x)] = find(y); }
  inline bool query(int x, int y) { return find(x) == find(y); }
  inline void clear() {
    for (register int i = 1; i <= Size_; ++i) fa_[i] = i;
  }
};
template <int Size_>
class BIT {
 private:
  long long val_[Size_ + 1];
  inline int lowbit(int x) { return x & -x; }

 public:
  BIT() { memset(val_, 0, sizeof(val_)); }
  inline long long query(int x) {
    long long res = 0;
    while (x > 0) res += val_[x], x -= lowbit(x);
    return res;
  }
  inline long long query(int x, int y) {
    if (x > y) swap(x, y);
    return query(y) - query(x - 1);
  }
  inline void update(int x, int y) {
    while (x <= Size_) val_[x] += y, x += lowbit(x);
  }
  inline void clear() { memset(val_, 0, sizeof(val_)); }
};
}  // namespace cla
const int maxn = 7004;
const int mod = 998244353, inf = 1000000007;
cla::monotone_queue<int> mq;
int a[maxn], b[maxn];
signed main() {
  io.SUF = '\n';
  int t, n, m, k, ans;
  io - t;
  for (; t; --t) {
    memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
    io - n - m - k;
    k = min(m - 1, k);
    for (register int i = 1; i <= n; ++i) io - a[i];
    for (register int i = 1; i <= m; ++i) b[i] = max(a[i], a[i + n - m]);
    ans = 0;
    for (register int i = 1; i < m - k; ++i) mq.push(b[i]);
    for (register int i = m - k; i <= m; ++i) {
      mq.push(b[i]);
      ans = max(ans, mq.query());
      mq.pop();
    }
    mq.clear();
    io + ans;
  }
  return 0;
}
