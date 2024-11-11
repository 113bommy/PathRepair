#include <bits/stdc++.h>
int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long int arr[n];
    for (int i = 0; i < n; i++) scanf("%ld", &arr[i]);
    qsort(arr, n, sizeof(long int), cmpfunc);
    int count = 0;
    for (int i = 0; i < n; i++)
      if (arr[i] != arr[i + 1]) count++;
    printf("%d\n", count);
  }
  return 0;
}
