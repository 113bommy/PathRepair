#include <bits/stdc++.h>
int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int pa, pb;
  pa = ((3 * a / 10 > a - a / 250 * c) ? (3 * a / 10) : (a - a / 250 * c));
  pb = ((3 * b / 10 > b - b / 250 * d) ? (3 * b / 10) : (b - b / 250 * d));
  if (pa > pb) printf("Misha");
  if (pa < pb)
    printf("Vasya");
  else if (pa == pb)
    printf("Tie");
}
