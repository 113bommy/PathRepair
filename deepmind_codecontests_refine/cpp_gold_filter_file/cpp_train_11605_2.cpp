#include <bits/stdc++.h>
int main() {
  int a, m, p;
  scanf("%d %d", &a, &m);
  for (int i = 0; a <= 10000000; i++) {
    p = a % m;
    if (p == 0) {
      printf("Yes");
      break;
    }
    a = a + p;
  }
  if (a >= 10000000 && p != 0) {
    printf("No");
  }
  return 0;
}
