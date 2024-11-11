#include <bits/stdc++.h>
int main() {
  int a, b, i;
  scanf("%d %d", &a, &b);
  while (a <= b) {
    a *= 3;
    b *= 2;
    i++;
  }
  printf("%d", i);
}
