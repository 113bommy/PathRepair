#include <bits/stdc++.h>
using namespace std;
const long long N = 205, mod = 1000000007;
long long k, fact[N], inv[N], S[N][N];
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res = res * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return res;
}
struct num {
  long long a, b;
  num(long long a = 0, long long b = 0) : a(a), b(b) {}
  friend num operator+(num a, num b) {
    return num((a.a + b.a) % mod, (a.b + b.b) % mod);
  }
  friend num operator-(num a, num b) {
    return num((a.a - b.a + mod) % mod, (a.b - b.b + mod) % mod);
  }
  friend num operator*(num a, num b) {
    return num((a.a * b.a % mod + 5 * a.b % mod * b.b % mod) % mod,
               (a.a * b.b % mod + a.b * b.a % mod) % mod);
  }
  friend num operator/(num a, num b) {
    long long x = power(
        (b.a * b.a % mod - 5 * b.b % mod * b.b % mod + mod) % mod, mod - 2);
    return num(
        (a.a * b.a % mod - 5 * a.b % mod * b.b % mod + mod) % mod * x % mod,
        (a.b * b.a % mod - a.a * b.b % mod + mod) % mod * x % mod);
  }
  friend num operator^(num a, long long b) {
    num res = num(1, 0);
    while (b) {
      if (b % 2) res = res * a;
      a = a * a;
      b /= 2;
    }
    return res;
  }
} sqrt5, s1, s2, s;
long long C(long long n, long long m) {
  return fact[n] * inv[m] % mod * inv[n - m] % mod;
}
long long solve(long long n) {
  long long ans = 0;
  for (long long i = 0; i <= k; i++) {
    num res = num(0, 0);
    for (long long j = 0; j <= i; j++) {
      s = ((s1 ^ j) * (s2 ^ (i - j)));
      if (s.a == 1 && s.b == 0)
        s = n % mod;
      else
        s = ((s ^ 3) - (s ^ (n + 3))) / (1 - s);
      s = s * (sqrt5 ^ i);
      s = s * C(i, j);
      if ((i - j) % 2 == 1) s = mod - s;
      res = res + s;
    }
    ans = (ans + S[k][i] * res.a % mod) % mod;
  }
  ans = ans * inv[k] % mod;
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  long long l, r;
  cin >> k >> l >> r;
  fact[0] = 1;
  for (long long i = 1; i <= k; i++) fact[i] = fact[i - 1] * i % mod;
  inv[k] = power(fact[k], mod - 2) % mod;
  for (long long i = k - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  S[0][0] = 1;
  for (long long i = 1; i <= k; i++)
    for (long long j = 1; j <= i; j++)
      S[i][j] = (S[i - 1][j - 1] - S[i - 1][j] * (i - 1) % mod + mod) % mod;
  sqrt5.b = power(5, mod - 2);
  s1.a = s1.b = s2.a = s2.b = power(2, mod - 2);
  s2.b = mod - s2.b;
  long long ans = (solve(r) - solve(l - 1) + mod) % mod;
  cout << ans;
  return 0;
}
