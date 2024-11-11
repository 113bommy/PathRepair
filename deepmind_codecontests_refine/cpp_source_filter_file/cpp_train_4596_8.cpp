#include <bits/stdc++.h>
using namespace std;
int n, k, x, y, z, a[200005], mx, b[200005], c[200005];
long long f1[200005], f2[200005], f3[200005], ans[200005];
long long ksm(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % 998244353)
    if (y & 1) ret = ret * x % 998244353;
  return ret;
}
void FWT(long long *f) {
  int i, j, k, rr;
  long long x;
  for (i = 1; i < mx; i <<= 1)
    for (rr = i << 1, j = 0; j < mx; j += rr)
      for (k = 0; k < i; ++k)
        x = f[j | k], f[j | k] += f[j | i | k], f[i | j | k] = x - f[i | j | k];
}
void IFWT(long long *f) {
  int i, j, k, rr;
  long long x;
  for (i = 1; i < mx; i <<= 1)
    for (rr = i << 1, j = 0; j < mx; j += rr)
      for (k = 0; k < i; ++k)
        x = f[j | k], f[j | k] += f[j | i | k], f[i | j | k] = x - f[i | j | k],
        (f[j | k] *= 499122177) %= 998244353,
        (f[i | j | k] *= 499122177) %= 998244353;
}
int i, g1, g2, g3, g4, A;
int main() {
  for (cin >> n >> k >> x >> y >> z, mx = 1 << k, i = 1; i <= n; ++i)
    cin >> a[i] >> b[i] >> c[i], A ^= a[i], b[i] ^= a[i], c[i] ^= a[i];
  for (i = 1; i <= n; ++i) ++f1[b[i]];
  for (i = 1; i <= n; ++i) ++f2[c[i]];
  for (i = 1; i <= n; ++i) ++f3[b[i] ^ c[i]];
  FWT(f1);
  FWT(f2);
  FWT(f3);
  for (i = 0; i < mx; ++i) {
    g1 = (n + f1[i] + f2[i] + f3[i] >> 2);
    g2 = (n + f1[i] - f2[i] - f3[i] >> 2);
    g3 = (n + f2[i] - f1[i] - f3[i] >> 2);
    g4 = (n + f3[i] - f1[i] - f2[i] >> 2);
    ans[i] = ksm(x + y + z, g1) * ksm(x + y - z, g2) % 998244353 *
             ksm(x - y + z, g3) % 998244353 * ksm(x - y - z, g4) % 998244353;
  }
  for (IFWT(ans), i = 0; i < mx; ++i)
    cout << (ans[i ^ A] + 998244353) % 998244353 << " ";
}
