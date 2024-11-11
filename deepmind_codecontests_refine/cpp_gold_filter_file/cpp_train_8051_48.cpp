#include <bits/stdc++.h>
int main() {
  int n, i;
  float a, sum = 0;
  scanf("%d", &n);
  i = 0;
  while (i < n) {
    scanf("%f", &a);
    sum += a;
    i++;
  }
  printf("%f\n", (sum / n));
  return 0;
}
