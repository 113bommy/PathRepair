#include <bits/stdc++.h>
namespace chiaro {
const int ha = 1e9 + 7;
int n, k;
int f[1000010];
int pre[1000010], suf[1000010];
int inv[1000010];
inline long long ksm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % ha;
    a = a * a % ha;
    b >>= 1;
  }
  return ans;
}
inline int sign(int x) { return ((x & 1) ? -1 : 1); }
inline void setting() { return; }
inline int main() {
  setting();
  std::cin >> n >> k;
  if (k == 0) printf("%d\n", n), exit(0);
  f[1] = 1;
  for (int i = 2; i <= k + 2; i++) f[i] = (f[i - 1] + ksm(i, k)) % ha;
  int mul = 1;
  inv[0] = 1;
  for (int i = 1; i <= k + 2; i++) mul = 1ll * mul * i % ha;
  inv[k + 2] = ksm(mul, ha - 2);
  for (int i = k + 1; i; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % ha;
  pre[0] = 1;
  for (int i = 1; i <= k + 2; i++) pre[i] = 1ll * pre[i - 1] * (n - i) % ha;
  suf[k + 3] = 1;
  for (int i = k + 2; i; i--) suf[i] = 1ll * suf[i + 1] * (n - i) % ha;
  long long res = 0;
  for (int i = 1; i <= k + 2; i++) {
    long long tmp = 0;
    tmp = 1ll * f[i] * inv[i - 1] % ha * inv[k + 2 - i] % ha * pre[i - 1] % ha *
          suf[i + 1] % ha;
    res = (res + tmp * sign(k + 2 - i)) % ha;
  }
  printf("%d\n", (res + ha) % ha);
  return 0;
}
}  // namespace chiaro
signed main() { return chiaro::main(); }
