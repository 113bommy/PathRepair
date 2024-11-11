#include <bits/stdc++.h>
long long int vector[1000100];
int compare(const void *_a, const void *_b) {
  int *a, *b;
  a = (int *)_a;
  b = (int *)_b;
  return (*a - *b);
}
int main() {
  long long int n, i, e;
  scanf("%I64d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &e);
    vector[i] = e + i;
  }
  qsort(vector, n, sizeof(long long int), &compare);
  for (i = 1; i < n; i++) {
    if (vector[i] == vector[i - 1]) {
      printf(":(");
      return 0;
    }
  }
  for (i = 0; i < n; i++) printf("%I64d ", vector[i] - i);
  return 0;
}
