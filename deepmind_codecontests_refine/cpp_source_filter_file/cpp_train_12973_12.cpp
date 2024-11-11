#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int x = sqrt(n);
  if (x * x == n)
    printf("%d\n", n * 2);
  else {
    int dif = n - (x * x);
    if (dif > x)
      printf("%d\n", x * 4 + 4);
    else
      printf("%d\n", x * 4 + 2);
  }
  return 0;
}
