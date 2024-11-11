#include <bits/stdc++.h>
using namespace std;
int flag;
void solve(int a1, int b1, int a2, int b2, int a3, int b3, char x, char y,
           char z) {
  if (a1 == a2 && a2 == a3) {
    if (b1 + b2 + b3 == a1) {
      flag = 1;
      printf("%d\n", a1);
      for (int i = 0; i < b1; i++) {
        for (int j = 0; j < a1; j++) {
          printf("%c", x);
        }
        puts("");
      }
      for (int i = 0; i < b2; i++) {
        for (int j = 0; j < a1; j++) {
          printf("%c", y);
        }
        puts("");
      }
      for (int i = 0; i < b3; i++) {
        for (int j = 0; j < a1; j++) {
          printf("%c", z);
        }
        puts("");
      }
      return;
    }
  }
  if (a1 == a2 + a3) {
    if (b1 + b2 == a1 && b2 == b3) {
      flag = 1;
      printf("%d\n", a1);
      for (int i = 0; i < b1; i++) {
        for (int j = 0; j < a1; j++) {
          printf("%c", x);
        }
        puts("");
      }
      for (int i = 0; i < b2; i++) {
        for (int j = 0; j < a1; j++) {
          if (j < a2)
            printf("%c", y);
          else
            printf("%c", z);
        }
        puts("");
      }
      return;
    }
  }
  if (a1 == a2 + b3) {
    if (b1 + b2 == a1 && b2 == a3) {
      flag = 1;
      printf("%d\n", a1);
      for (int i = 0; i < b1; i++) {
        for (int j = 0; j < a1; j++) {
          printf("%c", x);
        }
        puts("");
      }
      for (int i = 0; i < b2; i++) {
        for (int j = 0; j < a1; j++) {
          if (j < a2)
            printf("%c", y);
          else
            printf("%c", z);
        }
        puts("");
      }
      return;
    }
  }
  if (a1 == b2 + b3) {
    if (b1 + a2 == a1 && a2 == a3) {
      flag = 1;
      printf("%d\n", a1);
      for (int i = 0; i < b1; i++) {
        for (int j = 0; j < a1; j++) {
          printf("%c", x);
        }
        puts("");
      }
      for (int i = 0; i < a2; i++) {
        for (int j = 0; j < a1; j++) {
          if (j < b2)
            printf("%c", y);
          else
            printf("%c", z);
        }
        puts("");
      }
      return;
    }
  }
  if (a1 == b2 + b3) {
    if (b1 + a2 == a1 && a2 == a3) {
      flag = 1;
      printf("%d\n", a1);
      for (int i = 0; i < b1; i++) {
        for (int j = 0; j < a1; j++) {
          printf("%c", x);
        }
        puts("");
      }
      for (int i = 0; i < a2; i++) {
        for (int j = 0; j < a1; j++) {
          if (j < b2)
            printf("%c", y);
          else
            printf("%c", z);
        }
        puts("");
      }
      return;
    }
  }
  return;
}
int main() {
  int a1, b1, a2, b2, a3, b3;
  scanf("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3);
  if (a1 < b1) swap(a1, b1);
  if (a2 < b2) swap(a2, b2);
  if (a3 < b3) swap(a3, b3);
  flag = 0;
  solve(a1, b1, a2, b2, a3, b3, 'A', 'B', 'C');
  if (flag == 0) solve(a2, b2, a1, b1, a3, b3, 'B', 'A', 'C');
  if (flag == 0) solve(a3, b3, a2, b2, a1, b1, 'C', 'B', 'A');
  if (flag == 0) {
    printf("-1\n");
  }
  return 0;
}
