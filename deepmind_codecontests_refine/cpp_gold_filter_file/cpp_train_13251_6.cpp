#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if (c == d) {
    if (a >= c && b >= c && a + b >= c + c + 1) {
      if (a >= c + 1) {
        for (int i = 0; i < a - c; i++) putchar('4');
        for (int i = 0; i < c - 1; i++) printf("74");
        for (int i = 0; i < b - c + 1; i++) putchar('7');
        puts("4");
      } else {
        for (int i = 0; i < c; i++) printf("74");
        for (int i = 0; i < b - c; i++) putchar('7');
      }
    } else
      puts("-1");
  } else if (c == d + 1) {
    if (a >= c && b >= c) {
      for (int i = 0; i < a - c + 1; i++) putchar('4');
      for (int i = 0; i < c - 1; i++) printf("74");
      for (int i = 0; i < b - c + 1; i++) putchar('7');
    } else
      puts("-1");
  } else if (c + 1 == d) {
    if (a >= d && b >= d) {
      putchar('7');
      for (int i = 0; i < a - c; i++) putchar('4');
      for (int i = 0; i < c - 1; i++) printf("74");
      for (int i = 0; i < b - c; i++) putchar('7');
      putchar('4');
    } else
      puts("-1");
  } else
    puts("-1");
}
