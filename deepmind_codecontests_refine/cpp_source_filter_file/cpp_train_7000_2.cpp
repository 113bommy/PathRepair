#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& t : v) {
    is >> t;
  }
  return is;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < (v.size()); ++i)
    os << v[i] << (i == v.size() - 1 ? "\n" : " ");
  return os;
}
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
const int inf = 1001001001;
const ll linf = 1001001001001001001 * 4;
template <typename T, typename MERGE, typename UPDATE>
class segtree {
  int n;
  vector<T> val;
  T identity;
  MERGE merge;
  UPDATE _update;

 public:
  segtree(int _n, vector<T> init, T identity, MERGE merge, UPDATE update)
      : identity(identity), merge(merge), _update(update) {
    n = 1;
    while (n < _n) n *= 2;
    val = vector<T>(2 * n - 1, identity);
    for (int i = 0; i < (_n); ++i) val[i + n - 1] = init[i];
    for (int i = (n - 1) - 1; i >= 0; i--)
      val[i] = merge(val[i * 2 + 1], val[i * 2 + 2]);
  }
  void update(int i, T x) {
    i += n - 1;
    val[i] = _update(val[i], x);
    while (i > 0) {
      i = (i - 1) / 2;
      val[i] = merge(val[i * 2 + 1], val[i * 2 + 2]);
    }
  }
  T query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) r = n;
    if (b <= l || r <= a) return identity;
    if (a <= l && r <= b) return val[k];
    T t1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
    T t2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return merge(t1, t2);
  }
  T operator[](int i) const { return val[i]; }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a((n + 1) / 2);
  cin >> a;
  ll x;
  cin >> x;
  for (int i = 0; i < (n / 2); ++i) a.push_back(x);
  vector<ll> sum(n + 1, 0);
  for (int i = 0; i < (n); ++i) sum[i + 1] = sum[i] + a[i];
  if (sum[n] > 0) {
    cout << n << endl;
    return 0;
  }
  int sz = (n + 1) / 2;
  auto f = [](ll a, ll b) { return min(a, b); };
  auto g = [](ll a, ll b) { return a; };
  vector<ll> init(sz + 1);
  for (int i = 0; i < (sz + 1); ++i) init[i] = x * i - sum[i];
  segtree<ll, decltype(f), decltype(g)> st(sz + 1, init, linf, f, g);
  for (int k = (sz); k < (n); ++k) {
    if (n - k > sz && x <= 0) continue;
    ll mn = st.query(0, n - k);
    mn += sum[k + 1];
    if (mn > 0) {
      cout << k << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
