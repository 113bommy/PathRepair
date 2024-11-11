#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, k1, k2;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  k1 = max(3 * a / 10, a - a * c / 250);
  k2 = max(3 * b / 10, b - b * d / 250);
  if (k1 > k2)
    printf("Misha\n");
  else if (k2 > k1)
    printf("Vaya\n");
  else
    printf("Tie\n");
  return 0;
}
