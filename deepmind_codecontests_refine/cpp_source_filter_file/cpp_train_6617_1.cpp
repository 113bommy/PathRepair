#include <bits/stdc++.h>
int a[100001];
int comp(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int main() {
  int n1, n2, n, i, t1, t2;
  int sum1 = 0, sum2 = 0;
  scanf("%d%d%d", &n, &n1, &n2);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  qsort(a + 1, n, sizeof(a[1]), comp);
  if (n1 < n2) {
    t1 = n1;
    t2 = n2;
  } else {
    t1 = n2;
    t2 = n1;
  }
  for (i = 1; i <= t1; i++) sum1 += a[i];
  for (i = t1 + 1; i <= t1 + t2; i++) sum2 += a[i];
  printf("%f\n", ((double)(sum1) / t1 + (double)(sum2) / t2));
  return 0;
}
