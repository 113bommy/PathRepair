#include <bits/stdc++.h>
using namespace std;
int a[100100], n, s1[100100], t1, s2[100100], t2, l1[100100], l2[100100];
int k, h[100100], t[100100], out[100100], top;
bool c[100100];
void put1(int v) {
  int h = 1, t = t1, m, r = 0;
  while (h <= t)
    if (s1[m = h + t >> 1] > v)
      t = m - 1;
    else
      r = m, h = m + 1;
  l1[v] = s1[r];
  s1[r + 1] = v;
  if (r + 1 > t1) ++t1;
}
void go1() {
  h[++k] = top + 1;
  t[k] = top += t1;
  int i = 0;
  for (int x = s1[t1]; x; x = l1[x], ++i) c[out[top - i] = x] = 1;
}
void go2() {
  static int d[100100];
  int T;
  d[T = 1] = a[n];
  for (int i = n - 1; i; --i)
    if (a[i] < d[T]) d[++T] = a[i];
  h[++k] = top + 1;
  t[k] = top += T;
  int i = 0;
  while (T) c[out[h[k] + i++] = d[T--]] = 1;
}
int main() {
  int _;
  scanf("%d", &_);
  s2[0] = 2e5;
  while (_--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) c[i] = 0;
    top = 0;
    k = 0;
    while (n) {
      t1 = t2 = 0;
      for (int i = 1; i <= n; ++i) put1(a[i]);
      if (2 * n / t1 <= t1 + 1)
        go1();
      else
        go2();
      int L = n;
      n = 0;
      for (int i = 1; i <= L; ++i)
        if (!c[a[i]]) a[++n] = a[i];
    }
    printf("%d\n", k);
    for (int i = 1; i <= k; i++) {
      printf("%d", t[i] - h[i] + 1);
      for (int j = h[i]; j <= t[i]; ++j) printf(" %d", out[j]);
      printf("\n");
    }
  }
}
