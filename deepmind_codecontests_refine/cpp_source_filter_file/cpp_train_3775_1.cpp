#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[300005];
long long sum[300005];
long long pw(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  long long b = pw(n, mod - 2);
  for (int i = 1; i <= n; i++) {
    int m = n - i;
    if (m <= i) {
      printf("%lld\n", sum[m] * 1ll * b % mod);
    } else {
      int g = i;
      int mx = 0, mn = 0;
      int sz_mx = m / g + 1, sz_mn = m / g;
      if (m % g == 0)
        mx = 0, mn = g;
      else
        mx = m % g, mn = g - m % g;
      long long ans = 0;
      for (int i = 1; i <= n; i += g) {
        if (i > m) break;
        if (sz_mn == 0) {
          ans = (ans + sum[i + mx - 1] - sum[i - 1]) % mod;
        } else {
          ans =
              (ans + (sum[i + mx - 1] - sum[i - 1]) % mod * 1ll * sz_mx % mod) %
              mod;
          ans = (ans +
                 (sum[i + g - 1] - sum[i + mx - 1]) % mod * 1ll * sz_mn % mod) %
                mod;
        }
        sz_mx--;
        sz_mn--;
      }
      printf("%lld ", ans * 1ll * b % mod);
    }
  }
}
