#include <bits/stdc++.h>
int main(void) {
  int x;
  int a = 0, b = 0, c = 0;
  scanf("%d", &x);
  char y[x];
  scanf("%s", y);
  for (int i = 0; i < x; i++) {
    if (y[i] == '0') {
      a++;
    } else if (y[i] == '1') {
      b++;
    } else if (y[i] == '2') {
      c++;
    }
  }
  int m = x / 3;
  a = a - m;
  b = b - m;
  c = c - m;
  int s = 0;
  if (a == 0 && b == 0 && c == 0) {
    printf("%s", y);
  } else if (a != 0 || b != 0 || c != 0) {
    if (a > 0) {
      if (b > 0) {
        s = 0;
        for (int i = x; i >= 0; i--) {
          if (y[i] == '0') {
            y[i] = '2';
            s++;
          }
          if (s == a) {
            break;
          }
        }
        s = 0;
        for (int i = x; i >= 0; i--) {
          if (y[i] == '1') {
            y[i] = '2';
            s++;
          }
          if (s == b) {
            break;
          }
        }
        printf("%s", y);
      } else if (b == 0) {
        s = 0;
        for (int i = x; i >= 0; i--) {
          if (y[i] == '0') {
            y[i] = '2';
            s++;
          }
          if (s == a) {
            break;
          }
        }
        printf("%s", y);
      } else if (b < 0) {
        if (c < 0) {
          for (int i = x; i >= 0; i--) {
            if (y[i] == '0') {
              y[i] = '2';
              c++;
            }
            if (c == 0) {
              break;
            }
          }
          for (int i = x; i >= 0; i--) {
            if (y[i] == '0') {
              y[i] = '1';
              b++;
            }
            if (b == 0) {
              break;
            }
          }
          printf("%s", y);
        } else if (c == 0) {
          for (int i = x; i >= 0; i--) {
            if (y[i] == '0') {
              y[i] = '1';
              b++;
            }
            if (b == 0) {
              break;
            }
          }
          printf("%s", y);
        } else if (c > 0) {
          for (int i = x; i >= 0; i--) {
            if (y[i] == '0') {
              y[i] = '1';
              a--;
            }
            if (a == 0) {
              break;
            }
          }
          for (int i = 0; i < x; i++) {
            if (y[i] == '2') {
              y[i] = '1';
              c--;
            }
            if (c == 0) {
              break;
            }
          }
          printf("%s", y);
        }
      }
    } else if (a == 0) {
      if (b < 0) {
        s = 0;
        for (int i = 0; i < x; i++) {
          if (y[i] == '2') {
            y[i] = '1';
            s++;
          }
          if (s == c) {
            break;
          }
        }
        printf("%s", y);
      } else if (b > 0) {
        s = 0;
        for (int i = x; i >= 0; i--) {
          if (y[i] == '1') {
            y[i] = '2';
            s++;
          }
          if (s == b) {
            break;
          }
        }
        printf("%s", y);
      }
    } else if (a < 0) {
      if (b > 0) {
        if (c < 0) {
          s = 0;
          for (int i = 0; i < x; i++) {
            if (y[i] == '1') {
              y[i] = '0';
              a++;
            }
            if (a == 0) {
              break;
            }
          }
          s = 0;
          for (int i = x; i >= 0; i--) {
            if (y[i] == '1') {
              y[i] = '2';
              c++;
            }
            if (c == 0) {
              break;
            }
          }
          printf("%s", y);
        } else if (c > 0) {
          s = 0;
          for (int i = 0; i < x; i++) {
            if (y[i] == '1') {
              y[i] = '0';
              b--;
            }
            if (b == 0) {
              break;
            }
          }
          s = 0;
          for (int i = 0; i < x; i++) {
            if (y[i] == '2') {
              y[i] = '0';
              c--;
            }
            if (c == 0) {
              break;
            }
          }
          printf("%s", y);
        } else if (c == 0) {
          s = 0;
          for (int i = 0; i < x; i++) {
            if (y[i] == '1') {
              y[i] = '0';
              s++;
            }
            if (s == b) {
              break;
            }
          }
          printf("%s", y);
        }
      } else if (b < 0) {
        s = 0;
        for (int i = 0; i < x; i++) {
          if (y[i] == '2') {
            y[i] = '0';
            a++;
          }
          if (a == 0) {
            break;
          }
        }
        s = 0;
        for (int i = 0; i < x; i++) {
          if (y[i] == '2') {
            y[i] = '1';
            b++;
          }
          if (b == 0) {
            break;
          }
        }
        printf("%s", y);
      } else if (b == 0) {
        s = 0;
        for (int i = 0; i < x; i++) {
          if (y[i] == '2') {
            y[i] = '0';
            s++;
          }
          if (s == c) {
            break;
          }
        }
        printf("%s", y);
      }
    }
  }
  return 0;
}
