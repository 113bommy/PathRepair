#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main() {
  long long l, t, m;
  int n, i;
  double res;
  scanf("%d%I64d%I64d", &n, &l, &t);
  for (i = 0; i < n; i++) scanf("%d", a + i);
  res = 0;
  for (i = 0; i < n; i++) {
    m = 2 * t / l * (n - 1);
    res += m;
    m = (2 * t + a[i]) % l;
    if (m >= a[i]) {
      res += (upper_bound(a, a + n, m) - a) - 1 - i;
    } else {
      res += (upper_bound(a, a + n, m) - a) + n - 1 - i;
    }
    m = 2 * t / l * (n - 1);
    res += m;
    m = ((-2 * t + a[i]) % l + l) % l;
    if (m <= a[i]) {
      res += -(lower_bound(a, a + n, m) - a) + i;
    } else {
      res += -(lower_bound(a, a + n, m) - a) + n + i;
    }
  }
  printf("%lf\n", res / 8.0);
}
