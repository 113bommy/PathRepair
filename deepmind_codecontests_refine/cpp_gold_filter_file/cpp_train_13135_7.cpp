#include <bits/stdc++.h>
using namespace std;
const int N = 2.5e6 + 3, S = 21;
struct data {
  int a, b;
  inline friend void merge(data &x, data &y) {
    x.b = max(min(x.a, y.a), max(x.b, y.b));
    x.a = max(x.a, y.a);
  }
};
data f[N];
int a[N];
int main() {
  int n, mx = 0, s;
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    mx = max(mx, a[i]);
  }
  s = 31 - __builtin_clz(mx);
  for (register int i = n; i; i--) {
    if (!f[a[i]].a)
      f[a[i]].a = i;
    else if (f[a[i]].a && !f[a[i]].b)
      f[a[i]].b = i;
  }
  for (register int i = 1; i <= mx; i <<= 1)
    for (register int j = i; j <= mx; j += i << 1)
      for (register int k = j; k < j + i && k <= mx; k++) merge(f[k - i], f[k]);
  int ans = 0;
  for (register int i = 1; i <= n - 2; i++) {
    int nw = 0;
    for (register int j = s; ~j; j--)
      if (a[i] >> j & 1 ^ 1 && f[nw | 1 << j].b > i) nw |= 1 << j;
    ans = max(ans, a[i] | nw);
  }
  printf("%d", ans);
  return 0;
}
