#include <bits/stdc++.h>
long long cmpfunc(const void* a, const void* b) {
  return (*(long long*)a - *(long long*)b);
}
int main(void) {
  long long int test, i, j, n, count, flag = 0, o1 = 0, o2 = 0, b1, x, m, l,
                                      max, sum2, min, f, c, r, o, sum1, sum = 0,
                                      y, b, count1 = 0, a2, b2;
  char a[100000];
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%c", &a[i]);
  }
  count = max = 0;
  for (i = 0; i < n; i++) {
    if (a[i] == ' ') {
      if (count > max) {
        max = count;
      }
      count = 0;
    } else {
      if (a[i] >= 65 && a[i] <= 91) {
        count++;
      }
    }
  }
  if (count > max) {
    max = count;
  }
  printf("%lld", max);
  return 0;
}
