#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long *fac, *ifac;
long long powmod(long long b, long long e, long long mod) {
  long long res = 1;
  while (e > 0) {
    if (e % 2 == 1) res = (res * b) % mod;
    e = e / 2;
    b = (b * b) % mod;
  }
  return (res % mod);
}
long long inv(long long n, long long mod) { return powmod(n, mod - 2, mod); }
long long C(long long n, long long r, long long mod) {
  if (n < r) return 0;
  long long ans = fac[n];
  ans = (ans * ifac[r]) % mod;
  ans = (ans * ifac[n - r]) % mod;
  return ans % mod;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, i, j, k, x, y, z;
  string s;
  cin >> s;
  n = s.length();
  fac = (long long *)malloc((2 * n + 1) * sizeof(long long));
  ifac = (long long *)malloc((2 * n + 1) * sizeof(long long));
  fac[0] = 1;
  fac[1] = 1;
  for (i = (2); i < (2 * n + 1); ++i) fac[i] = (i * fac[i - 1]) % mod;
  ifac[0] = ifac[1] = 1;
  for (i = (2); i < (2 * n + 1); ++i)
    ifac[i] = (inv(i, mod) * ifac[i - 1]) % mod;
  long long left[n], right[n + 1];
  if (s[0] == '(')
    left[0] = 1;
  else
    left[0] = 0;
  for (i = (1); i < (n); ++i) {
    left[i] = left[i - 1];
    if (s[i] == '(') left[i]++;
  }
  right[n] = 0;
  if (s[n - 1] == ')')
    right[n - 1] = 1;
  else
    right[n - 1] = 0;
  for (i = n - 2; i >= 0; i--) {
    right[i] = right[i + 1];
    if (s[i] == ')') right[i]++;
  }
  long long ans = 0;
  for (i = (0); i < (n); ++i) {
    if (s[i] == '(') {
      x = left[i];
      y = right[i + 1];
      z = C(x + y - 1, x, mod);
      ans = (ans + z) % mod;
    }
  }
  cout << ans << "\n";
  return 0;
}
