#include <bits/stdc++.h>
using namespace std;
char A[5][5];
int B[5][5];
int h[5], l[5], x[5];
int main() {
  int i, j, m, n;
  int num0, num1, num2;
  int win1, win2, draw;
  win1 = win2 = num0 = num1 = num2 = 0;
  draw = 1;
  for (i = 0; i < 3; i++) {
    scanf("%s", A[i]);
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (A[i][j] == 'X') {
        num1++;
        B[i][j] = 1;
      }
      if (A[i][j] == '0') {
        num2++;
        B[i][j] = -10;
      }
      if (A[i][j] == '.') {
        num0++;
        B[i][j] = 1000;
      }
    }
  }
  if (abs(num1 - num2) > 1 || num2 > num1) {
    printf("illegal");
  } else {
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        h[i] += B[i][j];
        l[i] += B[j][i];
      }
      x[0] += B[i][i];
      x[1] += B[i][2 - i];
    }
    for (i = 0; i < 3; i++) {
      if (h[i] == 3)
        win1++;
      else if (h[i] == -30)
        win2++;
      if (l[i] == 3)
        win1++;
      else if (l[i] == -30)
        win2++;
      if (x[i] == 0) {
      } else if (x[i] == 3)
        win1++;
      else if (x[i] == -30)
        win2++;
    }
    if (win1 && win2) {
      printf("illegal");
      return 0;
    } else {
      if (win1) {
        if (num1 > num2) {
          printf("the first player won");
        } else {
          printf("illegal");
        }
        return 0;
      }
      if (win2) {
        if (num1 == num2) {
          printf("the second player won");
        } else {
          printf("illegal");
        }
        return 0;
      }
      if (win1 == 0 && win2 == 0) {
        if (num0) {
          if (num1 == num2) {
            printf("first");
            return 0;
          } else {
            printf("second");
            return 0;
          }
        } else {
          printf("draw");
          return 0;
        }
      }
    }
  }
  return 0;
}
