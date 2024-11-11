#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 16) + 5, P = 998244353;
int n, K, c, a[N], w[N][20], mx[N], id[N], f[20][N], ans[N];
int fac[N], inv[N], ifac[N];
int C(int k1, int k2) {
  if (k1 < 0 || k2 < 0 || k1 - k2 < 0) return 0;
  return 1LL * fac[k1] * ifac[k2] % P * ifac[k1 - k2] % P;
}
void addx(int& k1, int k2) { (k1 += k2) >= P && (k1 -= P); }
void subx(int& k1, int k2) { (k1 -= k2) < 0 && (k1 += P); }
int fpow(int k1, int k2) {
  int k3 = 1;
  for (; k2; k2 >>= 1, k1 = 1LL * k1 * k1 % P)
    if (k2 & 1) k3 = 1LL * k3 * k1 % P;
  return k3;
}
int main() {
  fac[0] = fac[1] = inv[0] = inv[1] = ifac[0] = ifac[1] = 1;
  for (int i = 2; i < N; ++i)
    fac[i] = 1LL * fac[i - 1] * i % P,
    inv[i] = 1LL * (P - P / i) * inv[P % i] % P,
    ifac[i] = 1LL * ifac[i - 1] * inv[i] % P;
  scanf("%d%d%d", &n, &K, &c);
  int sum = 0;
  for (int i = (1); i <= (n); ++i) {
    scanf("%d", a + i);
    sum ^= a[i];
    for (int j = (1); j <= (K); ++j) w[i][j] = a[i] ^ (a[i] - j), w[i][j] >>= 1;
    mx[i] = *max_element(w[i] + 1, w[i] + 1 + K);
    id[i] = i;
  }
  sort(id + 1, id + 1 + n, [&](int k1, int k2) { return mx[k1] < mx[k2]; });
  int lim = 1;
  f[0][0] = 1;
  for (int _ = (1); _ <= (n); ++_) {
    int i = id[_];
    int nlim = lim;
    while (nlim <= mx[i]) nlim <<= 1;
    for (int j = (K - 1); j >= (0); --j)
      for (int k = (0); k <= (lim - 1); ++k)
        for (int take = (1); take <= (K - j); ++take) {
          addx(f[j + take][k ^ w[i][take]], 1LL * f[j][k] * C(K - j, take) % P);
        }
    lim = nlim;
  }
  int tot = 0;
  for (int i = (0); i <= ((1 << c) - 1); ++i) addx(tot, f[K][i]);
  int itot = fpow(tot, P - 2);
  for (int i = (0); i <= ((1 << c) - 1); ++i)
    f[K][i] = 1LL * f[K][i] * itot % P;
  for (int i = (0); i <= ((1 << lim) - 1); ++i) {
    int x = (i << 1) ^ sum;
    if (K & 1) x ^= 1;
    ans[x] = f[K][i];
  }
  for (int i = (0); i <= ((1 << c) - 1); ++i) printf("%d ", ans[i]);
  return 0;
}
