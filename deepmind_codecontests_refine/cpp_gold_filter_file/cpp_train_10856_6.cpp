#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (int i = 0; i < (((int)(v).size())); ++i) {
    if (i) os << ", ";
    os << v[i];
  }
  return os << "]";
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << "(" << p.first << " " << p.second << ")";
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-9;
template <int m>
struct mint {
  int x;
  mint(int x = 0) : x(((x % m) + m) % m) {}
  mint operator-() { return x ? m - x : 0; }
  mint &operator+=(mint r) {
    if ((x += r.x) >= m) x -= m;
    return *this;
  }
  mint &operator-=(mint r) {
    if ((x -= r.x) < 0) x += m;
    return *this;
  }
  mint &operator*=(mint r) {
    x = ((ll)x * r.x) % m;
    return *this;
  }
  mint inv() {
    int a = x, b = m, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return u;
  }
  mint &operator/=(mint r) { return *this *= r.inv(); }
  friend mint operator+(mint l, mint r) { return l += r; }
  friend mint operator-(mint l, mint r) { return l -= r; }
  friend mint operator*(mint l, mint r) { return l *= r; }
  friend mint operator/(mint l, mint r) { return l /= r; }
  mint pow(ll n) {
    mint ret = 1, tmp = *this;
    while (n) {
      if (n & 1) ret *= tmp;
      tmp *= tmp, n >>= 1;
    }
    return ret;
  }
  friend bool operator==(mint l, mint r) { return l.x == r.x; }
  friend bool operator!=(mint l, mint r) { return l.x != r.x; }
  friend ostream &operator<<(ostream &os, mint a) { return os << a.x; }
  friend istream &operator>>(istream &is, mint &a) {
    int x;
    is >> x;
    a = x;
    return is;
  }
};
template <typename T>
struct Combination {
  int _n = 1;
  vector<T> _fact{1}, _rfact{1};
  void extend(int n) {
    if (n <= _n) return;
    _fact.resize(n);
    _rfact.resize(n);
    for (int i = _n; i < n; ++i) _fact[i] = _fact[i - 1] * i;
    _rfact[n - 1] = 1 / _fact[n - 1];
    for (int i = n - 1; i > _n; --i) _rfact[i - 1] = _rfact[i] * i;
    _n = n;
  }
  T fact(int k) {
    extend(k + 1);
    return _fact.at(k);
  }
  T rfact(int k) {
    extend(k + 1);
    return _rfact.at(k);
  }
  T P(int n, int r) {
    if (r < 0 or n < r) return 0;
    return fact(n) * rfact(n - r);
  }
  T C(int n, int r) {
    if (r < 0 or n < r) return 0;
    return fact(n) * rfact(r) * rfact(n - r);
  }
  T H(int n, int r) { return (n == 0 and r == 0) ? 1 : C(n + r - 1, r); }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  vector<char> type(2 * n);
  vector<int> sh(2 * n, -1);
  for (int i = 0; i < (2 * n); ++i) {
    cin >> type[i];
    if (type[i] == '-') cin >> sh[i], --sh[i];
  }
  vi stock;
  vi top{-INF};
  bool valid = true;
  int cnt = 0;
  vi ans(n);
  for (int i = 0; i < (2 * n); ++i) {
    if (type[i] == '+') {
      stock.emplace_back(cnt++);
      top.emplace_back(-1);
    } else {
      if (stock.empty()) {
        valid = false;
        break;
      }
      if (top.back() > sh[i]) {
        valid = false;
        break;
      }
      ans[stock.back()] = sh[i];
      stock.pop_back();
      top.pop_back();
      if (top.back() != -INF and top.back() < sh[i]) {
        top.pop_back();
        top.push_back(sh[i]);
      }
    }
  }
  if (!valid) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < (n); ++i) {
    if (i) cout << ' ';
    cout << ans[i] + 1;
  }
  cout << endl;
  return 0;
}
