#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int maxn = 1e6 + 3;
using namespace std;
int bj[maxn];
long long a[100010], f[maxn], inv[maxn], pri[maxn];
long long pre[maxn], per[maxn];
long long BM(long long k) {
  pre[0] = 1;
  per[0] = 1;
  for (int i = 1; i <= maxn; i++) {
    pre[i] = (k - i) % mod;
    per[i] = (k - (maxn + 1 - i)) % mod;
  }
  for (int i = 1; i <= maxn; i++) {
    pre[i] = pre[i - 1] * pre[i] % mod;
    per[i] = per[i - 1] * per[i] % mod;
  }
  long long ans = 0;
  for (int i = 1; i <= maxn; i++) {
    if ((maxn - i) & 1)
      ans = (ans -
             f[i] * pre[i - 1] % mod * per[maxn - i] % mod * inv[i - 1] % mod *
                 inv[maxn - i] % mod +
             mod) %
            mod;
    else
      ans = (ans + f[i] * pre[i - 1] % mod * per[maxn - i] % mod * inv[i - 1] %
                       mod * inv[maxn - i] % mod) %
            mod;
  }
  return ans;
}
int ksm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  inv[0] = 1;
  inv[1] = 1;
  for (int i = 2; i <= maxn; i++)
    inv[i] = (mod - mod / i) * 1ll * inv[mod % i] % mod;
  for (int i = 2; i <= maxn; i++) inv[i] = inv[i - 1] * inv[i] % mod;
  int n, k;
  scanf("%d%d", &n, &k);
  if (n <= maxn) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += ksm(i, k);
      ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
  }
  int cnt = 0;
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= maxn; i++) {
    if (!bj[i]) f[i] = ksm(i, k), pri[++cnt] = i;
    for (int j = 1; j <= cnt && i * pri[j] <= maxn; j++) {
      bj[i * pri[j]] = 1;
      f[i * pri[j]] = f[i] * f[pri[j]] % mod;
      if (i % pri[j] == 0) break;
    }
  }
  for (int i = 2; i <= maxn; i++) f[i] = (f[i - 1] + f[i]) % mod;
  printf("%lld\n", BM(n));
  return 0;
}
