#include <bits/stdc++.h>
int main() {
  int n, q;
  scanf("%d", &q);
  for (; q; --q) {
    scanf("%d", &n);
    if (n == 2) {
      printf("2");
      continue;
    }
    if (n % 2 == 0) {
      printf("0");
      continue;
    } else {
      printf("1");
      continue;
    }
  }
}
