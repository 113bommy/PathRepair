#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
  while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
    if (abs(c - d) > 1) {
      puts("-1");
      continue;
    }
    if (c == d) {
      int a1 = a - (c + 1);
      int b1 = b - c;
      if (a1 >= 0 && b1 >= 0) {
        for (int i = 1; i <= a1; i++) printf("4");
        for (int i = 1; i <= c; i++) printf("47");
        for (int i = 1; i <= b1; i++) printf("7");
        printf("4");
        puts("");
        continue;
      }
      a1 = a - c;
      b1 = b - c;
      if (a1 < 0 || b1 < 1)
        puts("-1");
      else {
        printf("74");
        for (int i = 1; i <= a1; i++) printf("4");
        for (int i = 1; i < c; i++) printf("74");
        for (int i = 1; i <= b1; i++) printf("7");
        puts("");
      }
    } else if (c > d) {
      int a1 = a - c;
      int b1 = b - c;
      if (a1 < 0 || b1 < 0)
        puts("-1");
      else {
        for (int i = 1; i <= a1; i++) printf("4");
        for (int i = 1; i <= c; i++) printf("47");
        for (int i = 1; i <= b1; i++) printf("7");
      }
    } else if (d > c) {
      int a1 = a - d;
      int b1 = b - d;
      if (a1 < 0 || b1 < 0)
        puts("-1");
      else {
        printf("74");
        for (int i = 1; i <= a1; i++) printf("4");
        for (int i = 1; i <= d - 2; i++) printf("74");
        for (int i = 1; i <= b1; i++) printf("7");
        printf("74");
      }
    }
  }
}
