#include <bits/stdc++.h>
using namespace std;
char s[10][10];
int main(void) {
  int x = 100;
  int y = 100;
  for (int i = 0; i < 8; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (s[i][j] == 'W') {
        int ok = 0;
        for (int k = 0; k < i; k++) {
          if (s[k][j] == 'B') {
            ok = 1;
            break;
          }
        }
        if (ok == 0) {
          x = min(x, i);
        }
      } else if (s[i][j] == 'B') {
        int ok = 0;
        for (int k = i + 1; k < 8; k++) {
          if (s[k][j] == 'W') {
            ok = 1;
            break;
          }
        }
        if (ok == 0) {
          y = min(y, 7 - i);
        }
      }
    }
  }
  if (x <= y)
    printf("A\n");
  else
    printf("B\n");
  return 0;
}
