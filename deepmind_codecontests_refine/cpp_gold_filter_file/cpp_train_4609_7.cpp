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
string S[100020];
vector<long long> G[100020];
vector<long long> vea(string s) {
  long long l = s.length();
  vector<long long> mae, ato;
  mae.push_back(-1000000007);
  long long d = 0;
  for (long long i = 0; i < l - 1; i++) {
    if (s[i] < s[i + 1]) {
      for (long long j = d; j <= i; j++) ato.push_back(j);
      d = i + 1;
    } else if (s[i] > s[i + 1]) {
      for (long long j = d; j <= i; j++) mae.push_back(j);
      d = i + 1;
    } else {
    }
  }
  for (long long j = d; j <= l - 1; j++) mae.push_back(j);
  mae.push_back(-1);
  while (ato.size()) {
    mae.push_back(ato.back());
    ato.pop_back();
  }
  mae.push_back(1000000007);
  assert(mae.size() == s.length() + 3);
  return mae;
}
vector<long long> dp[100020];
char nmo(long long a, long long ta, long long po) {
  long long lena = S[a].length();
  if (ta != -1) lena--;
  if (lena <= po) return 'A';
  if (ta == -1) return S[a][po];
  if (po < ta) return S[a][po];
  return S[a][po + 1];
}
vector<long long> H[100020];
long long QQ;
long long ha(long long a, long long ta, long long len) {
  if (ta == -1) return H[a][len - 1];
  if (len <= ta) return H[a][len - 1];
  long long ans = 0;
  if (ta) ans = H[a][ta - 1];
  long long ans2 = H[a][len] + mod - H[a][ta];
  ans2 %= mod;
  ans2 *= QQ;
  return (ans + ans2) % mod;
}
bool cv(long long a, long long ta, long long b, long long tb, long long len) {
  if (len == 0) return 1;
  return ha(a, ta, len) == ha(b, tb, len);
}
bool ch(long long a, long long ta, long long b, long long tb) {
  if (ta == 1000000007) return 0;
  if (ta == -1000000007) return 1;
  long long lena = S[a].length();
  if (ta != -1) lena--;
  long long lenb = S[b].length();
  if (tb != -1) lenb--;
  if (min(lena, lenb) == 0) {
    if (lena == lenb) return 1;
    if (lena == 0) return 1;
    return 0;
  }
  long long len = min(lena, lenb);
  long long si = 0, ue = len + 1;
  while (ue - si > 1) {
    long long me = (ue + si) / 2;
    if (cv(a, ta, b, tb, me))
      si = me;
    else
      ue = me;
  }
  return nmo(a, ta, si) <= nmo(b, tb, si);
}
void solve() {
  long long n;
  cin >> n;
  mod = 1000000007;
  for (long long i = 0; i < n; i++) {
    cin >> S[i];
    G[i] = vea(S[i]);
    long long l = S[i].length();
    long long hoge = 55555;
    H[i].push_back(S[i][0] - 'a' + 1);
    for (long long j = 1; j < l; j++) {
      H[i].push_back(0);
      H[i][j] = H[i][j - 1];
      H[i][j] += (S[i][j] - 'a' + 1) * hoge % mod;
      H[i][j] %= mod;
      hoge *= 55555;
      hoge %= mod;
    }
  }
  QQ = beki(55555, mod - 2, mod);
  for (long long i = 0; i < S[0].length() + 3; i++) {
    dp[0].push_back(0);
    if (0 < i && i <= S[0].length() + 2) dp[0][i] = i;
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < S[i].length() + 3; j++) dp[i].push_back(0);
    long long it = 0;
    for (long long j = 1; j <= S[i].length() + 1; j++) {
      while (ch(i - 1, G[i - 1][it], i, G[i][j])) it++;
      dp[i][j] += dp[i - 1][it - 1];
      dp[i][j] %= mod;
      dp[i][j] += dp[i][j - 1];
      dp[i][j] %= mod;
    }
  }
  cout << dp[n - 1][S[n - 1].length() + 1] << endl;
}
signed main() {
  mod = 1000000007;
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n = 1;
  for (long long i = 0; i < n; i++) solve();
  return 0;
}
