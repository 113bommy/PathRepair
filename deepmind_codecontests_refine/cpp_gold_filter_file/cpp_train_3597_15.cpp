#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
long long ksm(long long x, long long y) {
  long long s = 1;
  for (; y; y /= 2, x = x * x % mo)
    if (y & 1) s = s * x % mo;
  return s;
}
long long fac[200005], nf[200005];
void build(int n) {
  fac[0] = 1;
  for (int i = 1, _b = n; i <= _b; i++) fac[i] = fac[i - 1] * i % mo;
  nf[n] = ksm(fac[n], mo - 2);
  for (int i = n, _b = 1; i >= _b; i--) nf[i - 1] = nf[i] * i % mo;
}
long long C(int n, int m) {
  return n < m ? 0 : fac[n] * nf[n - m] % mo * nf[m] % mo;
}
const int N = 1505;
int n, m, k;
long long va, vb, p;
long long v[N];
long long g[N], h[N];
int main() {
  build(2e5);
  scanf("%d %d", &n, &m);
  scanf("%lld %lld", &va, &vb);
  p = va * ksm(vb, mo - 2) % mo;
  scanf("%d", &k);
  for (int i = 0, _b = min(m, k); i <= _b; i++) {
    v[i] = ksm(p, i) * ksm((1 - p + mo) % mo, k - i) % mo * C(k, i) % mo;
  }
  g[m] = 1;
  for (int ii = 1, _b = n; ii <= _b; ii++) {
    for (int i = 1, _b = m; i <= _b; i++) h[i] = (h[i - 1] + g[i]) % mo;
    long long s0 = 0, s1 = 0;
    for (int x = 1, _b = m; x <= _b; x++) {
      s0 = (s0 + v[x - 1]) % mo;
      s1 = (s1 - v[x - 1] * h[x - 1]) % mo;
      g[x] = (s0 * (h[m] - h[m - x]) + s1) % mo * v[m - x];
    }
  }
  long long ans = 0;
  for (int i = 0, _b = m; i <= _b; i++) ans = (ans + g[i]) % mo;
  ans = (ans % mo + mo) % mo;
  printf("%lld\n", ans);
}
