#include <bits/stdc++.h>
int compare(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  int a, b, c, d, a1, b1, a2, b2;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  a1 = a * 3 / 10;
  b1 = b * 3 / 10;
  a2 = a - a / 250 * c;
  b2 = b - b / 250 * d;
  if (compare(a1, a2) > compare(b1, b2))
    printf("Misha");
  else if (compare(a1, a2) < compare(b1, b2))
    printf("Visya");
  else
    printf("Tie");
  return 0;
}
