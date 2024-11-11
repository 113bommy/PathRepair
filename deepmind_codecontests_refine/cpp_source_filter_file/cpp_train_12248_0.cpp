#include <bits/stdc++.h>
using namespace std;
int n, a, b, l, p, i, j, x, y, flag;
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (i = 1; i * a <= n; i++) {
    j = n - i * a;
    if (j % b == 0) {
      x = i;
      y = j / b;
      flag = 1;
      break;
    }
  }
  if (!flag) {
    printf("-1");
    return 0;
  }
  l = p = 1;
  for (i = 1; i <= x; i++) {
    for (j = 1; j < a; j++) printf("%d ", ++p);
    printf("%d ", l);
    l = ++p;
  }
  for (i = 1; i <= y; i++) {
    for (j = 1; j < b; j++) printf("%d ", ++p);
    printf("%d ", l);
    l = ++p;
  }
  return 0;
}
