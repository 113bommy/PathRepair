#include <bits/stdc++.h>
using namespace std;
int q, a[1000010];
long long x, y;
int main(void) {
  int i = 0;
  scanf("%d %I64d", &q, &x);
  int q0 = q + 1;
  while (q--) {
    scanf("%I64d", &y);
    if (labs(y - i) % x == 0) {
      a[i]++;
      while (a[i] && i <= q0) {
        if (a[i] > 1) {
          if (i + x <= q0) a[i + x] += a[i] - 1;
          a[i] = 1;
        }
        i++;
      }
      printf("%d\n", i);
    } else {
      printf("%d\n", i);
      if (y < i) {
        y %= x;
        long long t = (i - y) / x + 1;
        y += t * x;
        if (y <= q0) a[y]++;
      } else {
        int t = (y - i) / x;
        y -= t * x;
        if (y < 0) y += x;
        if (y <= q0) a[y]++;
      }
    }
  }
  return 0;
}
