#include <bits/stdc++.h>
int cmpfunc(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
int main() {
  long long int a, b, c, d, e, i, j, k, n, sum1 = 0;
  long long int sum = 0;
  long long int x[200002], y[100002] = {0}, z[100002];
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &x[i]);
    y[x[i]]++;
  }
  z[0] = 0;
  z[1] = y[1];
  for (i = 2; i <= 100000; i++) {
    k = z[i - 1] > (z[i - 2] + y[i] * i) ? z[i - 1] : (z[i - 2] + y[i] * i);
    z[i] = k;
  }
  printf("%lld", z[100000]);
  return 0;
}
