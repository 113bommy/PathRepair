#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353LL;
long long inv(long long x) {
  long long y = mod - 2;
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
int n, a[100005], sume, m;
long long f[300005], e[100005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    m += a[i];
  }
  f[0] = n - 1;
  for (int i = 1; i < m; i++) {
    long long ss = (n - 1) * inv(m - i) % mod;
    f[i] = (ss * m % mod + ss * i % mod * f[i - 1] % mod) % mod;
  }
  f[m] = 0;
  for (int i = m - 1; i >= 0; i--) f[i] = (f[i] + f[i + 1]) % mod;
  long long c = f[0];
  for (int i = 1; i <= n; i++) {
    e[i] = f[a[i]];
    sume = (sume + e[i]) % mod;
  }
  sume = (sume + mod - (c * (n - 1) % mod)) % mod;
  sume = sume * inv(n) % mod;
  printf("%d", (int)sume);
  return 0;
}
