#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
long long modPow(long long a, long long b, long long MOD) {
  long long ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
  }
  return ret;
}
long long inv5 = 400000003;
long long fit(long long x) { return ((x % MOD) + MOD) % MOD; }
struct five {
  long long a, b;
  five(long long _a = 0, long long _b = 0) { a = fit(_a), b = fit(_b); }
  five operator+(five f) {
    f = f.normal();
    return five(a + f.a, b + f.b).normal();
  }
  five operator+(long long l) {
    l = fit(l);
    return five(a + l, b).normal();
  }
  five operator-(five f) {
    f = f.normal();
    return five(a - f.a, b - f.b).normal();
  }
  five operator-(long long l) {
    l = fit(l);
    return five(a - l, b).normal();
  }
  five operator*(five f) {
    f = f.normal();
    return five(a * f.a + 5 * b % MOD * f.b, a * f.b + b * f.a).normal();
  }
  five operator*(long long l) {
    l = fit(l);
    return five(a * l, b * l).normal();
  }
  bool operator==(five f) {
    f = f.normal();
    return fit(f.a - a) == 0 && fit(f.b - b) == 0;
  }
  five negate() { return five(-a, -b).normal(); }
  five pow(long long n) {
    five ret;
    ret.a = 1;
    five x = *this;
    while (n) {
      if (n & 1) ret = ret * x;
      x = x * x;
      n >>= 1;
    }
    return ret;
  }
  five normal() { return five(fit(a), fit(b)); }
  void show(string s = "") {
    cout << "(" << a << "+" << b << "[5"
         << ")" << s;
  }
  five d5() { return five(b, a * inv5).normal(); }
  five ge() { return five(a, -b).normal(); }
};
five comb[205][205];
five G(long long N, int K) {
  five p, q;
  long long inv2 = (MOD + 1) / 2;
  p.a = p.b = inv2;
  q.a = inv2, q.b = -inv2;
  q = q.normal();
  five ret;
  for (int j = (0); j < (int)(K + 1); j++) {
    five g = p.pow(j) * q.pow(K - j);
    five fh = comb[K][j];
    if ((K - j) & 1) fh = fh * -1;
    if (g == five(1, 0)) {
      ret = ret + fh * N;
    } else {
      five t = g - 1LL;
      long long temp = fit(t.a * t.a - 5 * t.b * t.b);
      temp = modPow(temp, MOD - 2, MOD);
      five now = g * (g.pow(N) - 1LL) * t.ge() * temp;
      ret = ret + now * fh;
    }
  }
  for (int j = (0); j < (int)(K); j++) ret = ret.d5();
  return ret;
}
long long t[205][205];
void solve() {
  long long k, l, r;
  cin >> k >> l >> r;
  five ret;
  for (int i = (0); i < (int)(k + 1); i++) {
    ret = (G(r + 2, i) - G(l + 1, i)) * t[k][i] + ret;
  }
  cout << ret.a << "\n";
}
int main() {
  for (int i = (0); i < (int)(201); i++) {
    comb[i][i] = comb[i][0] = 1;
    for (int j = (1); j < (int)(i); j++)
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
  }
  memset(t, 0, sizeof t);
  t[0][0] = 1;
  for (int i = (1); i < (int)(201); i++) {
    long long inv = modPow(i, MOD - 2, MOD);
    for (int j = (0); j < (int)(i); j++)
      t[i][j] += inv * (MOD + 1 - i) % MOD * t[i - 1][j] % MOD;
    for (int j = (0); j < (int)(i); j++) t[i][j + 1] += inv * t[i - 1][j] % MOD;
    for (int j = (0); j < (int)(i + 1); j++) t[i][j] %= MOD;
  }
  long long N, K;
  int _T = 10;
  for (int CA = (0); CA < (int)(_T); CA++) {
    solve();
  }
  return 0;
}
