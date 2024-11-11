#include <bits/stdc++.h>
long long pow(long long a, long long n, long long mod) {
  long long t;
  for (t = 1; n; n >>= 1, a *= a, a %= mod) n & 1 && (t *= a, t %= mod);
  return t;
}
int main() {
  long long N, A, B, K, i, l, t, ans, mod = 1000000009;
  char s[100100];
  for (scanf("%lld%lld%lld%lld%s", &N, &A, &B, &K, s), ans = i = 0;
       i <= N && s[i]; i++)
    s[i] == '+' ? ans += pow(A, N - i, mod) * pow(B, i, mod)
                : (ans -= pow(A, N - i, mod) * pow(B, i, mod)),
        ans %= mod;
  if (i <= N)
    for (l = i, t = pow(pow(A, i, mod), mod - 2, mod) * pow(B, i, mod) % mod,
        ans = t - 1 % mod ? (ans * pow(t, (N + 1) / i, mod) - ans) % mod *
                                pow(t - 1, mod - 2, mod) % mod
                          : (N + 1) / i * ans % mod,
        i += (N + 1) / i * i;
         i <= N; i++)
      s[i % l] == '+' ? ans += pow(A, N - i, mod) * pow(B, i, mod)
                      : (ans -= pow(A, N - i, mod) * pow(B, i, mod)),
          ans %= mod;
  printf("%lld\n", (ans + mod) % mod);
}
