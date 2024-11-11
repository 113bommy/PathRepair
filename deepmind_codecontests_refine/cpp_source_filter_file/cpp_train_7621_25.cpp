#include <bits/stdc++.h>
using namespace std;
long long dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
long long dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
class pa3 {
 public:
  long long x;
  long long y, z;
  pa3(long long x = 0, long long y = 0, long long z = 0) : x(x), y(y), z(z) {}
  bool operator<(const pa3& p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    return z < p.z;
  }
  bool operator>(const pa3& p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    return z > p.z;
  }
  bool operator==(const pa3& p) const {
    return x == p.x && y == p.y && z == p.z;
  }
  bool operator!=(const pa3& p) const {
    return !(x == p.x && y == p.y && z == p.z);
  }
};
class pa4 {
 public:
  long long x;
  long long y, z, w;
  pa4(long long x = 0, long long y = 0, long long z = 0, long long w = 0)
      : x(x), y(y), z(z), w(w) {}
  bool operator<(const pa4& p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    if (z != p.z) return z < p.z;
    return w < p.w;
  }
  bool operator>(const pa4& p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    if (z != p.z) return z > p.z;
    return w > p.w;
  }
  bool operator==(const pa4& p) const {
    return x == p.x && y == p.y && z == p.z && w == p.w;
  }
};
class pa2 {
 public:
  long long x, y;
  pa2(long long x = 0, long long y = 0) : x(x), y(y) {}
  pa2 operator+(pa2 p) { return pa2(x + p.x, y + p.y); }
  pa2 operator-(pa2 p) { return pa2(x - p.x, y - p.y); }
  bool operator<(const pa2& p) const { return y != p.y ? y < p.y : x < p.x; }
  bool operator>(const pa2& p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const pa2& p) const {
    return abs(x - p.x) == 0 && abs(y - p.y) == 0;
  }
  bool operator!=(const pa2& p) const {
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
long long extgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
pair<long long, long long> operator+(const pair<long long, long long>& l,
                                     const pair<long long, long long>& r) {
  return {l.first + r.first, l.second + r.second};
}
pair<long long, long long> operator-(const pair<long long, long long>& l,
                                     const pair<long long, long long>& r) {
  return {l.first - r.first, l.second - r.second};
}
ostream& operator<<(ostream& os, const vector<long long>& VEC) {
  for (auto v : VEC) os << v << " ";
  return os;
}
ostream& operator<<(ostream& os, const pair<long long, long long>& PAI) {
  os << PAI.first << " : " << PAI.second;
  return os;
}
ostream& operator<<(ostream& os, const pa3& PAI) {
  os << PAI.x << " : " << PAI.y << " : " << PAI.z;
  return os;
}
ostream& operator<<(ostream& os, const pa4& PAI) {
  os << PAI.x << " : " << PAI.y << " : " << PAI.z << " : " << PAI.w;
  return os;
}
ostream& operator<<(ostream& os,
                    const vector<pair<long long, long long> >& VEC) {
  for (auto v : VEC) os << v << " ";
  return os;
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
long long pr[1100000];
long long inv[1100000];
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
long long a[60][150] = {};
long long dp[60][150] = {};
long long co[60][150] = {};
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > ve(n);
  for (long long i = 0; i < n; i++) cin >> ve[i].first >> ve[i].second;
  reverse(ve.begin(), ve.end());
  set<long long> se;
  long long z = 1;
  mod = 998244353;
  for (auto& v : ve) {
    v.second++;
    z *= (v.second - v.first);
    z %= mod;
    se.insert(v.first);
    se.insert(v.second);
  }
  long long cnt = 1;
  map<long long, long long> ma;
  vector<long long> h;
  h.push_back(0);
  for (auto i : se) {
    ma[i] = cnt;
    h.push_back(i);
    cnt++;
  }
  h.push_back(1000000007);
  ma[-1] = 0;
  ma[1000000007] = cnt;
  for (auto& v : ve) {
    v.first = ma[v.first];
    v.second = ma[v.second];
  }
  for (long long i = 0; i < cnt; i++) {
    long long sa = h[i + 1] - h[i];
    long long si = 1;
    long long bo = 1;
    for (long long j = 1; j <= 50; j++) {
      si *= sa + j - 1;
      si %= mod;
      bo *= j;
      bo %= mod;
      co[i][j] = si * beki(bo, mod - 2, mod) % mod;
    }
  }
  for (long long i = 0; i < n; i++) {
    pair<long long, long long> v = ve[i];
    for (long long j = 0; j <= cnt; j++) {
      if (v.first <= j && v.second > j) a[i + 1][j] = 1;
    }
  }
  dp[0][0] = 1;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j <= cnt; j++)
      if (dp[i][j]) {
        for (long long k = j + 1; k <= cnt; k++) {
          for (long long l = i + 1;; l++) {
            if (a[l][k] == 0) break;
            dp[l][k] += dp[i][j] * co[k][l - i] % mod;
            dp[l][k] %= mod;
          }
        }
      }
  }
  long long ans = 0;
  for (long long i = 0; i < cnt; i++) ans += dp[n][i];
  ans %= mod;
  ans *= beki(z, mod - 2, mod);
  ans %= mod;
  cout << ans << endl;
}
signed main() {
  mod = 1000000007;
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n = 1;
  for (long long i = 0; i < n; i++) solve();
  return 0;
}
