#include <bits/stdc++.h>
const int N = 1e6 + 5, Mod = 998244353;
using namespace std;
int n, k;
long long ans, y;
long long s1[N], s2[N], fac[N];
inline long long power(long long a, long long b) {
  long long tmp = a, res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * tmp % Mod;
    tmp = tmp * tmp % Mod;
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &k);
  s1[0] = s2[k + 3] = fac[0] = 1;
  for (int i = 1; i <= k + 2; i++) s1[i] = s1[i - 1] * (n - i) % Mod;
  for (int i = k + 2; i >= 1; i--) s2[i] = s2[i + 1] * (n - i) % Mod;
  for (int i = 1; i <= k + 2; i++) fac[i] = fac[i - 1] * i % Mod;
  for (int i = 1; i <= k + 2; i++) {
    y = (y + power(i, k)) % Mod;
    long long a = s1[i - 1] * s2[i + 1] % Mod, b = fac[i - 1] *
                                                   ((k - i) & 1 ? -1ll : 1ll) *
                                                   fac[k + 2 - i] % Mod;
    ans = (ans + y * a % Mod * power(b, Mod - 2) % Mod) % Mod;
  }
  printf("%lld\n", (ans + Mod) % Mod);
  return 0;
}
