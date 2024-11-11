#include <bits/stdc++.h>
int main() {
  long long n, x = 0, arr[4], a;
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 1;
  scanf("%I64d", &n);
  if (n == 1) {
    printf("1 0 0");
  } else {
    while (x < n) {
      x = arr[1] + arr[2];
      a = arr[0];
      arr[0] = arr[1];
      arr[1] = arr[2];
      arr[2] = x;
    }
    if (x == n) {
      if (x == 0) {
        printf("0 0 0");
      } else {
        printf("%I64d %I64d %I64d\n", arr[1], a, arr[0] - a);
      }
    } else {
      printf("I'm too stupid to solve this problem");
    }
  }
  return 0;
}
