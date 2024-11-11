#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 1000, msiz = 2, inf = 1e18;
long long mod;
long long phi(long long x) {
  long long res = x;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
      while (x % i == 0) x /= i;
      res = res / i * (i - 1);
    }
  if (x > 1) res = res / x * (x - 1);
  return res;
}
long long product(long long obj1, long long obj2) {
  return (obj1 * obj2) % mod;
}
long long modpow(long long x, long long h) {
  long long res = 1;
  for (; h; h >>= 1) {
    if (h & 1) res = product(res, x);
    x = product(x, x);
  }
  return res;
}
long long gt[maxn], inverse[maxn], igt[maxn], ans[maxn];
long long C(long long k, long long n) {
  return product(gt[n], product(igt[k], igt[n - k]));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, a, q;
  cin >> n >> m >> a >> q;
  long long t = phi(q), t1 = 0, t2;
  mod = q;
  for (long long i = 1; i * i <= t; i++)
    if (t % i == 0) {
      if (modpow(a, i) == 1) {
        t1 = i;
        break;
      }
      if (modpow(a, t / i) == 1) t2 = i;
    }
  if (t1)
    t = t1;
  else
    t = t2;
  mod = t;
  gt[0] = gt[1] = igt[0] = igt[1] = inverse[1] = 1;
  for (long long i = 2; i <= m; i++) {
    inverse[i] = mod - product(mod / i, inverse[mod % i]);
    gt[i] = product(gt[i - 1], i);
    igt[i] = product(igt[i - 1], inverse[i]);
  }
  ans[0] = a;
  for (long long i = 1; i < n; i++) {
    if (i <= m) {
      long long tmp = C(i, m);
      mod = q;
      ans[i] = product(ans[i - 1], modpow(a, tmp));
      mod = t;
    } else
      ans[i] = ans[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) cout << ans[i] << " ";
  return 0;
}
