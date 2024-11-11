#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
constexpr long long mod = 1000000007;
const long long INF = mod * mod;
const double eps = 1e-4;
const double pi = acosl(-1.0);
template <typename T>
void chmin(T& a, T b) {
  a = min(a, b);
}
template <typename T>
void chmax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void cinarray(vector<T>& v) {
  for (int i = 0; i < v.size(); i++) cin >> v[i];
}
template <typename T>
void coutarray(vector<T>& v) {
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) cout << " ";
    cout << v[i];
  }
  cout << "\n";
}
long long mod_pow(long long x, long long n, long long m = mod) {
  if (n < 0) {
    long long res = mod_pow(x, -n, m);
    return mod_pow(res, m - 2, m);
  }
  if (abs(x) >= m) x %= m;
  if (x < 0) x += m;
  if (x == 0) return 0;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}
struct modint {
  int n;
  modint() : n(0) { ; }
  modint(long long m) {
    if (m < 0 || mod <= m) {
      m %= mod;
      if (m < 0) m += mod;
    }
    n = m;
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
const int max_n = 1 << 20;
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
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[1 << 20][2];
int pre[1 << 20][2];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = mod;
    }
  }
  dp[1][0] = dp[1][1] = -mod;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        for (int l = 0; l < 2; l++) {
          pair<int, int> p;
          p.first = a[i - 1];
          if (j == 0) p.first *= -1;
          p.second = dp[i][j];
          if (k) swap(p.first, p.second);
          int val = a[i];
          if (l == 0) val *= -1;
          if (p.first < val) {
            if (dp[i + 1][l] > p.second) {
              dp[i + 1][l] = p.second;
              pre[i + 1][l] = j;
            }
          }
        }
  }
  if (dp[n][0] == mod && dp[n][1] == mod) {
    cout << "NO\n";
    return;
  }
  vector<int> ans = a;
  int cur = 0;
  if (dp[n][0] == mod) cur = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (cur) ans[i] *= -1;
    cur = pre[i + 1][cur];
  }
  cout << "YES\n";
  coutarray(ans);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
