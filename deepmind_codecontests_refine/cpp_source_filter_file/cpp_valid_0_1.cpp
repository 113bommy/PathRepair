#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const int inv3 = (mod + 1) / 3;
const int maxn = 3003003;
int fac[maxn], ifac[maxn];
int qpow(int a, int n) {
  int ans = 1;
  for (; n; n >>= 1, a = (ll)a * a % mod)
    if (n & 1) ans = (ll)ans * a % mod;
  return ans;
}
int C(int n, int m) {
  return fac[n] * (ll)ifac[m] % mod * (ll)ifac[n - m] % mod;
}
int f[maxn], g[maxn];
int main(void) {
  int n, q;
  scanf("%d%d", &n, &q);
  fac[0] = 1;
  for (int i = 1; i <= 3 * n + 3; i++) fac[i] = fac[i - 1] * (ll)i % mod;
  ifac[3 * n + 3] = qpow(fac[3 * n + 3], mod - 2);
  for (int i = 3 * n + 2; i >= 0; i--)
    ifac[i] = ifac[i + 1] * (ll)(i + 1) % mod;
  for (int i = 0; i < 3 * n + 3; i++) f[i] = C(3 * n + 3, i + 1);
  g[0] = n + 1;
  g[1] = 3ll * n * (n + 1) / 2;
  for (int i = 2; i <= 3 * n; i++) {
    g[i] = ((f[i] - 3ll * g[i - 1] % mod + mod) % mod - g[i - 2] + mod) % mod *
           inv3 % mod;
  }
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    printf("%d\n", g[x]);
  }
  return 0;
}
