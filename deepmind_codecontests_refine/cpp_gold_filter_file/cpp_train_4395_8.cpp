#include <bits/stdc++.h>
using namespace std;
const int N = 2002, mod = 998244353;
int n, p1, p2, ans, b1[N], b2[N], a[N];
string s;
long long fac[N], ifac[N];
long long pow(long long x, long long y, long long mod) {
  if (y == 0) return 1;
  long long p = pow(x, y / 2, mod);
  return ((p * p % mod) * (1 + (y % 2) * (x - 1))) % mod;
}
void make_fac() {
  fac[0] = 1;
  for (long long i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
  ifac[N - 1] = pow(fac[N - 1], mod - 2, mod);
  for (int i = N - 2; i >= 0; i--)
    ifac[i] = 1ll * ifac[i + 1] * (i + 1ll) % mod;
}
long long C(int k, int n) {
  if (k > n) return 0;
  return fac[n] * ifac[n - k] % mod * ifac[k] % mod;
}
int solve(int x, int y) {
  long long res = 1;
  if (b1[x] > y || b2[n - 1] - b2[x] > y) return 0;
  p1 = y - b1[x], p2 = y - (b2[n - 1] - b2[x]);
  res = C(p1, a[x]) * C(p2, a[n - 1] - a[x]) % mod;
  return res;
}
int main() {
  make_fac();
  cin >> s;
  n = s.size();
  b1[0] = (s[0] == '(');
  b2[0] = (s[0] == ')');
  a[0] = (s[0] == '?');
  for (long long i = 1; i < n; i++) {
    b1[i] = b1[i - 1] + (s[i] == '(');
    b2[i] = b2[i - 1] + (s[i] == ')');
    a[i] = i + 1 - b1[i] - b2[i];
  }
  for (long long i = 0; i < n - 1; i++)
    for (long long j = 1; j < n / 2 + 1; j++)
      ans = (ans + (solve(i, j) * j % mod)) % mod;
  cout << ans;
}
