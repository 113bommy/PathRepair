#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  int max1, max2;
  if (((3 * a) / 10) > (a - ((a / 250) * c))) {
    max1 = ((3 * a) / 10);
  } else {
    max1 = (a - ((a / 250) * c));
  }
  if (((3 * b) / 10) > (b - ((b / 250) * d))) {
    max2 = ((3 * b) / 10);
  } else {
    max2 = (b - ((b / 250) * d));
  }
  if (max1 == max2) {
    printf("%s", "Tie");
    return 0;
  }
  if (max1 > max2) {
    printf("%s", "Misha");
    return 0;
  }
  if (max1 < max2) {
    printf("%s", "Vanya");
    return 0;
  }
}
