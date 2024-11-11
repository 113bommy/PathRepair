#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int n, m, a[1000005], tree[1000005];
long long ans, z, x, y, jc[1000005], sum, p, tot;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    for (int k = a[i]; k <= n; k += k & (-k)) tree[k] += 1;
  }
  ++a[n];
  jc[0] = 1;
  for (long long i = 1; i <= n; ++i) jc[i] = (jc[i - 1] * i) % mod;
  for (long long i = 1; i <= n; ++i) {
    p = n - i;
    y = 0;
    for (int k = a[i] - 1; k > 0; k -= k & (-k)) y += tree[k];
    ans = (ans + jc[p] * p % mod * (p - 1) % mod * ((mod + 1) / 2) % mod *
                     ((mod + 1) / 2) % mod * y % mod) %
          mod;
    ans = (ans + y * (y - 1) % mod * jc[p] % mod * ((mod + 1) / 2) % mod) % mod;
    ans = (ans + y * sum % mod * jc[p] % mod) % mod;
    ans = (ans + tot * y % mod * jc[p] % mod) % mod;
    x = z = 0;
    for (int k = n; k > 0; k -= k & (-k)) z += tree[k];
    for (int k = a[i]; k > 0; k -= k & (-k)) x += tree[k];
    x = n - a[i] - (z - x);
    sum = (sum + y - x + mod) % mod;
    tot = (tot + x) % mod;
    for (int k = a[i]; k <= n; k += k & (-k)) tree[k] -= 1;
  }
  printf("%I64d", ans);
}
