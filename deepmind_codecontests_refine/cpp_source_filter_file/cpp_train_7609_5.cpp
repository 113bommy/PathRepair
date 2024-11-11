#include <bits/stdc++.h>
int main() {
  int a, b, c, d, i, j, k, n, l = 0;
  scanf("%d", &a);
  int arr[a];
  for (i = 0; i < a; i++) {
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < a - 1; i++) {
    for (k = i + 1; k < a; k++)
      if (arr[i] > arr[k]) {
        n = arr[i];
        arr[i] = arr[k];
        arr[k] = n;
      }
  }
  for (i = 0; i < a - 1; i++) {
    if (arr[i + 1] - arr[i] != 1) {
      l = l + (arr[i + 1] - arr[i]);
    }
  }
  printf("%d\n", l);
}
