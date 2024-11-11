#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 1 << 22;
ll e[N], b[N], d[N];
ll t, p, n;
ll mul(ll a, ll b) { return (a * b - ll(ld(a) * b / p) * p) % p; }
void tf(ll *x, int l, int r, int n) {
  if (l == r) return;
  int m = (l + r) / 2, a, b;
  tf(x, l, m, n >> 1);
  tf(x, m + 1, r, n >> 1);
  for (int i = l; i <= m; i++) {
    a = x[i], b = x[i + (r - l + 1) / 2];
    x[i] = (a + b) % p, x[i + (r - l + 1) / 2] = (a - b + p) % p;
  }
}
int main() {
  int m;
  scanf("%d%I64d%I64d", &m, &t, &p);
  n = 1 << m;
  p *= n;
  for (int i = 0; i < n; i++) scanf("%I64d", &e[i]);
  for (int i = 0; i <= m; i++) scanf("%I64d", &b[i]);
  for (int i = 1; i < n; i++) d[i] = d[i >> 1] + (i & 1);
  for (int i = 0; i < n; i++) d[i] = b[d[i]];
  tf(e, 0, n - 1, n);
  tf(d, 0, n - 1, n);
  while (t) {
    if (t & 1)
      for (int i = 0; i < n; i++) e[i] = mul(e[i], d[i]);
    for (int i = 0; i < n; i++) d[i] = mul(d[i], d[i]);
    t >>= 1;
  }
  tf(e, 0, n - 1, n);
  for (int i = 0; i < n; i++) printf("%I64d\n", e[i] >> m);
  return 0;
}
