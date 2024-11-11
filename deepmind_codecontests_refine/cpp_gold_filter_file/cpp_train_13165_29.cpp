#include <bits/stdc++.h>
int main() {
  int i;
  char a, c;
  int b[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
  while (scanf("%c%c", &a, &c) != EOF) {
    getchar();
    a = b[a - 48];
    c = b[c - 48];
    printf("%d\n", a * c);
  }
  return 0;
}
