#include <bits/stdc++.h>
int main() {
  int a, m, p;
  scanf("%d %d", &a, &m);
  for (int i = 0; a <= 100000; i++) {
    p = a % m;
    if (p == 0) {
      printf("YES");
      break;
    }
    a = a + p;
  }
  if (a >= 100000 && p != 0) {
    printf("NO");
  }
  return 0;
}
