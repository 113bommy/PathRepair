#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
constexpr long long mod = 998244353;
const long long INF = mod * mod;
const long double eps = 1e-12;
const long double pi = acosl(-1.0);
long long mod_pow(long long x, long long n, long long m = mod) {
  if (n < 0) {
    long long res = mod_pow(x, -n, m);
    return mod_pow(res, m - 2, m);
  }
  if (abs(x) >= m) x %= m;
  if (x < 0) x += m;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}
struct modint {
  long long n;
  modint() : n(0) { ; }
  modint(long long m) : n(m) {
    if (n >= mod)
      n %= mod;
    else if (n < 0)
      n = (n % mod + mod) % mod;
  }
  operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) {
  a.n += b.n;
  if (a.n >= mod) a.n -= mod;
  return a;
}
modint operator-=(modint& a, modint b) {
  a.n -= b.n;
  if (a.n < 0) a.n += mod;
  return a;
}
modint operator*=(modint& a, modint b) {
  a.n = ((long long)a.n * b.n) % mod;
  return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, long long n) {
  if (n == 0) return modint(1);
  modint res = (a * a) ^ (n / 2);
  if (n % 2) res = res * a;
  return res;
}
long long inv(long long a, long long p) {
  return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) {
  a = a / b;
  return a;
}
const int max_n = 1 << 18;
modint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = modint(1);
  for (int i = 0; i < max_n - 1; i++) {
    fact[i + 1] = fact[i] * modint(i + 1);
  }
  factinv[max_n - 1] = modint(1) / fact[max_n - 1];
  for (int i = max_n - 2; i >= 0; i--) {
    factinv[i] = factinv[i + 1] * modint(i + 1);
  }
}
modint comb(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fact[a] * factinv[a - b];
}
int get_premitive_root() {
  int primitive_root = 0;
  if (!primitive_root) {
    primitive_root = [&]() {
      set<int> fac;
      int v = mod - 1;
      for (long long i = 2; i * i <= v; i++)
        while (v % i == 0) fac.insert(i), v /= i;
      if (v > 1) fac.insert(v);
      for (int g = 1; g < mod; g++) {
        bool ok = true;
        for (auto i : fac)
          if (mod_pow(g, (mod - 1) / i) == 1) {
            ok = false;
            break;
          }
        if (ok) return g;
      }
      return -1;
    }();
  }
  return primitive_root;
}
const int proot = get_premitive_root();
void dft(vector<modint>& f, bool inverse = false) {
  int n = f.size();
  if (n == 1) return;
  static vector<modint> w{1}, iw{1};
  for (int m = w.size(); m < n / 2; m *= 2) {
    modint dw = mod_pow(proot, (mod - 1) / (4 * m)), dwinv = (modint)1 / dw;
    w.resize(m * 2);
    iw.resize(m * 2);
    for (int i = 0; i < m; i++) w[m + i] = w[i] * dw, iw[m + i] = iw[i] * dwinv;
  }
  if (!inverse) {
    for (int m = n; m >>= 1;) {
      for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
        for (int i = s; i < s + m; i++) {
          modint x = f[i], y = f[i + m] * w[k];
          f[i] = x + y, f[i + m] = x - y;
        }
      }
    }
  } else {
    for (int m = 1; m < n; m *= 2) {
      for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
        for (int i = s; i < s + m; i++) {
          modint x = f[i], y = f[i + m];
          f[i] = x + y, f[i + m] = (x - y) * iw[k];
        }
      }
    }
    modint n_inv = (modint)1 / (modint)n;
    for (modint& v : f) v *= n_inv;
  }
}
vector<modint> multiply(vector<modint> g, vector<modint> h) {
  int n = 1;
  int pi = 0, qi = 0;
  for (int i = 0; i < g.size(); i++)
    if (g[i]) pi = i;
  for (int i = 0; i < h.size(); i++)
    if (h[i]) qi = i;
  int sz = pi + qi + 2;
  while (n < sz) n *= 2;
  g.resize(n);
  h.resize(n);
  dft(g);
  dft(h);
  for (int i = 0; i < n; i++) {
    g[i] *= h[i];
  }
  dft(g, true);
  return g;
}
modint inv2 = (1 + mod) / 2;
struct Data {
  vector<modint> p[2][2];
};
Data merge(Data dl, Data dr, int isone) {
  Data res;
  for (int a1 = 0; a1 < 2; a1++)
    for (int b1 = 0; b1 < 2; b1++)
      for (int a2 = 0; a2 < 2; a2++)
        for (int b2 = 0; b2 < 2; b2++) {
          vector<modint> r = multiply(dl.p[a1][b1], dr.p[a2][b2]);
          while (r.size() && r.back() == (modint)0) r.pop_back();
          if (isone && b1 && a2) {
            for (int i = 0; i < r.size(); i++) r[i] *= inv2;
          }
          int na = a1, nb = b1;
          if (res.p[na][nb].size() < r.size()) {
            res.p[na][nb].resize(r.size(), 0);
          }
          for (int i = 0; i < r.size(); i++) {
            res.p[na][nb][i] += r[i];
          }
        }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> c;
  int cur = 0;
  while (cur < n) {
    if (cur + a[cur] > n) {
      cout << 0 << "\n";
      return;
    }
    for (int j = cur; j < cur + a[cur]; j++) {
      if (a[cur] != a[j]) {
        cout << 0 << "\n";
        return;
      }
    }
    c.push_back(a[cur]);
    cur += a[cur];
  }
  if (c.size() == 1) {
    if (n == 1) {
      cout << 1 << "\n";
    } else {
      cout << 2 << "\n";
    }
    return;
  }
  function<Data(int, int)> yaru = [&](int l, int r) -> Data {
    if (r - l == 1) {
      int cnt = 0;
      if (c[l] == 1) cnt++;
      if (c[r] == 1) cnt++;
      Data res;
      res.p[0][0] = {1};
      res.p[1][1] = {0, (1 << cnt)};
      return res;
    }
    int m = (l + r) / 2;
    Data dl = yaru(l, m);
    Data dr = yaru(m, r);
    return merge(dl, dr, c[m] == 1);
  };
  Data d = yaru(0, c.size() - 1);
  vector<modint> num;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      if (num.size() < d.p[i][j].size()) {
        num.resize(d.p[i][j].size());
      }
      for (int k = 0; k < d.p[i][j].size(); k++) {
        num[k] += d.p[i][j][k];
      }
    }
  int c1 = 0;
  for (int i = 0; i < c.size(); i++)
    if (c[i] == 1) c1++;
  modint coef = mod_pow(inv2, c1);
  modint ans = 0;
  for (int i = 0; i < num.size(); i++) {
    if (i > c.size()) continue;
    modint val = num[i];
    if (i % 2) val *= -1;
    val *= mod_pow(2, c.size() - i);
    val *= fact[c.size() - i];
    val *= coef;
    ans += val;
  }
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init_f();
  solve();
  return 0;
}
