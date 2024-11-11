#include <bits/stdc++.h>
int n, a[105], b[105], c = 0, d = 0, e[105], g[105], r[105], s[105], l[105],
                       rr[105];
int cmp(const void *x, const void *y) {
  int q = *(int *)x;
  int z = *(int *)y;
  return r[z] - r[q];
}
int cmp2(const void *x, const void *y) {
  int q = *(int *)x;
  int z = *(int *)y;
  return s[q] - s[z];
}
int main() {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a[i], &b[i]);
    if (a[i] < 0) {
      g[c] = c;
      r[c] = a[i];
      l[c] = i;
      c++;
    } else {
      e[d] = d;
      s[d] = a[i];
      rr[d] = i;
      d++;
    }
  }
  qsort(g, c, sizeof(int), cmp);
  qsort(e, d, sizeof(int), cmp2);
  r[g[0]] = b[l[g[0]]];
  s[e[0]] = b[rr[e[0]]];
  for (i = 1; i < c; i++) r[g[i]] = r[g[i - 1]] + b[l[g[i]]];
  for (i = 1; i < d; i++) s[e[i]] = s[e[i - 1]] + b[rr[e[i]]];
  if (c == 0)
    printf("%d\n", b[rr[e[0]]]);
  else if (d == 0)
    printf("%d\n", b[l[g[0]]]);
  else if (c == d)
    printf("%d\n", r[g[c - 1]] + s[e[d - 1]]);
  else if (c > d)
    printf("%d\n", r[g[d]] + s[e[d - 1]]);
  else
    printf("%d\n", r[g[c - 1]] + s[e[c]]);
  return 0;
}
