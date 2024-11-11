#include <bits/stdc++.h>
int main() {
  int n, arr[101], input[101], i, sum = 0, count = 0, count2 = 0;
  scanf("%d", &n);
  for (i = 0; i < 100; i++) {
    arr[i] = 0;
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &input[i]);
  }
  int x = input[0];
  for (i = 0; i < n; i++) {
    arr[input[i]]++;
  }
  for (i = 0; i < 100; i++) {
    if (arr[i] > 0) {
      count++;
    }
  }
  if (count != 2) {
    printf("NO");
  } else {
    for (i = 0; i < n; i++) {
      if (input[i] == x) {
        count2++;
      }
    }
    if (count2 == n / 2) {
      printf("YES");
      printf("%d ", x);
      for (i = 0; i < n; i++) {
        if (input[i] == x) {
          continue;
        } else {
          printf("%d", input[i]);
          break;
        }
      }
    } else {
      printf("NO");
    }
  }
  return 0;
}
