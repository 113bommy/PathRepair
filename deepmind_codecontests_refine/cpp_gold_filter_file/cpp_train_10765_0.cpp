#include <bits/stdc++.h>
int main() {
  int i, j, temp, n;
  while (scanf("%d", &n) != EOF) {
    int rem;
    temp = n;
    if (temp == 0)
      printf("O-|-OOOO\n");
    else {
      while (temp != 0) {
        rem = temp % 10;
        if (rem >= 5) {
          rem = rem - 5;
          printf("-O|");
        } else
          printf("O-|");
        if (rem == 0) printf("-OOOO\n");
        if (rem == 1) printf("O-OOO\n");
        if (rem == 2) printf("OO-OO\n");
        if (rem == 3) printf("OOO-O\n");
        if (rem == 4) printf("OOOO-\n");
        temp = temp / 10;
      }
    }
  }
  return 0;
}
