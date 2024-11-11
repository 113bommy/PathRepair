#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int n, tot, a[N], ans, b[6] = {8, 7, 6, 7, 6, 5};
int x, y, z;
long long t;
void output(int f) {
  switch (f) {
    case 1:
      printf("%d %d %d %d\n", x - 1, y + 1, x, y + 1);
      return;
    case 2:
      printf("%d %d %d %d\n", x - 1, y + 2, x, y + 2);
      return;
    case 4:
      printf("%d %d %d %d\n", x + 2, y - 1, x + 2, y);
      return;
  }
}
int main() {
  scanf("%lld", &t);
  while (t) {
    a[++tot] = t % 6;
    t /= 6;
  }
  n = (tot << 1) + 2;
  printf("%d %d\n", n, n);
  for (int i = 1; i <= tot; i++) ans += b[a[i]];
  ans += (n << 1) - 10;
  printf("%d\n", ans);
  y = 5;
  z = n - 5;
  for (int i = 1; i <= z; i += 2) {
    printf("%d %d %d %d\n%d %d %d %d\n", i, y, i, y + 1, i + 1, y, i + 1,
           y + 1);
    printf("%d %d %d %d\n%d %d %d %d\n", i + 1, y - 1, i + 1, y, i + 2, y - 1,
           i + 2, y);
    printf("%d %d %d %d\n%d %d %d %d\n", y, i, y + 1, i, y, i + 1, y + 1,
           i + 1);
    printf("%d %d %d %d\n%d %d %d %d\n", y - 1, i + 1, y, i + 1, y - 1, i + 2,
           y, i + 2);
    y += 2;
  }
  printf("1 2 2 2\n2 1 2 2\n");
  x = y = 2;
  for (int i = tot; i >= 1; i--) {
    printf("%d %d %d %d\n", x + 1, y - 1, x + 1, y);
    switch (a[i]) {
      case 0:
        output(1);
        output(2);
        output(4);
        break;
      case 1:
        output(1);
        output(4);
        break;
      case 2:
        output(1);
        break;
      case 3:
        output(2);
        output(4);
        break;
      case 4:
        output(4);
        break;
    }
    x += 2;
    y += 2;
  }
  return 0;
}
