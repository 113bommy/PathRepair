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
int D[3000000];
const int MOD = 998244353;
void fourie(int N, int d, vector<int> &vec) {
  if (N == 1) {
    return;
  }
  int gyaku = 0;
  for (int i = 1; i < N; i++) {
    int e = 1 << (d - 1);
    while (gyaku & e) {
      gyaku ^= e;
      e >>= 1;
    }
    gyaku ^= e;
    if (i < gyaku) swap(vec[i], vec[gyaku]);
  }
  for (int c = 0; c < d; c++) {
    int f = 1 << c;
    for (int i = 0; i < N; i += (f << 1)) {
      for (int j = i; j < i + f; j++) {
        int A1 = ((long long)vec[j] +
                  (long long)vec[j + f] * D[(j - i) << (d - c - 1)]) %
                 MOD;
        int A2 =
            ((long long)vec[j] -
             ((long long)vec[j + f] * D[(j - i) << (d - c - 1)] % MOD) + MOD) %
            MOD;
        vec[j] = A1;
        vec[j + f] = A2;
      }
    }
  }
  return;
}
vector<int> NTT(vector<int> input1, vector<int> input2) {
  int N = 1;
  int d = 0;
  int size1 = input1.size(), size2 = input2.size();
  while (N < size1 + size2) {
    N *= 2;
    d++;
  }
  assert(N == (1 << d));
  while ((int)input1.size() < N) input1.push_back(0);
  while ((int)input2.size() < N) input2.push_back(0);
  for (auto v : input1) {
    if (v < 0) v = MOD - ((-v) % MOD);
    if (v >= MOD) v %= MOD;
  }
  for (auto v : input2) {
    if (v < 0) v = MOD - ((-v) % MOD);
    if (v >= MOD) v %= MOD;
  }
  int g = beki(3, 119, MOD);
  for (int i = 0; i < 23 - d; i++) g = ((long long)g * g) % MOD;
  D[0] = 1;
  for (int i = 1; i < N; i++) {
    D[i] = (long long)D[i - 1] * g % MOD;
  }
  fourie(N, d, input1);
  fourie(N, d, input2);
  vector<int> ANS;
  for (int i = 0; i < N; i++)
    input1[i] = (long long)input1[i] * input2[i] % MOD;
  for (int i = 1; i < N / 2; i++) swap(D[i], D[N - i]);
  fourie(N, d, input1);
  int ninv = beki(N, MOD - 2, MOD);
  for (int i = 0; i < N; i++) input1[i] = (long long)input1[i] * ninv % MOD;
  for (int i = 0; i < size1 + size2 + 1; i++) {
    ANS.push_back(input1[i]);
  }
  return ANS;
}
vector<int> ve(10, 0);
vector<int> dd;
void sh() {
  for (auto v : dd) cout << v << " ";
  cout << endl;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int y;
    cin >> y;
    ve[y] = 1;
  }
  int ans = 0;
  n /= 2;
  dd = ve;
  bool bo = 0;
  for (int i = 30; i >= 0; i--) {
    if (bo == 0 && (n & (1 << i)) == 0) continue;
    if (bo == 0) {
      bo = 1;
      continue;
    }
    if (n & (1 << i)) {
      dd = NTT(dd, dd);
      dd = NTT(dd, ve);
    } else {
      dd = NTT(dd, dd);
    }
  }
  for (auto v : dd) {
    if (v > 0) {
      ans += (long long)v * v % MOD;
      ans %= MOD;
    }
  }
  cout << ans % MOD << endl;
  return 0;
}
