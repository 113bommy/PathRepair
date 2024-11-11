#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 1000000007;
long long mpow(long long p, long long q) {
  long long ans = 1;
  while (q) {
    if (q & 1) ans = ans * p % mod;
    q >>= 1;
    p = p * p % mod;
  }
  return ans;
}
long long fac[2000005];
inline long long rev(int n) { return mpow(n, mod - 2); }
inline long long C(int m, int n) {
  return fac[m] * rev(fac[n] * fac[m - n] % mod) % mod;
}
int main() {
  int n, a = 0;
  scanf("%d", &n);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
  for (int i = 0, k; i < n; ++i) {
    scanf("%d", &k);
    if (k == 1) ++a;
  }
  long long ans = 0;
  for (int k = 0; k <= a; ++ ++k)
    ans +=
        C(a, k) * fac[k] % mod * rev(mpow(2, k >> 1) * fac[k >> 1] % mod) % mod;
  cout << ans * fac[n] % mod * rev(fac[a]) % mod << endl;
  return 0;
}
