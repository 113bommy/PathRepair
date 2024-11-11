#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000005;
int n, k;
int ans = 0, mod = 1e9 + 7;
int notPrime[MAXN], prime[MAXN], tot;
int mu[MAXN], p[MAXN], f[MAXN * 2];
void initMu(int n) {
  notPrime[1] = mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!notPrime[i]) prime[tot++] = i, mu[i] = -1;
    for (int j = 0; j < tot && i * prime[j] <= n; j++) {
      notPrime[i * prime[j]] = 1;
      if (i % prime[j])
        mu[i * prime[j]] = -mu[i];
      else {
        mu[i * prime[j]] = 0;
        break;
      }
    }
  }
}
int qpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = (long long)res * a % mod;
    a = (long long)a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &k);
  initMu(k);
  for (int i = 1; i <= k; i++) p[i] = qpow(i, n);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; i * j <= k; j++) {
      f[i * j] = (f[i * j] + (long long)p[j] * (mu[i] + mod) % mod) % mod;
      f[i * j] =
          (f[i * j] - (long long)p[j - 1] * (mu[i] + mod) % mod + mod) % mod;
    }
  }
  for (int i = 1; i <= k; i++) {
    f[i] = (f[i] + f[i - 1]) % mod;
    ans = (ans + (f[i] ^ i) % mod) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
