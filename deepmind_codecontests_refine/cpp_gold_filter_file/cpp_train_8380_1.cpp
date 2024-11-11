#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, sum, x, y, x0, y0, a[505][505];
  char s[1000005];
  while (~scanf("%d%d%d%d", &x, &y, &x0, &y0)) {
    memset(a, 0, sizeof(a));
    scanf("%s", s);
    l = strlen(s);
    sum = 0;
    for (int i = 0; i < l; i++) {
      if (!a[x0][y0]) {
        sum++;
        printf("1 ");
        a[x0][y0] = 1;
      } else
        printf("0 ");
      if (s[i] == 'U') x0--;
      if (s[i] == 'D') x0++;
      if (s[i] == 'L') y0--;
      if (s[i] == 'R') y0++;
      if (x0 <= 1) x0 = 1;
      if (y0 <= 1) y0 = 1;
      if (x0 > x) x0 = x;
      if (y0 > y) y0 = y;
    }
    printf("%d\n", x * y - sum);
  }
  return 0;
}
