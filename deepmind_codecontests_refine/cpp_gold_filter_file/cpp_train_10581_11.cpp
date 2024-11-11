#include <bits/stdc++.h>
int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
  long int i, j, k, n, m, t, flag = 0;
  float min = 10000.1, f;
  scanf("%ld%ld", &n, &m);
  while (n--) {
    scanf("%ld%ld", &j, &k);
    f = (float)j / k;
    if (f < min) min = f;
  }
  printf("%.8f\n", min * m);
  return 0;
}
