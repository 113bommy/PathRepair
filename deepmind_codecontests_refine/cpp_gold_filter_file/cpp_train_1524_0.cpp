#include <bits/stdc++.h>
using namespace std;
int n, k;
long long sum, ans, fac[1000005], inv[1000005], f[1000005];
long long Pow(long long a, int b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return res;
}
long long A(int n, int m) { return fac[n] * inv[n - m] % 1000000007; }
int main() {
  scanf("%d%d", &n, &k);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % 1000000007;
  inv[n] = Pow(fac[n], 1000000007 - 2);
  for (int i = n; i; i--) inv[i - 1] = inv[i] * i % 1000000007;
  for (int i = k + 2; i <= n; i++) {
    sum = (sum + f[i - 1] * inv[i - 2] % 1000000007) % 1000000007;
    sum = (sum - f[i - k - 1] * inv[i - k - 2] % 1000000007 + 1000000007) %
          1000000007;
    f[i] = ((i - k - 1) * fac[i - 2] % 1000000007 +
            fac[i - 2] * sum % 1000000007) %
           1000000007;
    ans = (ans + A(n - 1, n - i) * f[i] % 1000000007) % 1000000007;
  }
  printf("%d\n", ans);
  return 0;
}
