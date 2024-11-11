#include <bits/stdc++.h>
int max(int a, int b);
int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if (max(3 * a / 10, a - a / 250 * c) > max(3 * b / 10, b - b / 250 * c)) {
    printf("Misha");
  } else if (max(3 * b / 10, b - b / 250 * c) >
             max(3 * a / 10, a - a / 250 * c)) {
    printf("Vasya");
  } else
    printf("Tie");
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
