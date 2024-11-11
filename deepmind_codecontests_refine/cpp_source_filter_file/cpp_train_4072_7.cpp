#include <bits/stdc++.h>
using namespace std;
const int N = 300009, mod = 1e9 + 7;
int a[N], n, f[N], b[N], inv[N], fac[N];
inline void Init() {
  fac[0] = inv[0] = inv[1] = 1;
  for (int i = 1; i <= 7; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 2; i <= 7; i++)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 2; i <= 7; i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
}
inline int C(int n, int m) {
  if (m > n) return 0;
  return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
inline int check(int x) {
  for (int i = N - 1; i >= 1; i--) {
    f[i] = C(b[i], x);
    for (int j = 2; j * i < N; j++) f[i] = (f[i] - f[i * j] + mod) % mod;
  }
  return f[1];
}
int main() {
  Init();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[a[i]]++;
  for (int i = 1; i < N; i++)
    for (int j = 2; j * i < N; j++) b[i] += b[i * j];
  int ans = -1;
  for (int i = 1; i <= 7; i++) {
    if (check(i)) {
      ans = i;
      break;
    }
  }
  printf("%d", ans);
  return 0;
}
