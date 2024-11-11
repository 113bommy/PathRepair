#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < (((int)(v).size())); ++i) {
    if (i) os << " ";
    os << v[i];
  }
  return os;
}
template <class T>
void debug(const vector<T> &v) {
  cout << "[";
  for (int i = 0; i < (((int)(v).size())); ++i) {
    if (i) cout << ", ";
    cout << v[i];
  }
  cout << "]" << endl;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << " " << p.second;
}
template <class T, class U>
void debug(const pair<T, U> &p) {
  cout << "(" << p.first << " " << p.second << ")" << endl;
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
const ll MOD998 = 998244353;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const int inf = INT_MIN;
const ll linf = LLONG_MIN;
const ld eps = 1e-9;
template <int m>
struct mint {
  int x;
  mint(ll x = 0) : x(((x % m) + m) % m) {}
  mint operator-() const { return x ? m - x : 0; }
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
  mint inv() const { return pow(m - 2); }
  mint &operator/=(mint r) { return *this *= r.inv(); }
  friend mint operator+(mint l, mint r) { return l += r; }
  friend mint operator-(mint l, mint r) { return l -= r; }
  friend mint operator*(mint l, mint r) { return l *= r; }
  friend mint operator/(mint l, mint r) { return l /= r; }
  mint pow(ll n) const {
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
    ll x;
    is >> x;
    a = x;
    return is;
  }
};
using Int = mint<MOD>;
struct Rectangle {
  int l, r, u, d;
};
bool lessx(const Rectangle &r1, const Rectangle &r2) { return r1.l < r2.l; }
bool lessy(const Rectangle &r1, const Rectangle &r2) { return r1.u < r2.u; }
bool solve(vector<Rectangle> v) {
  if (((int)(v).size()) == 1) return true;
  sort((v).begin(), (v).end(), lessx);
  int mar = v[0].r;
  for (int i = (1); i < (((int)(v).size())); ++i) {
    if (mar <= v[i].l) {
      vector<Rectangle> nxt1(v.begin(), v.begin() + i);
      vector<Rectangle> nxt2(v.begin() + i, v.end());
      return solve(nxt1) && solve(nxt2);
    } else {
      mar = max(mar, v[i].r);
    }
  }
  sort((v).begin(), (v).end(), lessy);
  int mad = v[0].d;
  for (int i = (1); i < (((int)(v).size())); ++i) {
    if (mad <= v[i].u) {
      vector<Rectangle> nxt1(v.begin(), v.begin() + i);
      vector<Rectangle> nxt2(v.begin() + i, v.end());
      return solve(nxt1) && solve(nxt2);
    } else {
      mad = max(mad, v[i].d);
    }
  }
  return false;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  vector<Rectangle> v(n);
  for (int i = 0; i < (n); ++i) {
    Rectangle tmp;
    cin >> tmp.l >> tmp.u >> tmp.r >> tmp.d;
    v.emplace_back(tmp);
  }
  bool ans = solve(v);
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}
