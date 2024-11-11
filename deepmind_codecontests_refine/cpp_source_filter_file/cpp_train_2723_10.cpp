#include <bits/stdc++.h>
using namespace std;
struct fast_ios {
  fast_ios() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  };
} fast_ios_;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i != v.size() - 1) cout << endl;
  };
  return os;
}
template <typename T>
void Out(T x) {
  cout << x << '\n';
}
template <typename T1, typename T2>
void Ans(bool first, T1 y, T2 n) {
  if (first)
    Out(y);
  else
    Out(n);
}
using vec = vector<long long>;
using mat = vector<vec>;
using Pii = pair<long long, long long>;
using PiP = pair<long long, Pii>;
using PPi = pair<Pii, long long>;
using bools = vector<bool>;
using pairs = vector<Pii>;
const long long mod = 998244353;
template <long long MOD>
struct ModInt {
  using ll = long long;
  ll val;
  void setval(ll v) { val = v % MOD; };
  ModInt() : val(0) {}
  ModInt(ll v) { setval(v); };
  ModInt operator+(const ModInt &x) const { return ModInt(val + x.val); }
  ModInt operator-(const ModInt &x) const { return ModInt(val - x.val + MOD); }
  ModInt operator*(const ModInt &x) const { return ModInt(val * x.val); }
  ModInt operator/(const ModInt &x) const { return *this * x.inv(); }
  ModInt operator-() const { return ModInt(MOD - val); }
  ModInt operator+=(const ModInt &x) { return *this = *this + x; }
  ModInt operator-=(const ModInt &x) { return *this = *this - x; }
  ModInt operator*=(const ModInt &x) { return *this = *this * x; }
  ModInt operator/=(const ModInt &x) { return *this = *this / x; }
  friend ostream &operator<<(ostream &os, const ModInt &x) {
    os << x.val;
    return os;
  }
  friend istream &operator>>(istream &is, ModInt &x) {
    is >> x.val;
    x.val = (x.val % MOD + MOD) % MOD;
    return is;
  }
  ModInt pow(ll n) const {
    ModInt a = 1;
    if (n == 0) return a;
    long long i0 = 64 - __builtin_clzll(n);
    for (long long i = i0 - 1; i >= 0; i--) {
      a = a * a;
      if ((n >> i) & 1) a *= (*this);
    }
    return a;
  }
  ModInt inv() const { return this->pow(MOD - 2); }
};
using mint = ModInt<mod>;
mint pow(mint x, long long n) { return x.pow(n); }
using mvec = vector<mint>;
using mmat = vector<mvec>;
struct Combination {
  vector<mint> fact, invfact;
  Combination(long long N) {
    fact = vector<mint>({mint(1)});
    invfact = vector<mint>({mint(1)});
    fact_initialize(N);
  }
  void fact_initialize(long long N) {
    long long i0 = fact.size();
    if (i0 >= N + 1) return;
    fact.resize(N + 1);
    invfact.resize(N + 1);
    for (long long i = i0; i <= N; i++) fact[i] = fact[i - 1] * i;
    invfact[N] = (mint)1 / fact[N];
    for (long long i = N - 1; i >= i0; i--)
      invfact[i] = invfact[i + 1] * (i + 1);
  }
  mint nCr(long long n, long long r) {
    if (n < 0 || r < 0 || r > n) return mint(0);
    if (fact.size() < n + 1) fact_initialize(n);
    return fact[n] * invfact[r] * invfact[n - r];
  }
  mint nPr(long long n, long long r) {
    if (n < 0 || r < 0 || r > n) return mint(0);
    if (fact.size() < n + 1) fact_initialize(n);
    return fact[n] * invfact[n - r];
  }
};
signed main() {
  long long n, m;
  cin >> n >> m;
  vec a(n);
  cin >> a;
  bools like(n, true);
  for (long long i = (0); i < (n); i++)
    if (a[i] == 0) like[i] = false;
  vec w(n);
  cin >> w;
  long long S = 0, L = 0, D = 0;
  for (long long i = (0); i < (n); i++) {
    S += a[i];
    if (like[i])
      L += w[i];
    else
      D += w[i];
  }
  mmat dp(m + 1, mvec(m + 1, 0));
  dp[0][0] = 1;
  for (long long i = (0); i < (m); i++) {
    for (long long j = (0); j < (i + 1); j++) {
      long long k = i - j;
      long long L2 = L + j, D2 = D - k;
      if (D2 < 0) continue;
      mint inv = (mint)1 / (mint)(L2 + D2);
      dp[i + 1][j + 1] += dp[i][j] * (mint)L2 * inv;
      dp[i + 1][j] += dp[i][j] * (mint)D2 * inv;
    }
  }
  mvec ans(n, 0);
  mint al = 0;
  mint invL = (mint)1 / (mint)L;
  for (long long i = (0); i < (m + 1); i++) {
    al += dp[m][i] * (L + i) * invL;
  }
  mint ad = 0;
  mint invD = (mint)1 / (mint)D;
  for (long long i = (0); i < (m + 1); i++) {
    long long j = m - i;
    if (j <= L) ad += dp[m][i] * (D - j) * invD;
  }
  for (long long i = (0); i < (n); i++) {
    if (like[i])
      ans[i] = al * w[i];
    else
      ans[i] = ad * w[i];
  }
  Out(ans);
  return 0;
}
