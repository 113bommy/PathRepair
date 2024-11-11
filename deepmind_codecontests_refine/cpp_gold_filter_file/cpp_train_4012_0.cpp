#include <bits/stdc++.h>
int main() {
  int a, b, t, y;
  scanf("%d %d", &a, &b);
  if (a < b) {
    y = a;
    a = b;
    b = y;
  }
  if (a == b)
    t = (a + b) - 3;
  else if ((a - b) % 3 == 0)
    t = (a + b) - 3;
  else
    t = (a + b) - 2;
  if (t < 0) t = 0;
  printf("%d", t);
  return 0;
}
