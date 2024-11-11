#include <bits/stdc++.h>
int main() {
  int n, a, b, i, j, t, flag = 0;
  scanf("%d%d%d", &n, &a, &b);
  int arr[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        flag = 1;
        t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
      }
    }
    if (flag) break;
  }
  printf("%d", arr[b - 1] - arr[a - 1]);
  return 0;
}
