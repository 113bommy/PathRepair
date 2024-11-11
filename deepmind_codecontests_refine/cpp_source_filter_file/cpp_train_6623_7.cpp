#include <bits/stdc++.h>
int main() {
  int n, k, x, i, j, a, sum;
  scanf("%d%d%d", &n, &k, &x);
  int number[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &number[i]);
  }
  sum = k * x;
  for (j = 0; j < n - 2; j++) {
    sum = sum + number[j];
  }
  printf("%d\n", sum);
  return 0;
}
