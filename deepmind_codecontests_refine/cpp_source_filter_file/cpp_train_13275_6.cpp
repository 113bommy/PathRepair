#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x;
  scanf("%lld", &x);
  x = x % 360;
  if (x > 45 && x <= 135)
    printf("%d\n", 1);
  else if (x > 135 && x <= 225)
    printf("%d\n", 2);
  else if (x > 225 && x < 315)
    printf("%d\n", 3);
  else if (x < -45 && x >= -135)
    printf("%d\n", 3);
  else if (x < -135 && x >= -225)
    printf("%d\n", 2);
  else if (x < -225 && x > -315)
    printf("%d\n", 1);
  else
    printf("%d\n", 0);
  return 0;
}
