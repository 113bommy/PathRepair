#include <bits/stdc++.h>
#pragma GCC optimize("Ofast, unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrnd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
template <typename T1, typename T2>
bool relax(T1& a, const T2& b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
bool strain(T1& a, const T2& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
using gint = ld;
const gint EPS = 1e-7;
struct vec {
  gint x, y;
  vec() : x(0), y(0) {}
  vec(gint a, gint b) : x(a), y(b) {}
  vec(const vec& a) : x(a.x), y(a.y) {}
  vec operator+(const vec& a) { return vec(x + a.x, y + a.y); }
  vec operator-(const vec& a) { return vec(x - a.x, y - a.y); }
  gint operator*(const vec& a) { return a.x * x + y * a.y; }
  gint operator^(const vec& a) { return x * a.y - a.x * y; }
  vec operator*(gint a) { return vec(x * a, y * a); }
  vec operator/(gint a) { return vec(x / a, y / a); }
  gint qlen() { return (*this) * (*this); }
  gint len() { return sqrtl(qlen()); }
  void print() { cerr << x << ' ' << y << '\n'; }
  void read() { cin >> x >> y; }
};
int sign(gint x) {
  if (x > EPS) return 1;
  if (x < -EPS) return -1;
  return 0;
}
gint check(vec a, vec b, vec p) {
  vec ab = b - a, ba = a - b, ap = p - a, bp = p - b;
  if (ab * ap < 0 || ba * bp < 0)
    return min(ap.qlen(), bp.qlen());
  else
    return (((ab ^ ap)) * ((ab ^ ap))) / ab.qlen();
}
void solve() {
  int n, m;
  cin >> n;
  vec sum;
  vector<vec> gens(n);
  for (int i = 0; i < n; ++i) gens[i].read(), sum = sum + gens[i];
  sum = sum / n;
  cin >> m;
  vector<vec> conv(m + 1);
  for (int i = 0; i < m; ++i) conv[i].read();
  conv[m] = conv[0];
  cout.precision(12);
  cout << fixed;
  ld ans = 0;
  for (int i = 0; i < n; ++i) ans += (gens[i] - sum).qlen();
  for (int i = 0; i < m; ++i) {
    vec ab = conv[i + 1] - conv[i], ac = sum - conv[i];
    if (sign(ab ^ ac) > 0) {
      gint off = 1e100;
      for (int j = 0; j < m; ++j) {
        relax(off, check(conv[i], conv[i + 1], sum));
      }
      cout << ans + off * n << '\n';
      return;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  srand(time(0));
  int t = 1;
  while (t--) solve();
  return 0;
}
