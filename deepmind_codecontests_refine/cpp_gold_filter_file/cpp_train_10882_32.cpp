#include <bits/stdc++.h>
int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
  int num = 0, check = 1, count = 0, fin[100005], i, n, m, arr[100005];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  qsort(arr, n, sizeof(int), cmpfunc);
  for (i = 1; i < 10000005; i++) {
    if (i < arr[num]) {
      m = m - i;
      if (m < 0) break;
      fin[count] = i;
      count++;
    } else if (i == arr[num]) {
      num++;
    } else if (i > arr[num]) {
      m = m - i;
      if (m < 0) break;
      fin[count] = i;
      count++;
    }
  }
  printf("%d\n", count);
  for (i = 0; i < count; i++) {
    printf("%d ", fin[i]);
  }
  printf("\n");
  return 0;
}
