#include <bits/stdc++.h>
using namespace std;
int x, y, a, b;
int main() {
  scanf("%d%d%d%d", &x, &y, &a, &b);
  if (a <= 0 && b >= 0) {
    if ((y - x) >= a && (y - x) <= b)
      printf("FIRST\n%d", y);
    else
      printf("DRAW");
    return 0;
  }
  if ((y - x) * a < 0) {
    printf("DRAW");
    return 0;
  }
  bool sign = false;
  if (a < 0) {
    x *= -1;
    y *= -1;
    a *= -1;
    b *= -1;
    swap(a, b);
    sign = true;
  }
  long long cycleLen =
      (long long)(1) + (a - 1) * 1LL * 2 + (long long)(b - a + 1);
  long long temp = (y - x) % cycleLen;
  if (temp == 0) {
    printf("SECOND");
    return 0;
  }
  if (temp < a || temp > b) {
    printf("DRAW");
    return 0;
  }
  printf("FIRST\n");
  if (!sign)
    printf("%I64d", x + temp);
  else
    printf("%I64d", -(x + temp));
  return 0;
}
