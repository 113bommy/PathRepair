#include <bits/stdc++.h>
using namespace std;
long long int a[int(1e5 + 5)], x, y, s, n, v[int(1e5 + 5)], c[int(1e5 + 5)],
    mx[int(1e5 + 5)], q, b1, b2, res;
int main() {
  scanf("%lld%lld", &n, &q);
  for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
  for (int i = 0; i < n; i++) scanf("%lld", &c[i]);
  for (int i = 0; i < q; i++) {
    scanf("%lld%lld", &x, &y);
    for (int j = 1; j <= n; j++) mx[j] = -(1e18);
    b1 = b2 = n;
    res = 0;
    for (int j = 0; j < n; j++) {
      a[j] = v[j] * y;
      if (mx[c[j]] + v[j] * x > a[j]) a[j] = mx[c[j]] + v[j] * x;
      if (b1 != n && c[b1] != c[j] && a[b1] + v[j] * y > a[j])
        a[j] = a[b1] + v[j] * y;
      if (b2 != n && c[b2] != c[j] && a[b2] + v[j] * y > a[j])
        a[j] = a[b2] + v[j] * y;
      if (a[j] > a[b1]) {
        if (c[j] == c[b1] || c[j] != c[b2]) b1 = j;
      }
      if (a[j] > a[b2]) {
        if (c[j] == c[b2] || c[j] != c[b1]) b2 = j;
      }
      if (a[b1] < a[b2]) swap(b1, b2);
      mx[c[j]] = max(mx[c[j]], a[j]);
      res = max(res, a[j]);
    }
    printf("%lld\n", res);
  }
  return 0;
}
