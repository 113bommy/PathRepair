#include <bits/stdc++.h>
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    int a = n / 36;
    int b = n % 36;
    int c = b / 3;
    if (b % 3 == 2) c++;
    if (c == 12) {
      a++;
      c = 0;
    }
    printf("%d %d\n", a, c);
  }
  return 0;
}
