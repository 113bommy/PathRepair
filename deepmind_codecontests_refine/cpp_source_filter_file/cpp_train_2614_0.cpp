#include <bits/stdc++.h>
using namespace std;
const long long N = 100005, mod = 1000000007;
long long fact[N], inv[N];
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res = res * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return res;
}
long long C(long long n, long long m) {
  if (n == -1 && m == -1) return 1;
  return fact[n] * inv[m] % mod * inv[n - m] % mod;
}
long long S(long long a, long long b, long long c, long long d) {
  if (a < 0 || b < 0 || c < 0 || d < 0) return 0;
  return C(d + b, b) * C(a + c - 1, c - 1) % mod;
}
long long solve(string s, long long A, long long B, long long C, long long D) {
  long long n = s.length(), ans = 0;
  if (!(B == C || B == C - 1)) return 0;
  if (n > A + B + C + D + 1) return S(A, B, C, D);
  if (n < A + B + C + D + 1) return 0;
  for (long long i = 1; i < n; i++) {
    if (s[i] == '1') {
      if (s[i - 1] == '0')
        --A;
      else
        --C;
      if (i != n - 1) --B;
      if (B == C || B == C - 1) ans = (ans + S(A, B, C + 1, D));
      if (i != n - 1) ++B;
      if (s[i - 1] == '0') {
        ++A;
        --B;
      } else {
        ++C;
        --D;
      }
    } else {
      if (s[i - 1] == '0')
        --A;
      else
        --C;
    }
    if (A < 0 || B < 0 || C < 0 || D < 0) break;
  }
  if (A == 0 && B == 0 && C == 0 && D == 0) ++ans;
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  string s, t;
  long long A, B, C, D, ans = 0, n;
  cin >> s >> t >> A >> B >> C >> D;
  n = A + B + C + D;
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
  inv[n] = power(fact[n], mod - 2);
  for (long long i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  ans = (solve(t, A, B, C, D) - solve(s, A, B, C, D) + mod) % mod;
  n = s.length();
  for (long long i = 1; i < n; i++) {
    if (s[i - 1] == '0') {
      if (s[i] == '0')
        --A;
      else
        --B;
    } else {
      if (s[i] == '0')
        --C;
      else
        --D;
    }
  }
  if (A == 0 && B == 0 && C == 0 && D == 0) ans = (ans + 1) % mod;
  cout << ans;
  return 0;
}
