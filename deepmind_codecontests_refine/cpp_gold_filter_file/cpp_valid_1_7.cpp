#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optmize("unroll-loops")
#pragma GCC target("avx2,sse4")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getrnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
template <typename T1, typename T2>
inline bool relax(T1& a, const T2& b) {
  return a > b ? a = b, true : false;
}
template <typename T1, typename T2>
inline bool strain(T1& a, const T2& b) {
  return a < b ? a = b, true : false;
}
struct vec {
  using gint = ll;
  gint x, y;
  vec() : x(0), y(0) {}
  vec(ll a, ll b) : x(a), y(b) {}
  vec(vec a, vec b) : x(b.x - a.x), y(b.y - a.y) {}
  vec operator+(const vec& a) { return vec(a.x + x, a.y + y); }
  vec operator-(const vec& a) { return vec(x - a.x, y - a.y); }
  vec operator*(gint a) { return vec(x * a, y * a); }
  vec operator/(gint a) { return vec(x / a, y / a); }
  gint operator*(const vec& a) { return a.x * x + a.y * y; }
  gint qlen() { return (*this) * (*this); }
  ld len() { return sqrtl(qlen()); }
  gint operator^(const vec& a) { return x * a.y - y * a.x; }
  void read() { cin >> x >> y; }
};
void solve() {
  int n;
  cin >> n;
  ll ans = 0;
  vector<vec> p(n);
  vector<vector<int>> cnt(2, vector<int>(2, 0));
  for (int i = 0; i < n; ++i) {
    p[i].read();
    p[i].x = abs(p[i].x / 2) % 2;
    p[i].y = abs(p[i].y / 2) % 2;
    cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;
    for (int j = 0; j < i; ++j) {
      vec a = p[i], b = p[j];
      int s1 = a.x * b.y + a.y * b.x;
      for (int px = 0; px <= 1; ++px) {
        for (int py = 0; py <= 1; ++py) {
          int s = s1 + b.x * py + b.y * px + px * a.y + py * a.x;
          if (s % 2 == 0) ans += cnt[px][py];
        }
      }
      ++cnt[b.x][b.y];
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) solve();
  return 0;
}
