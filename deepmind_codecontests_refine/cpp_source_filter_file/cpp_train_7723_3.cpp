#include <bits/stdc++.h>
int compare(const void* val1, const void* val2) {
  return (*((unsigned int*)val1)) < (*((unsigned int*)val2))
             ? -1
             : ((*((unsigned int*)val1)) > (*((unsigned int*)val2)) ? 1 : 0);
}
int main(void) {
  unsigned int k, n, j, i;
  unsigned int arr[10001];
  scanf("%u", &k);
  for (j = 0; j < k; j++) {
    scanf("%u", &n);
    for (i = 0; i < n; i++) {
      scanf("%u", &(arr[i]));
    }
    qsort(arr, n, sizeof(unsigned int), compare);
    for (i = 0; i < n && arr[i] > i; i++)
      ;
    printf("%u\n", i);
  }
  return 0;
}
