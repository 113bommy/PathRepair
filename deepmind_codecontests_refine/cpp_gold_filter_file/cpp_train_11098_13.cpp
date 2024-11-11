#include <bits/stdc++.h>
using namespace std;
int main() {
  char a, b;
  scanf("%c %c", &a, &b);
  int n;
  scanf("%d", &n);
  n %= 4;
  if (a == '^') {
    if ((n == 1 && b == '>') || (n == 3 && b == '<')) {
      printf("cw\n");
    } else if (n == 1 && b == '<' || n == 3 && b == '>') {
      printf("ccw\n");
    } else {
      printf("undefined\n");
    }
  } else if (a == '>') {
    if (n == 1 && b == 'v' || n == 3 && b == '^') {
      printf("cw\n");
    } else if (n == 1 && b == '^' || n == 3 && b == 'v') {
      printf("ccw\n");
    } else {
      printf("undefined\n");
    }
  } else if (a == 'v') {
    if (n == 1 && b == '<' || n == 3 && b == '>') {
      printf("cw\n");
    } else if (n == 1 && b == '>' || n == 3 && b == '<') {
      printf("ccw\n");
    } else {
      printf("undefined\n");
    }
  } else if (a == '<') {
    if (n == 1 && b == '^' || n == 3 && b == 'v') {
      printf("cw\n");
    } else if (n == 1 && b == 'v' || n == 3 && b == '^') {
      printf("ccw\n");
    } else {
      printf("undefined\n");
    }
  }
  return 0;
}
