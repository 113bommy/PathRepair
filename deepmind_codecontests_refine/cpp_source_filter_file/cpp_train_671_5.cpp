#include <bits/stdc++.h>
using namespace std;
struct vec {
  long double x, y;
  bool operator==(const vec &a) const { return x == a.x && y == a.y; }
  bool operator<(const vec &a) const {
    if (a.x != x) return x < a.x;
    return y < a.y;
  }
  vec operator+(const vec &a) const { return {x + a.x, y + a.y}; }
  vec operator*(const long double &a) const { return {x * a, y * a}; }
  vec operator-(const vec &a) const { return {x - a.x, y - a.y}; }
  vec operator/(const long double &a) const { return {x / a, y / a}; }
  long double len() const { return sqrt(x * x + y * y); }
  long double dot(const vec &a) const { return x * a.x + y * a.y; }
  long double crs(const vec &a) const { return x * a.y - y * a.x; }
  vec proj(const vec &a) const {
    return (a / a.len()) * (*this).dot(a) / a.len();
  }
};
struct P {
  int x, y;
  bool operator<(const P &a) const { return y > a.y; }
};
bool as(P a, P b) { return a.x < b.x; }
long long x, y, z, mod = 1000000007;
vector<P> v[1];
int i, n, m, k, a, d, b, c, dx[10] = {1, 0, -1, 0}, dy[10] = {0, 1, 0, -1};
int e;
int o[11];
long long l[111111];
int j[1];
stack<int> s;
queue<P> q;
P u[1];
char r[111111];
map<int, int> p, p1;
long long ten[111111], fac[111111], re[111111];
long long dd(long long x, long long y) {
  long long p = 1;
  for (; y; x *= x, x %= mod, y /= 2)
    if (y % 2) p *= x, p %= mod;
  return p;
}
int main() {
  scanf("%d %d", &a, &b);
  ten[0] = fac[0] = re[0] = 1;
  for (int t = 1; t <= a; t++)
    ten[t] = ten[t - 1] * 10 % mod, fac[t] = fac[t - 1] * t % mod,
    re[t] = dd(fac[t], mod - 2);
  if (b == 0) {
    for (int t = 1; t <= a; y += (x * ten[a - t]) % mod, y %= mod, t++)
      scanf("%1lld", &x);
    printf("%lld", y);
    return 0;
  }
  for (int t = 1; t <= a; t++) {
    scanf("%1d", &o[t]);
    if (a >= t + b)
      l[t] = fac[a - t - 1] * re[b - 1] % mod * re[a - t - b] % mod *
             ten[t - 1] % mod;
    l[t] += l[t - 1];
    l[t] %= mod;
  }
  for (int t = 1; t <= a; t++) {
    if (t > b)
      y += fac[t - 1] * re[b] % mod * re[t - b - 1] % mod * o[t] % mod *
           ten[a - t] % mod;
    y %= mod;
    if (t < a) {
      y += l[min(a - b, a - t)] * o[t] % mod;
      y %= mod;
    }
  }
  printf("%lld", y);
}
