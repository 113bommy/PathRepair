#include <bits/stdc++.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int cc = 0;
  bool charge = 0;
  if (a == 1 && b == 1) {
    printf("0\n");
    return 0;
  }
  while (1) {
    if (a == 1 || a == 2) {
      charge = 0;
    } else {
      charge = 1;
    }
    if (!charge) {
      a++;
      b -= 2;
    } else {
      a -= 2;
      b++;
    }
    cc = 0;
    if (a <= 0 || b <= 0) {
      break;
    }
  }
  printf("%d\n", cc);
}
