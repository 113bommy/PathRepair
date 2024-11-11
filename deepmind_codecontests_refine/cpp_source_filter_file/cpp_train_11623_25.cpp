#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for (int i = 100; i >= a; i--) {
    if (i >= a && i <= a * 2) {
      a = i;
      break;
    }
  }
  for (int i = a - 1; i >= b; i--) {
    if (i >= b && i <= b * 2) {
      b = i;
      break;
    }
  }
  for (int i = b - 1; i >= max(c, d); i--) {
    if (i >= c && i <= c * 2 && i >= d && i <= d * 2 && c * 2 < b &&
        c * 2 < a && d * 2 < b && d * 2 < a) {
      c = i;
      printf("%d\n%d\n%d\n", a, b, c);
      return 0;
    }
  }
  printf("%d\n", -1);
  return 0;
}
