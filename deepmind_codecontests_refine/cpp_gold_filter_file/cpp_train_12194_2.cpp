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
long long gcd(long long v, long long b) {
  if (v > b) return gcd(b, v);
  if (v == b) return b;
  if (b % v == 0) return v;
  return gcd(v, b % v);
}
double distans(double x1, double y1, double x2, double y2) {
  double rr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt(rr);
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
long long pr[1000010];
long long inv[1000010];
long long beki(long long wa, long long rr, long long warukazu) {
  if (rr == 0) return 1 % warukazu;
  if (rr == 1) return wa % warukazu;
  wa %= warukazu;
  if (rr % 2 == 1)
    return ((long long)beki(wa, rr - 1, warukazu) * (long long)wa) % warukazu;
  long long zx = beki(wa, rr / 2, warukazu);
  return (zx * zx) % warukazu;
}
double bekid(double w, long long r) {
  if (r == 0) return 1.0;
  if (r == 1) return w;
  if (r % 2) return bekid(w, r - 1) * w;
  double f = bekid(w, r / 2);
  return f * f;
}
long long comb(long long nn, long long rr) {
  long long r = pr[nn] * inv[rr];
  r %= mod;
  r *= inv[nn - rr];
  r %= mod;
  return r;
}
void gya(long long ert) {
  pr[0] = 1;
  for (long long i = 1; i < ert; i++) {
    pr[i] = (pr[i - 1] * i) % mod;
  }
  for (long long i = 0; i < ert; i++) inv[i] = beki(pr[i], mod - 2, mod);
}
long long sosu[8000] = {};
bitset<7001> dp[100010];
bitset<7001> q1[7010];
bitset<7001> q4[7010];
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<long long> sf;
  sf.push_back(1);
  for (long long i = 2; i <= 7000; i++)
    if (!sosu[i]) {
      for (long long j = i * 2; j <= 7000; j += i) sosu[j] = 1;
      long long t = sf.size();
      for (long long j = 0; j < t; j++)
        if (sf[j] * i <= 7000) sf.push_back(sf[j] * i);
    }
  sort(sf.begin(), sf.end());
  for (long long i = 1; i <= 7000; i++)
    for (long long j = i; j <= 7000; j += i) {
      q1[j].set(i);
    }
  for (long long i = 1; i <= 7000; i++) {
    for (auto v : sf) {
      if (v * i > 7000) break;
      q4[i].set(v * i);
    }
  }
  long long n, q;
  cin >> n >> q;
  string ans = "";
  for (long long i = 0; i < q; i++) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long x, v;
      cin >> x >> v;
      dp[x] = q1[v];
    }
    if (t == 4) {
      long long x, v;
      cin >> x >> v;
      if ((dp[x] & q4[v]).count() % 2)
        ans += "1";
      else
        ans += "0";
    }
    if (t == 2) {
      long long x, y, z;
      cin >> x >> y >> z;
      dp[x] = (dp[y] ^ dp[z]);
    }
    if (t == 3) {
      long long x, y, z;
      cin >> x >> y >> z;
      dp[x] = (dp[y] & dp[z]);
    }
  }
  cout << ans << endl;
  return 0;
}
