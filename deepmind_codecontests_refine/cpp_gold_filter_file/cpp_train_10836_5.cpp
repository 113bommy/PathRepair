#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const long double PI = acos(-1);
const int N = 1e6 + 5;
const long long MOD = 998244353;
const int INF = 0x3f3f3f3f;
long long n, a[N], p[N], pot[N], f[N], g[N];
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  if (n == 1) return printf("%lld\n", a[1]), 0;
  p[1] = a[1];
  for (int i = 2; i <= n; i++) p[i] = (p[i - 1] + a[i]) % MOD;
  pot[0] = 1;
  for (int i = 1; i <= n; i++) pot[i] = (2ll * pot[i - 1]) % MOD;
  long long ans = p[n] % MOD;
  ans = (ans + (p[n - 1] * 2) % MOD) % MOD;
  for (long long i = n - 2; i > 0; i--) {
    long long j = n - i;
    long long term = ((j - 1) * pot[j - 2]) % MOD;
    term = (term + pot[j]) % MOD;
    ans = (ans + (p[i] * term) % MOD) % MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
