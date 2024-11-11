#include <bits/stdc++.h>
using namespace std;
int main() {
  int long a, b, x1, x2, y1, y2;
  cin >> a >> b;
  if (a > 0 && b > 0) {
    printf("0 %ld %ld 0\n", (a + b), (a + b));
  } else if (a < 0 && b > 0) {
    x1 = -a + b;
    y1 = 0;
    x2 = 0;
    y2 = x1 * -1;
    printf("%ld 0 0 %ld\n", y2, x1);
  } else if (a > 0 && b < 0) {
    x1 = a + (b * -1);
    y2 = x1 * -1;
    printf("0 %ld %ld 0\n", y2, x1);
  } else {
    x1 = a + b;
    y2 = x1 * -1;
    printf("%ld 0 0 %ld\n", x1, x1);
  }
  return 0;
}
