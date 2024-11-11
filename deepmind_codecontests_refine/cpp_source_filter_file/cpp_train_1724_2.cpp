#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
int sqr;
int k, C[655][655], S1[655][655], fac[655], m;
int inv(int x) { return x == 1 ? 1 : (ll)(mod - mod / x) * inv(mod % x) % mod; }
struct exComplex {
  int a, b;
  exComplex(int x = 0, int y = 0) {
    a = x;
    b = y;
  }
  exComplex operator+(const exComplex &y) const {
    return exComplex((a + y.a) % mod, (b + y.b) % mod);
  }
  exComplex operator*(const exComplex &y) const {
    return exComplex(((ll)a * y.a % mod + (ll)sqr * b % mod * y.b % mod) % mod,
                     ((ll)b * y.a % mod + (ll)a * y.b % mod) % mod);
  }
  exComplex operator/(const int &y) const {
    int i = inv(y);
    return exComplex((ll)a * i % mod, (ll)b * i % mod);
  }
};
using num = exComplex;
num A, B, alpha, beta, Ap[655], Bp[655], al[655], be[655];
num qpow(num x, ll y) {
  if (y == 0) return num(1, 0);
  num d = qpow(x, y >> 1);
  d = d * d;
  if (y & 1) d = d * x;
  return d;
}
std::pair<num, num> sum(num w, ll n) {
  if (n == 1) return {w, w};
  auto P = sum(w, n / 2);
  num L = P.first;
  num pw = P.second;
  L = L + pw * L;
  pw = pw * pw;
  if (n & 1) {
    pw = pw * w;
    L = L + pw;
  }
  return {L, pw};
}
int calc(ll n) {
  if (n == 0) return 0;
  num ans;
  for (int i = 0; i <= k; ++i) {
    Ap[i] = qpow(A, i);
    Bp[i] = qpow(B, i);
    al[i] = qpow(alpha, i);
    be[i] = qpow(beta, i);
  }
  for (int j = 0; j <= k; ++j) {
    auto det = [](int x) { return x & 1 ? mod - 1 : 1; };
    int coef = (ll)det(k - j) * S1[k][j] % mod;
    for (int x = 0; x <= j; ++x) {
      num c2 = Ap[x] * Bp[j - x];
      num w = al[x] * be[j - x];
      ans = ans + num(C[j][x], 0) * num(coef, 0) * sum(w, n).first * c2;
    }
  }
  return (ll)ans.a * inv(fac[k]) % mod;
}
void solve() {
  ll l, r;
  scanf("%d%lld%lld", &k, &l, &r);
  l++;
  r++;
  fac[0] = 1;
  for (int i = 1; i <= k; ++i) fac[i] = (ll)fac[i - 1] * i % mod;
  for (int i = 0; i <= k; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  S1[0][0] = 1;
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= i; ++j)
      S1[i][j] = (S1[i - 1][j - 1] + (ll)S1[i - 1][j] * (i - 1) % mod) % mod;
  int ans = (calc(r) - calc(l - 1) + mod) % mod;
  printf("%d\n", ans);
}
int main() {
  sqr = 5;
  A = num(5, 1) / 10;
  B = num(5, mod - 1) / 10;
  alpha = num(1, 1) / 2;
  beta = num(1, mod - 1) / 2;
  solve();
  return 0;
}
