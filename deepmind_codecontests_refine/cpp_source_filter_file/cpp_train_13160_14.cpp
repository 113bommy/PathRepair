#include <bits/stdc++.h>
long a[400000][2];
int comp1(const void *a, const void *b) {
  long t;
  t = ((long *)a)[0] - ((long *)b)[0];
  if (t > 0) {
    return 1;
  } else if (t < 0) {
    return 0;
  } else {
    return -1;
  }
}
int comp2(const void *a, const void *b) {
  long t;
  t = ((long *)a)[1] - ((long *)b)[1];
  if (t > 0) {
    return 1;
  } else if (t < 0) {
    return 0;
  } else {
    return -1;
  }
}
int main() {
  long i, k, n;
  scanf("%ld", &n);
  for (i = 0; i < n; i++) {
    scanf("%ld", &a[i][0]);
    a[i][1] = i;
  }
  qsort(a, n, sizeof(long) * 2, comp1);
  for (i = 0, k = 0; i < n; i++) {
    if (a[i][0] <= k) {
      a[i][0] = k + 1;
      k++;
    } else {
      k = a[i][0];
    }
  }
  qsort(a, n, sizeof(long) * 2, comp2);
  printf("%ld", a[0][0]);
  for (i = 1; i < n; i++) {
    printf(" %ld", a[i][0]);
  }
  printf("\n");
  return 0;
}
