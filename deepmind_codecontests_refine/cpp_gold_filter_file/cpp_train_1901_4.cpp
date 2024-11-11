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
long long pr[2100100];
long long inv[2100010];
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
vector<long long> G[1020];
vector<long long> dep[1020];
long long hu[1020];
long long dfs(long long r, long long p, long long d) {
  dep[d].push_back(r);
  hu[r] = 0;
  for (auto v : G[r])
    if (v != p) {
      hu[r] = max(hu[r], 1 + dfs(v, r, d + 1));
    }
  return hu[r];
}
vector<long long> W;
void dfs2(long long r, long long p, long long d) {
  if (d == 0) {
    W.push_back(r);
    return;
  }
  for (auto v : G[r])
    if (v != p) dfs2(v, r, d - 1);
}
pair<long long, long long> ask(long long si, long long ue) {
  long long ko = 0;
  for (long long i = si; i < ue; i++) ko += dep[i].size();
  if (ko == 0) return make_pair(1000000007, 1000000007);
  cout << "? " << ko;
  for (long long i = si; i < ue; i++)
    for (auto v : dep[i]) cout << " " << v;
  cout << endl;
  long long r, d;
  cin >> r >> d;
  return make_pair(r, d);
}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n - 1; i++) {
    long long y, yy;
    cin >> y >> yy;
    G[y].push_back(yy);
    G[yy].push_back(y);
  }
  cout << "? " << n;
  for (long long i = 1; i <= n; i++) cout << " " << i;
  cout << endl;
  long long r, d;
  cin >> r >> d;
  dfs(r, r, 0);
  if (G[r].size() == 1) {
    cout << "? " << dep[d].size();
    for (auto v : dep[d]) cout << " " << v;
    cout << endl;
    long long rr;
    cin >> rr >> d;
    cout << "! " << r << " " << rr << endl;
  } else {
    long long val = -1, p = -1;
    for (auto v : G[r])
      if (hu[v] > val) {
        val = hu[v];
        p = v;
      }
    for (long long i = 1; i <= n; i++) {
      dep[i].clear();
    }
    for (auto v : G[r])
      if (v != p) dfs(v, r, 1);
    long long si = 0, ue = 501;
    long long a1 = r;
    while (ue - si > 1) {
      long long me = (ue + si) / 2;
      pair<long long, long long> z = ask(me, ue);
      if (z.second == d)
        si = me, a1 = z.first;
      else
        ue = me;
    }
    long long a2;
    dfs2(a1, a1, d);
    cout << "? " << W.size();
    for (auto v : W) cout << " " << v;
    cout << endl;
    cin >> a2 >> d;
    cout << "! " << a1 << " " << a2 << endl;
    W.clear();
  }
  string s;
  cin >> s;
  for (long long i = 1; i <= n; i++) {
    G[i].clear();
    dep[i].clear();
  }
  dep[0].clear();
}
signed main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) solve();
  return 0;
}
