#include <bits/stdc++.h>
using namespace std;
char s[2001000];
int main() {
  int a, b, c, d, i, j;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  i = 0;
  if (c == d) {
    if (a > c && b >= c) {
      for (j = 0; j < a - c; s[i++] = '4', j++)
        ;
      for (j = 0; j < c - 1; s[i++] = '7', s[i++] = '4', j++)
        ;
      for (j = 0; j < b - c + 1; s[i++] = '7', j++)
        ;
      s[i++] = '4';
    } else if (b > c && a >= c) {
      s[i++] = '7';
      for (j = 0; j < a - c; s[i++] = '4', j++)
        ;
      for (j = 0; j < c; s[i++] = '4', s[i++] = '7', j++)
        ;
      for (j = 0; j < b - c - 1; s[i++] = '7', j++)
        ;
    } else {
      s[0] = '-';
      s[1] = '1';
    }
  } else if (c == d + 1) {
    if (a >= c && b >= c) {
      for (j = 0; j < a - c; s[i++] = '4', j++)
        ;
      for (j = 0; j < c; s[i++] = '4', s[i++] = '7', j++)
        ;
      for (j = 0; j < b - c; s[i++] = '7', j++)
        ;
    } else {
      s[0] = '-';
      s[1] = '1';
    }
  } else if (d == c + 1) {
    if (b >= c && a >= c) {
      s[i++] = '7';
      for (j = 0; j < a - c; s[i++] = '4', j++)
        ;
      for (j = 0; j < c - 1; s[i++] = '4', s[i++] = '7', j++)
        ;
      for (j = 0; j < b - c; s[i++] = '7', j++)
        ;
      s[i++] = '4';
    } else {
      s[0] = '-';
      s[1] = '1';
    }
  } else {
    s[0] = '-';
    s[1] = '1';
  }
  printf("%s\n", s);
  return 0;
}
