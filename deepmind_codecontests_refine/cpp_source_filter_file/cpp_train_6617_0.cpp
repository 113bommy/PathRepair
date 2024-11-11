#include <bits/stdc++.h>
int cmp(const void* a, const void* b);
int main() {
  long long t = 1;
  while (t--) {
    long long n, n1, n2;
    scanf("%lld%lld%lld", &n, &n1, &n2);
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      scanf("%lld", &arr[i]);
    }
    qsort(arr, n, sizeof(arr[0]), cmp);
    float s1 = 0, s2 = 0;
    if (n2 < n1) {
      long long x = n2;
      n2 = n1;
      n1 = x;
    }
    if (1) {
      for (long long i = 0; i < n1; i++) s1 += arr[i];
      for (long long i = n1; i < n1 + n2; i++) s2 += arr[i];
    }
    printf("%.8f\n", s1 / n1 + s2 / n2);
  }
  return 0;
}
int cmp(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
