#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int arr[1000];
  int i;
  int state = 1;
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  arr[n + 1] = -999999;
  for (i = 0; i < n; i++) {
    switch (state) {
      case 1:
        if (arr[i] < arr[i + 1]) {
        } else if (arr[i] == arr[i + 1]) {
          state = 2;
        } else {
          state = 3;
        }
        break;
      case 2:
        if (arr[i] == arr[i + 1]) {
        } else if (arr[i] > arr[i + 1]) {
          state = 3;
        } else {
          printf("NO\n");
          return 0;
        }
        break;
      case 3:
        if (arr[i] <= arr[i + 1]) {
          printf("NO\n");
          return 0;
        }
        break;
    }
  }
  printf("YES\n");
  return 0;
}
