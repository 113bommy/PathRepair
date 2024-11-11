#include <bits/stdc++.h>
int main() {
  int a, b, c, d;
  scanf("%d %d", &a, &b);
  if (a > b) {
    c = ((a / b) / 2);
    printf("%d %d", b, c);
  } else {
    c = (b * a) / 2;
    printf("%d %d", a, c);
  }
}
