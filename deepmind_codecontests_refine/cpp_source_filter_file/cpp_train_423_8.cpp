#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
long long i, j, n, k, z, mod = 174086401, t[3000], f[3000], a[3000];
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    memset(f, 0, sizeof f);
    f[0] = 1;
    a[0] = 1;
    for (j = 1; j <= n; j++) {
      if (j <= i)
        f[j] = a[j - 1];
      else
        f[j] = (a[j - 1] - a[j - min(i, j) - 1] + mod) % mod;
      a[j] = a[j - 1];
      a[j] = (a[j] + f[j]) % mod;
    }
    t[i] = f[n];
  }
  for (i = n; i >= 1; i--) t[i] = (t[i] - t[i - 1] + mod) % mod;
  for (i = 1; i <= n; i++) {
    for (j = 1; (j <= n) && (i * j < k); j++) {
      z = (z + t[i] * t[j] % mod) % mod;
    }
  }
  z = z * 2 % mod;
  cout << z;
  return 0;
}
