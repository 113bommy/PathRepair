#include <bits/stdc++.h>
int main() {
  int n, count = 1, max = 1;
  scanf("%d", &n);
  int arr[n + 1];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (int j = 1; j < n; j++) {
    if (arr[j] >= arr[j - 1]) {
      count++;
      if (count > max) max = count;
    } else
      count = 1;
  }
  printf("%d\n", max);
}
