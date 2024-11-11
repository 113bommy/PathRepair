#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, x, y, x1, y2, n;
  scanf("%lld%lld%lld", &a, &x, &y);
  if (y > 0) {
    n = ceil((float)y / a);
    if (n == 1) {
      if (y, n * a) {
        if (x < (float)a / 2 && x > -(float)a / 2) {
          printf("%lld", n);
          return 0;
        }
      }
    } else {
      if (n % 2 == 0) {
        if (y < n * a) {
          if (x < (float)a / 2 && x > -(float)a / 2) {
            printf("%lld", n + n / 2 - 1);
            return 0;
          }
        }
      } else {
        if (y < n * a) {
          if (x < a && x > 0) {
            printf("%lld", n + n / 2);
            return 0;
          } else {
            if (x > -a && x < 0) {
              printf("%lld", n + n / 2 - 1);
              return 0;
            }
          }
        }
      }
    }
  }
  printf("-1");
  return 0;
}
