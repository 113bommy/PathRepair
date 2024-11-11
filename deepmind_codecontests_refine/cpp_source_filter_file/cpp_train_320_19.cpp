#include <bits/stdc++.h>
using namespace std;
int n, q;
const int maxn = 2e5 + 5;
const long long mod = 1e9 + 7;
long long a[maxn], w[maxn];
long long lowbit(long long x) { return x & -x; }
void add(long long t[], long long x, long long d, int typ) {
  for (; x < maxn; x += lowbit(x)) {
    t[x] += d;
    if (typ) t[x] = (t[x] + mod) % mod;
  }
}
long long ask(long long t[], long long x, int typ) {
  long long ret = 0;
  for (; x; x -= lowbit(x)) {
    ret += t[x];
    if (typ) ret %= mod;
  }
  return ret;
}
long long sum[maxn];
long long t[maxn];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    a[i] -= i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", w + i);
    add(t, i, w[i], 0);
    add(sum, i, w[i] * a[i], 1);
  }
  while (q--) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    if (l < 0) {
      add(t, -l, r - w[-l], 0);
      add(sum, -l, a[-l] * (r - w[-l]), 1);
      w[-l] = r;
    } else {
      long long L = l, R = r;
      long long all = ask(t, r, 0) - ask(t, l - 1, 0);
      while (L < R) {
        long long mid = (L + R) / 2;
        if (ask(t, mid, 0) - ask(t, l - 1, 0) > all / 2)
          R = mid;
        else
          L = mid + 1;
      }
      long long k = L;
      long long ans = a[k] * (ask(t, k - 1, 1) - ask(t, l - 1, 1) + mod) % mod;
      ans -= (ask(sum, k - 1, 1) - ask(sum, l - 1, 1) + mod) % mod;
      ans = (ans + mod) % mod;
      (ans += (ask(sum, r, 1) - ask(sum, k, 1) + mod)) %= mod;
      ans -= a[k] * (ask(t, r, 1) - ask(t, k, 1) + mod) % mod;
      ans = (ans + mod) % mod;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
