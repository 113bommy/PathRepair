#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int getLength(long long n) {
  int c = 0;
  while (n > 0) {
    c += 1;
    n /= 10;
  }
  return c;
}
long long m10 = 1000000;
inline long long mul(long long a, long long b, long long mod) {
  long long ans = 0;
  while (b > 0) {
    if (b & 1) {
      ans = ans + a;
      if (ans >= mod) ans -= mod;
    }
    b >>= 1;
    a <<= 1;
    if (a >= mod) a -= mod;
  }
  return ans;
}
long long pow_(long long a, long long n, long long mod) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans = mul(ans, a, mod);
    n >>= 1;
    a = mul(a, a, mod);
  }
  return ans;
}
long long solve(long long g, long long y, long long p, long long i) {
  long long P = 1;
  for (int j = 0; j < (i); ++j) P *= p;
  y %= P;
  if (i == 1) {
    long long ans = 1;
    for (int j = 0; j < (p); ++j) {
      if (ans == y) return j;
      ans = ans * g % p;
    }
    assert(0);
  }
  long long phi = 1;
  for (int j = 0; j < (i - 2); ++j) phi *= p;
  phi *= (p - 1);
  long long x = solve(g, y, p, i - 1);
  long long c = pow_(g, phi, P);
  long long ans = pow_(g, x, P);
  for (int j = 0; j < (p); ++j) {
    if (ans == y) return x + phi * j;
    ans = mul(ans, c, P);
  }
  assert(0);
}
void solve(long long x) {
  int n = getLength(x);
  int m = 6;
  long long y = x * m10 / (1ll << (n + m));
  while (y * (1ll << (n + m)) < x * m10 || y % 5 == 0) ++y;
  long long ans1 = solve(2, y, 5, n + m) + n + m;
  cout << ans1 << "\n";
}
int main() {
  int T = 20;
  scanf("%d", &T);
  while (T--) {
    long long n;
    scanf("%lld", &n);
    solve(n);
  }
  return 0;
}
