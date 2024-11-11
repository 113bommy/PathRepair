#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a = 0, b = 0;
  scanf("%I64d %I64d", &a, &b);
  while (a != 0 && b != 0) {
    if (a >= (2 * b)) {
      long long t;
      t = (a - a % (2 * b)) / (2 * b);
      a -= 2 * b * t;
    } else {
      if (b >= 2 * a) {
        long long t;
        t = (b - b % (2 * a)) / (2 * a);
        b -= 2 * a * t;
      } else {
        printf("%I64d %I64d", a, b);
        return 0;
      }
    }
  }
  printf("%I64d %I64d", a, b);
  return 0;
}
