#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, t;
  long long k;
  cin >> n >> m >> k;
  if (k < n)
    printf("%d 1\n", k + 1);
  else {
    k -= (n - 1), m -= 1;
    a = k / m;
    b = k % m;
    if (a % 2 == 0) {
      if (b == 0)
        t = 1;
      else
        t = b;
      if (b > 0) {
        a += 1;
        a = n - a + 1;
        printf("%d %d\n", a, t + 1);
      } else {
        printf("%d %d\n", n - a + 1, t + 1);
      }
    } else {
      if (b > 0) {
        a += 1;
        a = n - a + 1;
        printf("%d %d\n", a, m - b + 2);
      } else {
        b = 1;
        printf("%d %d\n", n - a + 1, m - b + 2);
      }
    }
  }
  return 0;
}
