#include <bits/stdc++.h>
int main() {
  int n, a, b, l, t, r, e;
  int arr1[3] = {-5, -2, -1};
  int arr2[3] = {5, 2, 1};
  scanf("%d", &n);
  while (n) {
    scanf("%d %d", &a, &b);
    if (a == b) {
      n--;
      printf("0\n");
      continue;
    } else if (a > b) {
      l = a - b;
      t = l / 5;
      l = l % 5;
      r = l / 2;
      l = l % 2;
      e = l;
      l = t + r + e;
    } else if (a < b) {
      l = b - a;
      t = l / 5;
      l = l % 5;
      r = l / 2;
      l = l % 2;
      e = l;
      l = t + r + e;
    }
    printf("%d\n", l);
    n--;
  }
  return 0;
}
