#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, h, i, j, ex, p, k;
  cin >> n >> d >> h;
  if ((h > d) || (d > h * 2) || (d == 1 && h == 1 && n > 2)) {
    printf("-1");
    return 0;
  }
  for (i = 1; i <= h; i++) {
    printf("%d %d\n", i, i + 1);
  }
  ex = n - h - 1;
  p = h + 2;
  k = 1;
  for (i = 1; i <= (d - h); i++) {
    printf("%d %d\n", k, p);
    ex--;
    k = p;
    p++;
  }
  if (d > h)
    while (ex > 0) {
      printf("1 %d\n", p);
      ex--;
      p++;
    }
  else
    while (ex > 0) {
      printf("2 %d\n", p);
      ex--;
      p++;
    }
}
