#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    int count = 0;
    int min = arr[n - 1];
    for (i = n - 2; i >= 0; i--) {
      if (arr[i] > min) {
        count++;
      } else
        min = arr[i];
    }
    printf("%d\n", count);
  }
  return 0;
}
