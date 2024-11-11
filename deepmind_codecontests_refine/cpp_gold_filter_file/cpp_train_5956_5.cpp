#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int fact[200010], v[200010];
int pw(int a, int b) {
  int sol = 1;
  for (int i = 1; i <= b; i <<= 1) {
    if (b & i) sol = (1LL * sol * a) % mod;
    a = (1LL * a * a) % mod;
  }
  return sol;
}
int comb(int n, int k) {
  return (1LL * fact[n] * pw((1LL * fact[n - k] * fact[k]) % mod, mod - 2)) %
         mod;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  v[n + 1] = v[1];
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = (1LL * fact[i - 1] * i) % mod;
  int c = 0;
  for (int i = 1; i <= n; i++)
    if (v[i] != v[i + 1]) c++;
  int ct = pw(k, n - c);
  n = c;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (k - 2 == 0 && i < n) continue;
    int val = pw(k - 2, n - i);
    if (n - i == 0) val = 1;
    val = (1LL * val * comb(n, i)) % mod;
    if (i % 2 == 1)
      val = (1LL * val * pw(2, i - 1)) % mod;
    else {
      int r = comb(i, i / 2);
      r = (1LL * r * pw(2, mod - 2)) % mod;
      r = pw(2, i - 1) - r;
      if (r < 0) r += mod;
      val = (1LL * val * r) % mod;
    }
    val = (1LL * val * ct) % mod;
    ans += val;
    if (ans >= mod) ans -= mod;
  }
  printf("%d", ans);
  return 0;
}
