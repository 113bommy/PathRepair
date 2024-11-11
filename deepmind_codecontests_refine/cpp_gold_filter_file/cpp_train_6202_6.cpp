#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, x1, x2, t1, t2, p, d, r1, r2;
  scanf("%d %d %d", &s, &x1, &x2);
  scanf("%d %d", &t1, &t2);
  scanf("%d %d", &p, &d);
  if (t1 >= t2) {
    printf("%d\n", abs(x2 - x1) * t2);
    return 0;
  } else {
    r1 = abs(x2 - x1) * t2;
    r2 = 0;
    bool flag = 0;
    while (1) {
      if (p == x1) flag = 1;
      if (flag && p == x2) break;
      r2 += t1;
      if (p == s) d = -1;
      if (p == 0) d = 1;
      if (d == -1)
        p--;
      else
        p++;
    }
  }
  printf("%d\n", min(r1, r2));
}
