#include <bits/stdc++.h>
int main() {
  int n, arr[1000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  int s = 0, d = 0, c = 0, j;
  for (int i = 0, j = n - 1; i <= j;) {
    if (arr[i] < arr[j]) {
      if (c == 0) {
        s += arr[j];
        c = 1;
      } else {
        d += arr[j];
        c = 0;
      }
      j--;
    } else {
      if (c == 0) {
        s += arr[i];
        c = 1;
      } else {
        d += arr[i];
        c = 0;
      }
      i++;
    }
  }
  printf("%d %d\n", s, d);
  return 0;
}
