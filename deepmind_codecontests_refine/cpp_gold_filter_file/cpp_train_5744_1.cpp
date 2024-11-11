#include <bits/stdc++.h>
#pragma warning(disable : 4996)
int digit_sum(int a) {
  int i;
  int sum = 0;
  int div = 1000;
  for (i = 0; i < 4; i++) {
    sum += a / div;
    a = a % div;
    div /= 10;
  }
  return sum;
}
int main() {
  int a;
  int n;
  scanf("%d", &a);
  int i = a;
  while (i <= 1004) {
    n = digit_sum(i);
    if (n % 4 == 0) {
      printf("%d\n", i);
      return 0;
    } else
      i++;
  }
  return 0;
}
