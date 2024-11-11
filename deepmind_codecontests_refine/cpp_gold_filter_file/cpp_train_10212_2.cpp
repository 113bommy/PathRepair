#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
template <class T, class U>
using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;
const int INF = 1e9;
int n, m;
V<int> a;
template <class T>
class SegmentTree {
  int n;
  vector<T> data;
  T def;
  function<T(T, T)> operation;
  function<T(T, T)> update;
  T _query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return def;
    if (a <= l && r <= b)
      return data[k];
    else {
      T c1 = _query(a, b, 2 * k + 1, l, (l + r) >> 1);
      T c2 = _query(a, b, 2 * k + 2, (l + r) >> 1, r);
      return operation(c1, c2);
    }
  }

 public:
  SegmentTree(size_t _n, T _def, function<T(T, T)> _operation,
              function<T(T, T)> _update)
      : def(_def), operation(_operation), update(_update) {
    n = 1;
    while (n < _n) n <<= 1;
    data = vector<T>(2 * n - 1, def);
  }
  void change(int i, T x) {
    i += n - 1;
    data[i] = update(data[i], x);
    while (i > 0) {
      i = (i - 1) >> 1;
      data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }
  T query(int a, int b) { return _query(a, b, 0, 0, n); }
  T operator[](int i) { return data[i + n - 1]; }
};
ll count_med(int med) {
  V<int> pm1(n);
  for (int i = 0; i < n; i++) pm1[i] = (a[i] < med ? -1 : 1);
  ll ret = 0;
  int tmp = n;
  SegmentTree<int> seg(
      2 * n + 1, 0, [&](int i, int j) { return i + j; },
      [&](int i, int j) { return i + j; });
  for (int i = 0; i < n; i++) {
    seg.change(tmp, 1);
    tmp += pm1[i];
    ret += seg.query(0, tmp);
  }
  return ret;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << count_med(m) - count_med(m + 1) << '\n';
  return 0;
}
