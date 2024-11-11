#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
struct T {
  int i, j;
  long long l, r, s, d;
  T(int i = -1, int j = 0, long long l = 0, long long r = 0, long long d = 0,
    long long s = 0)
      : i(i), j(j), l(l), r(r), d(d), s(s) {}
};
T t[1 << 18];
int d[1 << 18], h[1 << 18], p;
T uni(const T &a, const T &b) {
  if (a.i == -1) return b;
  if (b.i == -1) return a;
  return T(a.i, b.j, max(a.l, b.l + a.d + d[a.j]), max(b.r, a.r + b.d + d[a.j]),
           a.d + b.d + d[a.j], max(a.r + b.l + d[a.j], max(a.s, b.s)));
}
T fnd(int i, int j) {
  T l, r;
  for (i += p, j += p; i <= j; i = (i + 1) / 2, j = (j - 1) / 2) {
    if (i & 1) l = uni(l, t[i]);
    if (~j & 1) r = uni(t[j], r);
  }
  return uni(l, r);
}
int main() {
  int n, i, j, q;
  scanf("%d%d", &n, &q);
  for (i = 0; i < n; scanf("%d", &d[i]), i++)
    ;
  for (i = 0; i < n; scanf("%d", &h[i]), i++)
    ;
  for (p = 1; p < n; p *= 2)
    ;
  for (i = 0; i < n; t[p + i] = T(i, i, 2 * h[i], 2 * h[i], 0, 0), i++)
    ;
  for (i = p - 1; i > 0; t[i] = uni(t[2 * i], t[2 * i + 1]), i--)
    ;
  for (; q--;) {
    scanf("%d%d", &i, &j);
    i--;
    j--;
    T v;
    if (i <= j)
      v = uni(fnd(j + 1, n - 1), fnd(0, i - 1));
    else
      v = fnd(j + 1, i - 1);
    printf("%lld\n", v.s);
  }
  return 0;
}
