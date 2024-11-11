#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, x1, x2, t1, t2, p, d, ans1, ans2;
  char mid;
  while (scanf("%d %d %d", &s, &x1, &x2) != EOF) {
    scanf("%d %d", &t1, &t2);
    scanf("%d %d", &p, &d);
    ans1 = t2 * abs(x1 - x2);
    if (x1 > x2) {
      x1 = s - x1;
      x2 = s - x2;
      d = -d;
      p = s - p;
    }
    if (d < 0)
      ans2 = (x2 + p) * t1;
    else {
      if (p <= x1)
        ans2 = (x2 - p) * t1;
      else
        ans2 = (s + s - p + x2) * t1;
    }
    printf("%d\n", min(ans1, ans2));
  }
}
