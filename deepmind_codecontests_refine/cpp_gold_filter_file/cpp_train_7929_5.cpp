#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  int i, j;
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int m;
  scanf("%d", &m);
  int arr1[m];
  for (i = 0; i < m; i++) {
    scanf("%d", &arr1[i]);
  }
  int Gn;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - 1; j++) {
      if (arr[j] >= arr[j + 1]) {
        Gn = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = Gn;
      }
    }
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < m - 1; j++) {
      if (arr1[j] >= arr1[j + 1]) {
        Gn = arr1[j];
        arr1[j + 1] = arr1[j];
        arr1[j + 1] = Gn;
      }
    }
  }
  printf("%d %d", arr[n - 1], arr1[m - 1]);
  return 0;
}
