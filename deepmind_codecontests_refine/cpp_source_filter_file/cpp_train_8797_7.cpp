#include <bits/stdc++.h>
int main() {
  int n, cont = 0;
  scanf("%d", &n);
  for (int i = 5; i >= 1; i--) {
    while (n > i) {
      n -= i;
      cont++;
    }
  }
  printf("%d", cont);
  return 0;
}
