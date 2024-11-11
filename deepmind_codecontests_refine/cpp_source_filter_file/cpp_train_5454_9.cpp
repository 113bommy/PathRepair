#include <bits/stdc++.h>
using namespace std;
template <class my>
my aabs(const my &a) {
  return (a > 0) ? a : -a;
}
long long int gcd(long long int a, long long int b) {
  return (b == 0) ? a : gcd(b, a % b);
}
long long int LSOne(long long int k) { return (k & (-k)); }
inline int inv(int o) {
  int b = 1000000007, u = 0, v = 1, t, a = o;
  while (a) {
    t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  if (u < 0) u += 1000000007;
  return u;
}
inline int add(const int &a, const int &b) {
  return a + b >= 1000000007 ? a + b - 1000000007 : a + b;
}
inline int sub(const int &a, const int &b) {
  return a - b < 0 ? a - b + 1000000007 : a - b;
}
inline int mul(const int &a, const int &b) {
  return int(a * 1ll * b % 1000000007);
}
inline int _div(const int &a, const int &b) { return mul(a, inv(b)); }
inline int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
void solve() {
  int n, m, xc, yc, a, b, x1, y1, ax, ay, temp, x[2], y[2];
  cin >> n >> m >> xc >> yc >> a >> b;
  temp = gcd(a, b);
  a /= temp;
  b /= temp;
  ax = n / a;
  ax = min(ax, m / b);
  x1 = a * ax;
  y1 = b * ax;
  a = (x1 + 1) / 2;
  b = (y1 + 1) / 2;
  x[0] = xc - ((x1 + 1) / 2);
  x[1] = xc + (x1 / 2);
  y[0] = yc - ((y1 + 1) / 2);
  y[1] = yc + (y1 / 2);
  if (x[0] < 0) {
    x[1] -= x[0];
    x[0] = 0;
  }
  if (x[1] > n) {
    x[0] -= (n - x[1]);
    x[1] = n;
  }
  if (y[0] < 0) {
    y[1] -= y[0];
    y[0] = 0;
  }
  if (y[1] > m) {
    y[0] -= (y[1] - m);
    y[1] = m;
  }
  cout << x[0] << " " << y[0] << " " << x[1] << " " << y[1] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
  while (t--) solve();
}
