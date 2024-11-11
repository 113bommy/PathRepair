#include <bits/stdc++.h>
using namespace std;
int a1, a2, a3, a4;
int main() {
  int i, n, x, as, k;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x == 1) a1++;
    if (x == 2) a2++;
    if (x == 3) a3++;
    if (x == 4) a4++;
  }
  x = a1 + a2 * 2 + a3 * 3 + a4;
  if (x == 1 || x == 2 || x == 5) {
    puts("-1");
    return 0;
  }
  if (a1 >= a2) {
    a1 -= a2;
    a3 += a2;
    as = 100000000;
    for (i = 0; i <= a1; i++)
      if (i >= (a1 - i) * 2) {
        if (i - (a1 - i) * 2 <= a3 + (a1 - i)) as = min(as, i);
      } else {
        if (i + a4 >= (a1 - i) * 2) as = min(as, (a1 - i) * 2);
      }
    as += a2;
    if (as >= 100000000) as = -1;
  } else {
    a2 -= a1;
    a3 += a1;
    as = 100000000;
    for (i = 0; i <= a2; i++) {
      if (2 * i <= a2 - i) {
        if (2 * i + a4 >= a2 - i) as = min(as, a2 - i);
      } else {
        if (2 * i - (a2 - i) <= a3 + (a2 - i)) as = min(as, 2 * i);
      }
    }
    as += a1;
    if (as >= 100000000) as = -1;
  }
  printf("%d\n", as);
  return 0;
}
