#include <bits/stdc++.h>
const int N = 1e6 + 10;
using namespace std;
inline int min(int a, int b) { return a < b ? a : b; }
int main() {
  int a, b, c;
  while (~scanf("%d%d%d", &a, &b, &c)) {
    int k = min(min(a / 3, b / 2), c / 2);
    a -= 3 * k;
    b -= 2 * k;
    c -= 2 * k;
    if (a == 0 && b == 0 && c == 0) {
      printf("%d\n", k * 7);
    } else {
      if (a == 0) {
        if (b == 0 || c == 0) {
          printf("%d\n", k * 7 + 1);
        } else {
          printf("%d\n", k * 7 + 2);
        }
      } else if (b == 0) {
        if (c == 0) {
          if (a > 2) {
            printf("%d\n", k * 7 + 2);
          } else {
            printf("%d\n", k * 7 + 1);
          }
        } else {
          if (c >= 2) {
            printf("%d\n", k * 7 + 3);
          } else {
            printf("%d\n", k * 7 + 2);
          }
        }
      } else if (c == 0) {
        if (a >= 2 && b >= 2) {
          printf("%d\n", k * 7 + 4);
        } else if (b < 2 && a >= 2) {
          printf("%d\n", k * 7 + 3);
        } else if (a < 2) {
          printf("%d\n", k * 7 + 2);
        }
      } else {
        int kk = min(min(a, b), c), sum = 0;
        if (kk == a) {
          if (a == 1) {
            if (c >= 2) {
              if (b >= 2) {
                b = 2;
              }
              printf("%d\n", k * 7 + a + b + 2);
            } else {
              printf("%d\n", k * 7 + 3);
            }
          } else {
            printf("%d\n", k * 7 + 6);
          }
        } else {
          if (b == 1) {
            if (c >= 2) {
              if (a >= 3) {
                a = 3;
              }
              printf("%d\n", k * 7 + a + 3);
            } else if (c == 1) {
              if (a >= 3) {
                a = 3;
              }
              printf("%d\n", k * 7 + a + 2);
            }
          }
          if (c == 1) {
            if (b >= 2) {
              if (a >= 3) {
                a = 3;
              }
              printf("%d\n", k * 7 + a + 3);
            } else if (b == 1) {
              if (a >= 3) {
                a = 3;
              }
              printf("%d\n", k * 7 + a + 2);
            }
          }
        }
      }
    }
  }
  return 0;
}
