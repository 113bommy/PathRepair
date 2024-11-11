#include <bits/stdc++.h>
long long dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
long long dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
using namespace std;
class pa3 {
 public:
  long long x;
  long long y, z;
  pa3(long long x = 0, long long y = 0, long long z = 0) : x(x), y(y), z(z) {}
  bool operator<(const pa3 &p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    return z < p.z;
  }
  bool operator>(const pa3 &p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    return z > p.z;
  }
  bool operator==(const pa3 &p) const {
    return x == p.x && y == p.y && z == p.z;
  }
  bool operator!=(const pa3 &p) const {
    return !(x == p.x && y == p.y && z == p.z);
  }
};
class pa4 {
 public:
  long long x;
  long long y, z, w;
  pa4(long long x = 0, long long y = 0, long long z = 0, long long w = 0)
      : x(x), y(y), z(z), w(w) {}
  bool operator<(const pa4 &p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    if (z != p.z) return z < p.z;
    return w < p.w;
  }
  bool operator>(const pa4 &p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    if (z != p.z) return z > p.z;
    return w > p.w;
  }
  bool operator==(const pa4 &p) const {
    return x == p.x && y == p.y && z == p.z && w == p.w;
  }
};
class pa2 {
 public:
  long long x, y;
  pa2(long long x = 0, long long y = 0) : x(x), y(y) {}
  pa2 operator+(pa2 p) { return pa2(x + p.x, y + p.y); }
  pa2 operator-(pa2 p) { return pa2(x - p.x, y - p.y); }
  bool operator<(const pa2 &p) const { return y != p.y ? y < p.y : x < p.x; }
  bool operator>(const pa2 &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const pa2 &p) const {
    return abs(x - p.x) == 0 && abs(y - p.y) == 0;
  }
  bool operator!=(const pa2 &p) const {
    return !(abs(x - p.x) == 0 && abs(y - p.y) == 0);
  }
};
string itos(long long i) {
  ostringstream s;
  s << i;
  return s.str();
}
long long Gcd(long long v, long long b) {
  if (v == 0) return b;
  if (b == 0) return v;
  if (v > b) return Gcd(b, v);
  if (v == b) return b;
  if (b % v == 0) return v;
  return Gcd(v, b % v);
}
long long mod;
long long extgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
pair<long long, long long> operator+(const pair<long long, long long> &l,
                                     const pair<long long, long long> &r) {
  return {l.first + r.first, l.second + r.second};
}
pair<long long, long long> operator-(const pair<long long, long long> &l,
                                     const pair<long long, long long> &r) {
  return {l.first - r.first, l.second - r.second};
}
long long beki(long long wa, long long rr, long long warukazu) {
  if (rr == 0) return 1 % warukazu;
  if (rr == 1) return wa % warukazu;
  wa %= warukazu;
  if (rr % 2 == 1)
    return ((long long)beki(wa, rr - 1, warukazu) * (long long)wa) % warukazu;
  long long zx = beki(wa, rr / 2, warukazu);
  return (zx * zx) % warukazu;
}
long long pr[10];
long long inv[10];
long long comb(long long nn, long long rr) {
  if (rr < 0 || rr > nn || nn < 0) return 0;
  long long r = pr[nn] * inv[rr];
  r %= mod;
  r *= inv[nn - rr];
  r %= mod;
  return r;
}
void gya(long long ert) {
  pr[0] = 1;
  for (long long i = 1; i <= ert; i++) {
    pr[i] = ((long long)pr[i - 1] * i) % mod;
  }
  inv[ert] = beki(pr[ert], mod - 2, mod);
  for (long long i = ert - 1; i >= 0; i--) {
    inv[i] = (long long)inv[i + 1] * (i + 1) % mod;
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long ans = 0;
  long long p = b - a + 1, q = c - b + 1;
  if (p > q) swap(p, q);
  for (long long i = c; i <= d; i++) {
    if (a + b > i)
      ans += p * q;
    else {
      long long g = i - a - b + 1;
      if (p >= g)
        ans += p * q - g * (g + 1) / 2;
      else if (q >= g)
        ans += p * (q - g + q - g + p - 1) / 2;
      else if (q - g + p > 0)
        ans += (q - g + p) * (q - g + p + 1) / 2;
      else
        ans += 0;
    }
  }
  cout << ans << endl;
  return 0;
}
