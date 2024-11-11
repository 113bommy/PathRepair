#include <bits/stdc++.h>
using namespace std;
const int S = 1 << 21;
char p0[S], *p1, *p2;
inline int read() {
  static int x, c, f;
  x = 0;
  f = 1;
  do
    c = (p2 == p1 && (p2 = (p1 = p0) + fread(p0, 1, S, stdin)) == p1 ? EOF
                                                                     : *p1++),
    c == '-' && (f = -1);
  while (!isdigit(c));
  do
    x = x * 10 + (c & 15),
    c = (p2 == p1 && (p2 = (p1 = p0) + fread(p0, 1, S, stdin)) == p1 ? EOF
                                                                     : *p1++);
  while (isdigit(c));
  return x * f;
}
const int N = 1e5 + 5;
int n, q, a[N];
long long ans;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &q);
    for (int i = (1); i <= (n); ++i) scanf("%d", a + i);
    a[n + 1] = 0;
    ans = 0;
    for (int i = (1); i <= (n); ++i)
      if (a[i] > a[i + 1]) ans += a[i] - a[i + 1];
    printf("%lld\n", ans);
    while (q--) {
      static int l, r;
      scanf("%d%d", &l, &r);
      if (l == r) {
        printf("%lld\n", ans);
        continue;
      }
      if (l == r - 1) {
        if (a[l - 1] > a[l]) ans -= a[l - 1] - a[l];
        if (a[l] > a[l + 1]) ans -= a[l] - a[l + 1];
        if (a[r] > a[r + 1]) ans -= a[r] - a[r + 1];
        swap(a[l], a[r]);
        if (a[l - 1] > a[l]) ans += a[l - 1] - a[l];
        if (a[l] > a[l + 1]) ans += a[l] - a[l + 1];
        if (a[r] > a[r + 1]) ans += a[r] - a[r + 1];
        printf("%lld\n", ans);
        continue;
      }
      if (a[l - 1] > a[l]) ans -= a[l - 1] - a[l];
      if (a[l] > a[l + 1]) ans -= a[l] - a[l + 1];
      if (a[r - 1] > a[r]) ans -= a[r - 1] - a[r];
      if (a[r] > a[r + 1]) ans -= a[r] - a[r + 1];
      swap(a[l], a[r]);
      if (a[l - 1] > a[l]) ans += a[l - 1] - a[l];
      if (a[l] > a[l + 1]) ans += a[l] - a[l + 1];
      if (a[r - 1] > a[r]) ans += a[r - 1] - a[r];
      if (a[r] > a[r + 1]) ans += a[r] - a[r + 1];
      printf("%lld\n", ans);
    }
  }
  return 0;
}
