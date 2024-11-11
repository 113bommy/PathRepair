#include <bits/stdc++.h>
const int N = 1010;
int n, m, k;
int i, j, d, mi, t;
int a[N], b[N];
int main() {
  scanf("%d %d", &n, &m);
  for (i = 0; i <= n; i++) scanf("%d", &a[i]);
  for (i = 0; i <= m; i++) scanf("%d", &b[i]);
  if (n > m) {
    if (a[0] > 0)
      printf("Infinity");
    else
      printf("-Infinity");
  } else if (n == m) {
    int ai = ((a[0]) < 0 ? (-(a[0])) : (a[0])),
        bi = ((b[0]) < 0 ? (-(b[0])) : (b[0]));
    while (ai != bi)
      if (ai > bi)
        ai -= bi;
      else
        bi -= ai;
    if (a[0] * b[0] > 0)
      printf("%d/%d", ((a[0]) < 0 ? (-(a[0])) : (a[0])) / ai,
             ((b[0]) < 0 ? (-(b[0])) : (b[0])) / ai);
    else
      printf("-%d/%d", ((a[0]) < 0 ? (-(a[0])) : (a[0])) / ai,
             ((b[0]) < 0 ? (-(b[0])) : (b[0])) / ai);
  } else
    printf("0/1");
  return 0;
}
