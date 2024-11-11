#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
const long long mod = 1e9 + 7;
long long jie[N], inv[N], W[N], Wn[N], F[N];
long long C(long long m, long long n) {
  if (m < n) return 0;
  return jie[m] * inv[n] % mod * inv[m - n] % mod;
}
void pre() {
  jie[0] = 1;
  inv[0] = inv[1] = 1;
  for (int i = (2); i < (N); ++i) inv[i] = -mod / i * inv[mod % i] % mod + mod;
  for (int i = (1); i < (N); ++i)
    inv[i] = inv[i] * inv[i - 1] % mod, jie[i] = jie[i - 1] * i % mod;
}
long long quick(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  long long f, w, h;
  scanf("%lld%lld%lld", &f, &w, &h);
  if (f == 0) {
    if (w > h)
      printf("1");
    else
      printf("0");
    return 0;
  }
  if (w == 0) {
    printf("0");
    return 0;
  }
  pre();
  for (int i = (1); i < (f + 1); ++i) {
    F[i] = C(f - 1, i - 1);
  }
  for (int i = (1); i < (w + 1); ++i) {
    W[i] = C(w - 1, i - 1);
    if (w <= h * i) continue;
    Wn[i] = C(w - 1 - h * i, i - 1);
  }
  long long ans = 0, tot = 0;
  for (int i = (1); i < (f + 1); ++i)
    ans = (ans + F[i] * Wn[i] * 2 % mod) % mod,
    tot = (tot + F[i] * W[i] * 2) % mod;
  for (int i = (2); i < (w + 1); ++i)
    ans = (ans + F[i - 1] * Wn[i] % mod) % mod,
    tot = (tot + F[i - 1] * W[i]) % mod;
  for (int i = (2); i < (f + 1); ++i)
    ans = (ans + F[i] * Wn[i - 1] % mod) % mod,
    tot = (tot + F[i] * W[i - 1]) % mod;
  if (ans < 0) ans += mod;
  ans = ans * quick(tot, mod - 2) % mod;
  cout << ans;
}
