#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
template <typename T>
inline istream& operator>>(istream& i, vector<T>& v) {
  for (int j = 0; j < ((int)(v).size()); ++j) i >> v[j];
  return i;
}
template <typename T>
string join(const vector<T>& v) {
  stringstream s;
  for (int i = 0; i < ((int)(v).size()); ++i) s << ' ' << v[i];
  return s.str().substr(1);
}
template <typename T>
inline ostream& operator<<(ostream& o, const vector<T>& v) {
  if ((int)(v).size()) o << join(v);
  return o;
}
template <typename T1, typename T2>
inline istream& operator>>(istream& i, pair<T1, T2>& v) {
  return i >> v.first >> v.second;
}
template <typename T1, typename T2>
inline ostream& operator<<(ostream& o, const pair<T1, T2>& v) {
  return o << v.first << "," << v.second;
}
template <typename T>
inline long long int suma(const vector<T>& a) {
  long long int res(0);
  for (auto&& x : a) res += x;
  return res;
}
const double eps = 1e-10;
const long long int LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MX = 200005;
const int mod = 1000000007;
struct mint {
  long long int x;
  mint() : x(0) {}
  mint(long long int x) : x((x % mod + mod) % mod) {}
  mint& fix() {
    x = (x % mod + mod) % mod;
    return *this;
  }
  mint operator-() const { return mint(0) - *this; }
  mint operator~() const { return mint(1) / *this; }
  mint& operator+=(const mint& a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint& a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint& a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint& operator/=(const mint& a) {
    (x *= a.ex(mod - 2).x) %= mod;
    return *this;
  }
  mint operator+(const mint& a) const { return mint(*this) += a; }
  mint operator-(const mint& a) const { return mint(*this) -= a; }
  mint operator*(const mint& a) const { return mint(*this) *= a; }
  mint operator/(const mint& a) const { return mint(*this) /= a; }
  mint ex(long long int t) const {
    if (!t) return 1;
    mint res = ex(t / 2);
    res *= res;
    return (t & 1) ? res * x : res;
  }
  bool operator<(const mint& a) const { return x < a.x; }
  bool operator==(const mint& a) const { return x == a.x; }
};
mint ex(mint x, long long int t) { return x.ex(t); }
istream& operator>>(istream& i, mint& a) {
  i >> a.x;
  return i;
}
ostream& operator<<(ostream& o, const mint& a) {
  o << a.x;
  return o;
}
struct comb {
  vector<mint> f, g;
  comb() {}
  comb(int mx) : f(mx + 1), g(mx + 1) {
    f[0] = 1;
    for (int i = 1; i <= (mx); ++i) f[i] = f[i - 1] * i;
    g[mx] = f[mx].ex(mod - 2);
    for (int i = mx; i > 0; i--) g[i - 1] = g[i] * i;
  }
  mint c(int a, int b) {
    if (a < b) return 0;
    return f[a] * g[b] * g[a - b];
  }
} c(MX);
struct mat {
  int h, w;
  vector<vector<mint> > d;
  mat() {}
  mat(int h, int w, mint v = 0) : h(h), w(w), d(h, vector<mint>(w, v)) {}
  vector<mint>& operator[](int i) { return d[i]; }
  const vector<mint>& operator[](int i) const { return d[i]; }
  void fil(mint v = 0) {
    for (int i = 0; i < (h); ++i)
      for (int j = 0; j < (w); ++j) d[i][j] = v;
  }
  void unit() {
    for (int i = 0; i < (h); ++i)
      for (int j = 0; j < (w); ++j) d[i][j] = (i == j);
  }
  mat operator*(const mat& a) const {
    mat res(h, a.w);
    for (int i = 0; i < (h); ++i)
      for (int k = 0; k < (w); ++k)
        for (int j = 0; j < (a.w); ++j) res[i][j] += d[i][k] * a[k][j];
    return res;
  }
  mat inv() {
    mat res(h, w);
    res.unit();
    for (int i = 0; i < (w); ++i) {
      if (!d[i][i].x) {
        for (int j = i + 1; j < h; ++j) {
          if (d[j][i].x) {
            swap(d[i], d[j]);
            swap(res[i], res[j]);
            break;
          }
        }
        assert(d[i][i].x);
      }
      mint x = ~d[i][i];
      for (int j = 0; j < (w); ++j) d[i][j] *= x;
      for (int j = 0; j < (w); ++j) res[i][j] *= x;
      for (int k = 0; k < (h); ++k) {
        if (i == k || !d[k][i].x) continue;
        mint x = d[k][i];
        for (int j = i; j < w; ++j) d[k][j] -= d[i][j] * x;
        for (int j = 0; j < (w); ++j) res[k][j] -= res[i][j] * x;
      }
    }
    return res;
  }
  void pri() {
    for (int i = 0; i < (h); ++i) {
      cout << "|";
      for (int j = 0; j < (w); ++j) cout << " " << d[i][j];
      cout << " |" << endl;
    }
    cout << endl;
  }
};
int m;
const int K = 201;
vector<int> to[MX];
vector<mint> co[K];
mint co2[K + 1];
mint exs[K][K];
inline void fold(vector<mint>& a) {
  while ((int)(a).size() > K) {
    mint x = a.back();
    a.pop_back();
    int j = (int)(a).size() - K;
    for (int i = 0; i < (K); ++i) a[i] += co[j][i] * x;
  }
}
inline vector<mint> add(vector<mint>& a, vector<mint>& b) {
  vector<mint> res((int)(a).size() + (int)(b).size() - 1);
  for (int i = 0; i < ((int)(a).size()); ++i)
    for (int j = 0; j < ((int)(b).size()); ++j) res[i + j] += a[i] * b[j];
  fold(res);
  return res;
}
mint ans;
vector<mint> dfs(int v, int p = -1) {
  vector<mint> dp(1, 1);
  for (int u : to[v]) {
    if (u == p) continue;
    vector<mint> e = dfs(u, v);
    e.insert(e.begin(), 1);
    for (int i = 0; i < ((int)(e).size()); ++i) ans -= e[i] * co2[i];
    dp = add(dp, e);
  }
  for (int i = 0; i < ((int)(dp).size()); ++i) dp[i] *= 2;
  dp[0] -= 1;
  for (int i = 0; i < ((int)(dp).size()); ++i) ans += dp[i] * co2[i];
  return dp;
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < (n - 1); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  for (int i = 0; i < (K); ++i)
    for (int j = 0; j < (K); ++j) exs[i][j] = ex(i, j);
  mat a(K, K);
  for (int i = 0; i < (K); ++i)
    for (int j = 0; j < (K); ++j) a[i][j] = exs[i][j] * c.g[j];
  mat ia = mat(a).inv();
  for (int i = 0; i < (K + 1); ++i) co2[i] = ex(i, m) * c.g[m];
  for (int i = 0; i < (K); ++i) {
    mat x(1, K);
    for (int j = 0; j < (K); ++j) x[0][j] = ex(K + i, j) * c.g[j];
    x = x * ia;
    co[i] = x[0];
  }
  dfs(0);
  ans *= c.f[m];
  cout << ans << endl;
  return 0;
}
