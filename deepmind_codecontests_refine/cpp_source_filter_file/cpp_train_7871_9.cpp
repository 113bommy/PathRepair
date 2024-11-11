#include <bits/stdc++.h>
using namespace std;
int n;
int a[15];
void f(int fg, int x) {
  if (fg == 1) {
    for (int i = 0; i <= 10; i++) {
      if (((x >> i) & 1) != 0) {
        a[i] = 1;
      }
    }
  } else if (fg == 2) {
    for (int i = 0; i <= 10; i++) {
      if (((x >> i) & 1) == 0) {
        a[i] = 0;
      }
    }
  } else {
    for (int i = 0; i <= 10; i++) {
      if (((x >> i) & 1) != 0) {
        if (a[i] == 0 || a[i] == 1)
          a[i] ^= 1;
        else
          a[i] = -a[i];
      }
    }
  }
}
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i <= 10; i++) a[i] = 5;
    for (int i = 0; i < n; i++) {
      char ch;
      int tp;
      getchar();
      scanf("%c", &ch);
      scanf("%d", &tp);
      if (ch == '|')
        f(1, tp);
      else if (ch == '&')
        f(2, tp);
      else
        f(3, tp);
    }
    int ansor = 0;
    int ansand = 1023;
    int ansxor = 0;
    for (int i = 0; i <= 10; i++) {
      if (a[i] == 1) {
        ansor += (1 << i);
      } else if (a[i] == 0) {
        ansand -= (1 << i);
      } else if (a[i] == -5) {
        ansxor += (1 << i);
      }
    }
    printf("3\n");
    printf("| %d\n", ansor);
    printf("& %d\n", ansand);
    printf("^ %d\n", ansxor);
  }
}
