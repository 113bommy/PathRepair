#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, i, j, k, l;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  i = max((3 * a) / 10, (a - (a / 250)) * c);
  j = max((3 * b) / 10, (b - (b / 250)) * d);
  if (i > j) {
    printf("Misha\n");
  } else if (i < j) {
    printf("Vasya\n");
  } else
    printf("Tie\n");
  return 0;
}
