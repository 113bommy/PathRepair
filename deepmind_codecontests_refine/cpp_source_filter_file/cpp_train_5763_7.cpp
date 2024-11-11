#include <bits/stdc++.h>
int r[1024], c[1024];
long long find_min(int* a, int l, int* p) {
  int i, j;
  unsigned long long min = -1ll, s, d;
  for (i = 0; i <= l; ++i) {
    for (s = j = 0; j < i; ++j) d = ((i - j) * 2 - 1), s += d * d * a[j];
    for (; j < l; ++j) d = ((j - i) * 2 + 1), s += d * d * a[j];
    if (min > s) min = s, *p = i;
  }
  return min;
}
int main() {
  int i, j, k;
  int n, m;
  long long s = 0;
  for (scanf("%d%d", &n, &m), i = j = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      scanf("%d", &k);
      c[j] += k, r[i] += k;
    }
  }
  s += find_min(r, n, &n);
  s += find_min(c, m, &m);
  printf("%llu\n%d %d\n", s * 4, n, m);
  return 0;
}
