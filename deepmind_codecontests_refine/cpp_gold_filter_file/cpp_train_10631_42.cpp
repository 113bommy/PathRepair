#include <bits/stdc++.h>
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
using namespace std;
class pa3 {
 public:
  int x, y, z;
  pa3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
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
  int x;
  int y, z, w;
  pa4(int x = 0, int y = 0, int z = 0, int w = 0) : x(x), y(y), z(z), w(w) {}
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
  int x, y;
  pa2(int x = 0, int y = 0) : x(x), y(y) {}
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
string itos(int i) {
  ostringstream s;
  s << i;
  return s.str();
}
int gcd(int v, int b) {
  if (v > b) return gcd(b, v);
  if (v == b) return b;
  if (b % v == 0) return v;
  return gcd(v, b % v);
}
double distans(double x1, double y1, double x2, double y2) {
  double rr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt(rr);
}
int mod;
int extgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
int pr[1000010];
int inv[1000010];
int beki(int wa, int rr, int warukazu) {
  if (rr == 0) return 1 % warukazu;
  if (rr == 1) return wa % warukazu;
  wa %= warukazu;
  if (rr % 2 == 1)
    return ((long long)beki(wa, rr - 1, warukazu) * (long long)wa) % warukazu;
  long long zx = beki(wa, rr / 2, warukazu);
  return (zx * zx) % warukazu;
}
double bekid(double w, int r) {
  if (r == 0) return 1.0;
  if (r == 1) return w;
  if (r % 2) return bekid(w, r - 1) * w;
  double f = bekid(w, r / 2);
  return f * f;
}
int comb(int nn, int rr) {
  int r = pr[nn] * inv[rr];
  r %= mod;
  r *= inv[nn - rr];
  r %= mod;
  return r;
}
void gya(int ert) {
  pr[0] = 1;
  for (int i = 1; i < ert; i++) {
    pr[i] = (pr[i - 1] * i) % mod;
  }
  for (int i = 0; i < ert; i++) inv[i] = beki(pr[i], mod - 2, mod);
}
signed main() {
  vector<int> ve;
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  int a[2020];
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << n + 1 << endl;
  for (int i = n; i >= 1; i--) {
    int e = a[i] % 2000;
    int sa = (i - e + 4000 - 1) % 2000;
    cout << "1 " << i << " " << sa << endl;
    for (int j = 1; j <= i; j++) a[j] += sa;
  }
  cout << "2 " << n << " 2000" << endl;
  return 0;
}
