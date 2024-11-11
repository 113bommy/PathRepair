#include <bits/stdc++.h>
int main() {
  int a = 0, b, c, d, i, z = 0, s = 0;
  char x[100] = {0};
  gets(x);
  for (i = 0; i < 100; i++) {
    if (x[i] == 'C' || x[i] == 'P')
      a = a + 1;
    else
      break;
  }
  for (i = 0; i < a; i++) {
    if (x[i] == x[i + 1]) {
      z = z + 1;
      if (z > 4) {
        z = 0;
        s = s + 1;
      }
    } else {
      s = s + 1;
      z = 0;
    }
  }
  printf("%d", s);
  return 0;
}
