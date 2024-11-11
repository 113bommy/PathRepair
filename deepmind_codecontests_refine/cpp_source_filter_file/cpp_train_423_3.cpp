#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
const int mod = 998244353;
long long f[2][N], g[N];
int power(int a, int n) {
  int b = 1;
  for (; n; n >>= 1, a = 1LL * a * a % mod) {
    if (n & 1) {
      b = 1LL * b * a % mod;
    }
  }
  return b;
}
int main() {
  int n, K;
  scanf("%d %d", &n, &K);
  for (int i = 1; i <= n; i++) {
    int t = 0;
    memset(f[t], 0, sizeof f[t]);
    f[t][1] = 2;
    for (int j = 1; j < n; j++) {
      memset(f[t ^ 1], 0, sizeof f[t ^ 1]);
      for (int k = 1; k <= i; k++) {
        if (k + 1 <= i) {
          (f[t ^ 1][k + 1] += f[t][k]) %= mod;
        }
        (f[t ^ 1][1] += f[t][k]) %= mod;
      }
      t ^= 1;
    }
    for (int k = 1; k <= i; k++) {
      (g[i] += f[t][k]) %= mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= min(n, K); i++) {
    (ans += (g[i] - g[i - 1] + mod) * g[min(n, K / i - (K % i == 0))]) % mod;
  }
  (ans += mod) %= mod;
  ans = 1LL * ans * power(2, mod - 2) % mod;
  printf("%lld\n", ans);
  return 0;
}
