#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 998244353;
long long a1[maxn], b1[maxn];
struct node {
  long long l, r;
} num[maxn];
long long n, k, val[maxn], cnt;
long long ans, d[maxn], x[maxn], c[maxn];
long long quickpow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long ni(long long x) { return quickpow(x, mod - 2); }
void init() {
  a1[0] = 1;
  for (int i = 1; i < maxn; i++) {
    a1[i] = (a1[i - 1] * i) % mod;
  }
  b1[maxn - 1] = ni(a1[maxn - 1]);
  for (int i = maxn - 2; i >= 0; i--) {
    b1[i] = b1[i + 1] * (i + 1) % mod;
  }
}
long long C(long long n, long long m) {
  if (n < m) return 0;
  return (a1[n] * b1[m] % mod) * b1[n - m] % mod;
}
int main() {
  scanf("%lld%lld", &n, &k);
  init();
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &num[i].l, &num[i].r);
    val[cnt++] = num[i].l;
    val[cnt++] = num[i].r;
  }
  sort(val, val + cnt);
  cnt = unique(val, val + cnt) - val;
  for (int i = 1; i <= n; i++) {
    num[i].l = lower_bound(val, val + cnt, num[i].l) - val + 1;
    num[i].r = lower_bound(val, val + cnt, num[i].r) - val + 1;
  }
  for (int i = 1; i <= cnt; i++) {
    x[num[i].l]++;
    d[num[i].l]++;
    d[num[i].r + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    c[i] = c[i - 1] + d[i];
  }
  for (int i = 1; i <= cnt; i++) {
    if (c[i] < k) continue;
    ans = (ans + C(c[i], k) - C(c[i] - x[i], k) + mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
