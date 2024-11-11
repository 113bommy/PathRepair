#include <bits/stdc++.h>
int main() {
  int n, i, a[100], counts, b[2];
  int min, max, minindex, maxindex;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  max = min = a[0];
  maxindex = minindex = 0;
  for (i = 0; i < n; i++) {
    if (max < a[i]) {
      max = a[i];
      maxindex = i;
    }
    if (min > a[i]) {
      min = a[i];
      minindex = i;
    }
  }
  if (maxindex == 0 || maxindex == n - 1 || minindex == 0 ||
      minindex == n - 1) {
    counts = n - 1;
    printf("%d", counts);
    return 0;
  }
  if (maxindex < minindex) {
    counts = minindex;
  } else {
    counts = maxindex;
  }
  b[0] = n - maxindex;
  b[1] = n - minindex;
  if (b[0] > b[1]) {
    ;
  } else {
    b[0] = b[1];
  }
  if (b[0] > counts) {
    counts = b[0];
  }
  printf("%d", counts);
  return 0;
}
