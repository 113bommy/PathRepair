#include <bits/stdc++.h>
int main() {
  int n, d = 0;
  scanf("%d", &n);
  while (n >= 1) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    if (b - a > 1) d++;
    n--;
  }
  printf("%d", d);
}
