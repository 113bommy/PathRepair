#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
long long fac[2005];
long long qp(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long inv(long long x) { return qp(x, mod - 2); }
long long c(long long m, long long n) {
  return fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod;
}
int n, m;
void solve() { printf("%lld\n", c(2 * m, n + 2 * m - 1)); }
int main() {
  fac[0] = 1;
  for (int i = 1; i <= 2005; i++) fac[i] = fac[i - 1] * i % mod;
  while (~scanf("%d %d", &n, &m)) solve();
  return 0;
}
