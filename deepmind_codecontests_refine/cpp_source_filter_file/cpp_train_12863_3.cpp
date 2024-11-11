#include <bits/stdc++.h>
int main() {
  int k, r, i, ch = 0;
  scanf("%d%d", &k, &r);
  if (k % 10 == 0 || k % 10 == r) {
    printf("1\n");
    ch++;
  } else if ((k * 2) % 10 == 0 || (k * 2) % 10 == r) {
    printf("2\n");
    ch++;
  } else {
    i = 1;
    int mod = k % 10;
    for (i = 1; i <= 10; i++) {
      if (((mod * i) % 10) == r) {
        printf("%d\n", i);
        ch++;
        break;
      }
    }
  }
  if (ch == 0) printf("10\n");
}
