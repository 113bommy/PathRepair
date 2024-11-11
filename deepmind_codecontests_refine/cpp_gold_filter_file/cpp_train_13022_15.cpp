#include <bits/stdc++.h>
int main() {
  int a, b, c, d, f = 0;
  int e[110] = {};
  scanf("%d%d", &a, &b);
  while (a--) {
    scanf("%d%d", &c, &d);
    for (int i = c; i <= d; i++) e[i] = 1;
  }
  for (int i = 1; i <= b; i++) {
    if (e[i] == 0) f++;
  }
  printf("%d\n", f);
  for (int i = 1; i <= b; i++) {
    if (e[i] == 0) printf("%d ", i);
  }
  putchar('\n');
  return 0;
}
