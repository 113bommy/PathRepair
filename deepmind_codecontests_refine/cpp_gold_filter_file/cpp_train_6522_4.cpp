#include <bits/stdc++.h>
using namespace std;
int n, d, lo, hi, mi;
long long b, a[100005], x[300005], nd, ia, ib, ta;
bool ok;
int main() {
  scanf("%d%d%lld", &n, &d, &b);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  lo = 0, hi = n / 2 + 1;
  while (lo < hi) {
    mi = (lo + hi) / 2;
    ok = 1;
    ia = ib = 0;
    for (int i = mi; i < n - mi; i++) {
      nd = b;
      while (nd) {
        if (ia == n) {
          ok = 0;
          break;
        }
        if (abs(i - ia) <= (long long)min(i + 1, n - i) * d) {
          ta = min(a[ia] - ib, nd);
          ib += ta;
          nd -= ta;
          if (ib == a[ia]) ia++, ib = 0;
        } else
          ia++, ib = 0;
      }
    }
    if (ok)
      hi = mi;
    else
      lo = mi + 1;
  }
  printf("%d\n", lo);
  return 0;
}
