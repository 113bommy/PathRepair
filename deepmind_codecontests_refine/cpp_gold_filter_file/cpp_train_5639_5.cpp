#include <bits/stdc++.h>
int main() {
  int i, j, n;
  scanf("%d", &n);
  int arr[n];
  int arr_1[n];
  int arr_final[n];
  for (i = 0; i < n; i++) {
    scanf("%d %d", &arr[i], &arr_1[i]);
    if (i == 0) {
      arr_final[i] = arr_1[i];
    } else if (i == n - 1) {
      arr_final[i] = arr[i];
    } else {
      arr_final[i] = arr_final[i - 1] - arr[i] + arr_1[i];
    }
  }
  int max = arr_final[0];
  for (i = 0; i < n; i++) {
    if (arr_final[i] >= max) {
      max = arr_final[i];
    }
  }
  printf("%d", max);
  return 0;
}
