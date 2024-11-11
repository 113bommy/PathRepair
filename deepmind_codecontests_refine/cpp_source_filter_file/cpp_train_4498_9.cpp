#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 998244353;
const double pi = 3.1415926535897932, eps = 1e-6;
void chmax(int &x, int y) {
  if (x < y) x = y;
}
void chmin(int &x, int y) {
  if (x > y) x = y;
}
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)ret * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return ret;
}
int n, k, a[200005], fac[200005], inv[200005], dif, ans;
int pw2[200005], pwk2[200005], pwk[200005];
int C(int x, int y) {
  return (long long)fac[x] * inv[y] % mod * inv[x - y] % mod;
}
int get(int x) {
  if (x % 2 == 0)
    return ((pw2[x] - C(x, x / 2) + mod) % mod * 499122177ll) % mod;
  return x == 0 ? 0 : pw2[x - 1];
}
int main() {
  scanf("%d%d", &n, &k);
  if (k == 1) {
    puts("0");
    return 0;
  }
  for (int(i) = (1); (i) <= (n); (i)++) scanf("%d", a + i);
  for (int(i) = (1); (i) <= (n); (i)++)
    if (a[i] != a[i % n + 1]) dif++;
  fac[0] = 1;
  for (int(i) = (1); (i) <= (n); (i)++)
    fac[i] = (long long)fac[i - 1] * i % mod;
  inv[n] = qpow(fac[n], mod - 2);
  for (int(i) = (n - 1); (i) >= (0); (i)--)
    inv[i] = (long long)inv[i + 1] * (i + 1) % mod;
  pw2[0] = 1;
  for (int(i) = (1); (i) <= (n); (i)++) pw2[i] = pw2[i - 1] * 2 % mod;
  pwk2[0] = 1;
  for (int(i) = (1); (i) <= (n); (i)++)
    pwk2[i] = (long long)pwk2[i - 1] * (k - 2) % mod;
  pwk[0] = 1;
  for (int(i) = (1); (i) <= (n); (i)++)
    pwk[i] = (long long)pwk[i - 1] * k % mod;
  for (int(num) = (0); (num) <= (n); (num)++) {
    int d = dif - num;
    ans += (long long)get(d) * C(dif, num) % mod * pwk2[num] % mod;
    if (ans >= mod) ans -= mod;
  }
  ans = (long long)ans * pwk[n - dif] % mod;
  printf("%d\n", ans);
  return 0;
}
