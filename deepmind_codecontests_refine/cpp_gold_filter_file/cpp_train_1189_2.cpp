#include <bits/stdc++.h>
int arr[3000000] = {-1};
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int k = n + m;
  if (n == m) {
    for (int i = 0; i < k; i++) {
      arr[i] = i % 2;
    }
  } else if (n > m) {
    if (n == m + 1) {
      for (int i = 0; i < k; i++) {
        arr[i] = i % 2;
      }
    } else {
      printf("-1");
      return 0;
    }
  } else {
    if (m <= 2 * n + 2) {
      int index = 0;
      for (int i = 0; i < m - n; i++) {
        arr[index++] = 1;
        arr[index++] = 1;
        arr[index++] = 0;
      }
      for (int i = 0; i < 2 * n - m; i++) {
        arr[index++] = 1;
        arr[index++] = 0;
      }
    } else {
      printf("-1");
      return 0;
    }
  }
  for (int i = 0; i < k; i++) {
    printf("%d", arr[i]);
  }
  return 0;
}
