#include <bits/stdc++.h>
using namespace std;
double PI = 3.141592653589793;
const long long P = 1e9 + 7;
class mint {
 public:
  static int init_siz;
  static vector<mint> inverse, factorial;
  static int mintP;
  int n;
  static mint exp(mint a, long long e) {
    mint res = 1;
    while (e) {
      if (e & 1) res *= a;
      a *= a;
      e >>= 1;
    }
    return res;
  }
  static void init(int n) {
    init_siz = n;
    inverse.resize(n + 1);
    factorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) factorial[i] = factorial[i - 1] * i;
    inverse[n] = exp(factorial[n], mintP - 2);
    for (int i = n - 1; i >= 0; i--) inverse[i] = inverse[i + 1] * (i + 1);
  }
  static mint inv(mint const& a) {
    return (init_siz >= a.n ? inverse[a.n] * (a.n > 1 ? fac(a - 1) : 1)
                            : exp(a, mintP - 2));
  }
  static mint cinv(mint const& a) {
    return (init_siz >= a.n ? inverse[a.n] : exp(fac(a), mintP - 2));
  }
  static mint fac(mint const& a) {
    if (init_siz >= a.n)
      return factorial[a.n];
    else {
      mint out = 1;
      for (int i = 0; i < a.n; i++) out *= (i + 1);
      return out;
    }
  }
  mint(long long val = 0) {
    n = val % mintP;
    if (n < 0) n += mintP;
  }
  mint& operator+=(mint const& b) {
    n += b.n;
    if (n >= mintP) n -= mintP;
    return *this;
  }
  mint& operator-=(mint const& b) {
    n -= b.n;
    if (n < 0) n += mintP;
    return *this;
  }
  mint& operator*=(mint const& b) {
    n = (long long)n * b.n % mintP;
    return *this;
  }
  mint exp(long long e) { return exp(*this, e); }
  mint inv() { return inv(*this); }
  mint& operator/=(mint const& b) { return *this *= inv(b); }
  friend std::ostream& operator<<(std::ostream& os, mint const& a) {
    return os << (a.n < 0 ? a.n + mintP : a.n);
  }
  friend mint operator+(mint a, mint const b) { return a += b; }
  friend mint operator-(mint a, mint const b) { return a -= b; }
  friend mint operator-(mint const a) { return 0 - a; }
  friend mint operator*(mint a, mint const b) { return a *= b; }
  friend mint operator/(mint a, mint const b) { return a /= b; }
  friend bool operator==(mint const& a, mint const& b) { return a.n == b.n; }
  friend bool operator!=(mint const& a, mint const& b) { return a.n != b.n; }
};
int mint::init_siz = 0;
int mint::mintP = P;
vector<mint> mint::factorial, mint::inverse;
mint comb(int n, int r) {
  if (n < r)
    return 0;
  else {
    return (mint::fac(n) * mint::cinv(r) * mint::cinv(n - r));
  }
}
const int mx = 1e5 + 1;
int n, k;
bool nprime[mx] = {};
int mob[mx] = {};
void init() {
  fill(mob, mob + mx, 1);
  for (int i = 2; i < mx; i++) {
    if (nprime[i]) continue;
    for (int j = i; j < mx; j += i) {
      if (j % (i * i) == 0)
        mob[j] = 0;
      else if (j % i == 0)
        mob[j] *= -1;
      nprime[j] = 1;
    }
  }
}
void solve() {
  cin >> n >> k;
  mint ans = 0;
  for (int p = 1; p * p <= n; p++) {
    if (n % p) continue;
    ans += (mob[p] * comb(n / p - 1, k - 1));
    if (p * p != n) {
      ans += (mob[n / p] * comb(p - 1, k - 1));
    }
  }
  cout << ans << '\n';
}
int main() {
  mint::init(mx);
  init();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  for (int c = 0; c < T; c++) {
    solve();
  }
}
