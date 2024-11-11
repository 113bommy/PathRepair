#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
  return x;
}
const int N = 1e7 + 5;
const long long mod = 998244353;
int ksm(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return ans;
}
int prime[N], kth[N], cnt;
bool is_not_prime[N];
void sieve(int n, int k) {
  is_not_prime[0] = is_not_prime[1] = 1;
  kth[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!is_not_prime[i]) prime[++cnt] = i, kth[i] = ksm(i, k);
    for (int j = 1; j <= cnt && 1ll * prime[j] * i <= n; j++) {
      if (i % prime[j] == 0) break;
      prime[i * prime[j]] = 1;
      kth[i * prime[j]] = 1ll * kth[i] * kth[prime[j]] % mod;
    }
  }
}
int inv[N];
void preinv(int n) {
  inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
}
long long n, m, k, p, q, ivq, ivp;
int S[N];
int main() {
  n = read(), m = read(), k = read();
  sieve(k, k);
  p = ksm(m, mod - 2), q = (1 - p + mod) % mod, ivq = ksm(q, mod - 2),
  ivp = ksm(p, mod - 2);
  preinv(k);
  if (m == 1)
    printf("%d\n", ksm(n, k));
  else if (n <= k) {
    long long ans = 0;
    for (int i = 0, xs1 = 1, xs2 = ksm(q, n), xs3 = 1, xs4 = 1; i <= n; i++,
             xs1 = 1ll * xs1 * p % mod, xs2 = 1ll * xs2 * ivq % mod,
             xs3 = 1ll * xs3 * (n - i + 1) % mod,
             xs4 = 1ll * xs4 * inv[i] % mod)
      ans =
          (ans + 1ll * xs3 * xs4 % mod * kth[i] % mod * xs1 % mod * xs2 % mod) %
          mod;
    cout << ans;
  } else {
    S[k] = 1;
    for (int i = k - 1, xs1 = mod - p,
             xs2 = 1ll * (n - i - 1) * inv[k - i] % mod;
         i >= 0; i--, xs1 = 1ll * xs1 * (mod - p) % mod,
             xs2 = 1ll * xs2 * (n - i - 1) % mod * inv[k - i] % mod)
      S[i] =
          (1ll * S[i + 1] * (1 - p + mod) % mod + 1ll * xs2 * xs1 % mod) % mod;
    long long ans = 0;
    for (int i = 0, xs1 = 1, xs2 = 1; i <= k; i++,
             xs1 = 1ll * xs1 * (n - i + 1) % mod * inv[i] % mod,
             xs2 = 1ll * xs2 * p % mod)
      ans = (ans + 1ll * kth[i] * xs1 % mod * S[i] % mod * xs2 % mod) % mod;
    cout << ans;
  }
  return 0;
}
