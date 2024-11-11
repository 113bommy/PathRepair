#include <bits/stdc++.h>
const int N(1e6 + 10), Mod(998244353);
int fastpow(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1, x = 1ll * x * x % Mod)
    if (y & 1) ans = 1ll * ans * x % Mod;
  return ans;
}
int n, L[N], R[N], P[N], Q[N], fac[N], inv[N], ans;
char s[N];
int C(int n, int m) {
  if (n < m || m < 0 || n < 0) return 0;
  return 1ll * fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}
int main() {
  std::scanf("%s", s + 1), n = strlen(s + 1), fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % Mod;
  inv[n] = fastpow(fac[n], Mod - 2);
  for (int i = n - 1; i; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % Mod;
  for (int i = 1; i <= n; i++)
    L[i] = L[i - 1] + (s[i] == '('), P[i] = P[i - 1] + (s[i] == '?');
  for (int i = n; i; i--)
    R[i] = R[i + 1] + (s[i] == ')'), Q[i] = Q[i + 1] + (s[i] == '?');
  for (int i = 1; i < n; i++)
    ans = (ans + 1ll * L[i] * C(P[i] + Q[i + 1], Q[i + 1] + R[i + 1] - L[i])) %
          Mod;
  for (int i = 1; i < n; i++)
    ans = (ans + 1ll * P[i] *
                     C(P[i] + Q[i + 1] - 1, Q[i + 1] + R[i + 1] - L[i] - 1)) %
          Mod;
  std::printf("%d\n", ans);
  return 0;
}
