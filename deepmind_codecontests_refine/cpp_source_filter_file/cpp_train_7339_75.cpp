#include <bits/stdc++.h>
using namespace std;
int main() {
  char c[8][8];
  int n = 8;
  int w, b;
  int foundw = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      scanf("%c", &c[i][j]);
    }
    getchar();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (c[i][j] == 'W' && foundw == 0) {
        int vd = 0;
        for (int k = 0; k < i; k++) {
          if (c[k][j] != '.') {
            vd = 1;
            break;
          }
        }
        if (vd == 0) {
          w = i;
          foundw = 1;
        }
      }
      if (c[i][j] == 'B') {
        int vd = 0;
        for (int k = i + 1; k < n; k++) {
          if (c[k][j] != '.') {
            vd = 1;
            break;
          }
        }
        if (vd == 0) {
          b = 7 - i;
        }
      }
    }
  }
  if (w < b)
    printf("A\n");
  else
    printf("B\n");
  return 0;
}
