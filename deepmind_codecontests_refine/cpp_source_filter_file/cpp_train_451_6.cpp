#include <bits/stdc++.h>
int main() {
  int a;
  scanf("%d", &a);
  int b[a][2];
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  int closedL = 0, openL = 0, closedR = 0, openR = 0, count = 0;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < 2; j++) {
      if ((j % 2) == 0) {
        if (b[i][j] == 0)
          closedL++;
        else
          openL++;
      } else {
        if (b[i][j] == 0)
          closedR++;
        else
          openR++;
      }
    }
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < 2; j++) {
      if ((j % 2) == 0) {
        if ((closedL > openL) && b[i][j] == 1) {
          b[i][j] = 0;
          count++;
        } else if ((closedL < openL) && b[i][j] == 0) {
          b[i][j] = 1;
          count++;
        }
      } else {
        if ((closedR > openR) && b[i][j] == 1) {
          b[i][j] = 0;
          count++;
        } else if ((closedR < openR) && b[i][j] == 0) {
          b[i][j] = 1;
          count++;
        }
      }
    }
  }
  printf("%d", count);
}
