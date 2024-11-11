#include <bits/stdc++.h>
using namespace std;
int n;
char a[5], b[5], c[5], d[5];
int main() {
  scanf("%d", &n);
  scanf("%s", a);
  scanf("%s", b);
  printf("YES\n");
  if (a[0] != a[1] && b[0] != b[1]) {
    if (a[0] == b[1] && a[1] == b[0]) {
      for (int i = 1; i <= n; i++) {
        printf("%c", a[0]);
      }
      for (int i = 1; i <= n; i++) {
        if (b[1] != 'a' && b[0] != 'a') printf("a");
        if (b[1] != 'b' && b[0] != 'b') printf("b");
        if (b[1] != 'c' && b[0] != 'c') printf("c");
      }
      for (int i = 1; i <= n; i++) {
        printf("%c", a[1]);
      }
    } else if (a[0] == b[0] && b[1] == a[1]) {
      for (int i = 1; i <= n; i++) {
        if (b[1] != 'a' && b[0] != 'a') printf("a%c%c", b[1], b[0]);
        if (b[1] != 'b' && b[0] != 'b') printf("b%c%c", b[1], b[0]);
        if (b[1] != 'c' && b[0] != 'c') {
          printf("c");
          printf("%c%c", b[1], b[0]);
        }
      }
    } else {
      if (a[1] == b[0]) {
        for (int i = 1; i <= n; i++) {
          printf("%c%c%c", b[1], b[0], a[0]);
        }
      } else if (a[0] == b[1]) {
        for (int i = 1; i <= n; i++) {
          printf("%c%c%c", a[1], a[0], b[0]);
        }
      } else if (a[0] == b[0]) {
        for (int i = 1; i <= n; i++) printf("%c%c%c", a[1], b[1]);
        for (int i = 1; i <= n; i++) {
          printf("%c", a[0]);
        }
      } else if (b[1] == a[1]) {
        for (int i = 1; i <= n; i++) {
          printf("%c", b[1]);
        }
        for (int i = 1; i <= n; i++) {
          printf("%c%c", a[0], b[0]);
        }
      } else {
        if (a[0] != 'a' && a[1] != 'a') {
          for (int i = 1; i <= n; i++) {
            printf("a%c%c", a[1], a[0]);
          }
        } else if (a[0] != 'b' && a[1] != 'b') {
          for (int i = 1; i <= n; i++) {
            printf("b%c%c", a[1], a[0]);
          }
        } else if (a[0] != 'c' && a[1] != 'c') {
          for (int i = 1; i <= n; i++) {
            printf("c%c%c", a[1], a[0]);
          }
        }
      }
    }
  } else {
    if (a[0] == a[1] && b[0] == b[1] && a[0] != b[0]) {
      for (int i = 1; i <= n; i++) {
        printf("%c%c", a[0], b[0]);
      }
      for (int i = 1; i <= n; i++) {
        if (b[1] != 'a' && a[0] != 'a') printf("a");
        if (b[1] != 'b' && a[0] != 'b') printf("b");
        if (b[1] != 'c' && a[0] != 'c') printf("c");
      }
    } else {
      if (a[0] == a[1]) {
        if (b[0] != a[0] && b[1] != a[0]) {
          for (int i = 1; i <= n; i++) {
            printf("%c%c%c", a[0], b[1], b[0]);
          }
        } else {
          if (b[0] == a[0] && b[1] == a[0]) {
            for (int i = 1; i <= n; i++) {
              printf("abc");
            }
          } else {
            if (b[0] == a[0] || b[1] == a[0]) {
              for (int i = 1; i <= n; i++) {
                if (b[1] != 'a' && b[0] != 'a') printf("%c%ca", b[1], b[0]);
                if (b[1] != 'b' && b[0] != 'b') printf("%c%cb", b[1], b[0]);
                if (b[1] != 'c' && b[0] != 'c') {
                  printf("%c%c", b[1], b[0]);
                  printf("c");
                }
              }
            } else {
              for (int i = 1; i <= n; i++) {
                printf("%c%c%c", a[0], b[1], b[0]);
              }
            }
          }
        }
      } else if (b[0] == b[1]) {
        if (a[0] != b[0] && a[1] != b[0]) {
          for (int i = 1; i <= n; i++) {
            printf("%c%c%c", b[0], a[1], a[0]);
          }
        } else {
          if (b[0] == a[0] && b[0] == a[1]) {
            for (int i = 1; i <= n; i++) {
              printf("abc");
            }
          } else {
            if (a[0] == b[0] || a[1] == b[0]) {
              for (int i = 1; i <= n; i++) {
                if (a[1] != 'a' && a[0] != 'a') printf("%c%ca", a[1], a[0]);
                if (a[1] != 'b' && a[0] != 'b') printf("%c%cb", a[1], a[0]);
                if (a[1] != 'c' && a[0] != 'c') {
                  printf("%c%c", a[1], a[0]);
                  printf("c");
                }
              }
            } else {
              for (int i = 1; i <= n; i++) {
                printf("%c%c%c", b[0], a[1], a[0]);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
