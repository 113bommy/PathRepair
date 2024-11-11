#include <bits/stdc++.h>
int main() {
  int A, NUMBER, ARR[1001], X, Y, T, SUM = 0, SUM2 = 0, SMX = 0, SMY = 0;
  scanf("%d", &NUMBER);
  for (A = 0; A < NUMBER; A++) {
    scanf("%d %d %d", &T, &X, &Y);
    if (T == 1) {
      SUM = SUM + 10;
      SMX = SMX + X;
    } else {
      SUM2 = SUM2 + 10;
      SMY = SMY + X;
    }
  }
  {
    if (SMX >= SUM / 2)
      printf("LIVE\n");
    else
      printf("DEED\n");
  }
  {
    if (SMY >= SUM2 / 2)
      printf("LIVE");
    else
      printf("DEAD");
  }
  return 0;
}
