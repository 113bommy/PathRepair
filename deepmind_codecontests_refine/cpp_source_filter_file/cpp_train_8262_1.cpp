#include <bits/stdc++.h>
int main() {
  int n, cnt = 0;
  int i, j, temp;
  scanf("%d", &n);
  int arr[n];
  for (i = 0; i < n; i++) scanf("%d", &arr[i]);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  for (i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1] && i != 0) {
      cnt++;
    }
    if (i != 0) {
      if (arr[i] == arr[i + 1] && arr[i] == arr[i - 1] && arr[i] != 0) {
        printf("-1");
        return 0;
      }
    }
  }
  printf("%d", cnt);
}
