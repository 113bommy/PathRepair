#include <bits/stdc++.h>
using namespace std;
int s, x1, x2;
int p1, p2;
int pos;
int d, t;
int main() {
  int ans = 0;
  scanf("%d%d%d", &s, &x1, &x2);
  scanf("%d%d", &p1, &p2);
  scanf("%d%d", &pos, &d);
  if (p1 >= p2) {
    printf("%d\n", abs(x2 - x1) * p2);
  } else {
    if (x1 < x2)
      t = 1;
    else
      t = -1;
    if (d == t && d == 1) {
      if (x1 >= pos)
        ans = min((x2 - pos) * p1, (x2 - x1) * p2);
      else
        ans = min((s - pos + x2 + s) * p1, (x2 - x1) * p2);
    } else if (d == t && d == -1) {
      if (x1 <= pos)
        ans = min((pos - x2) * p1, (x1 - x2) * p2);
      else
        ans = min((s + pos + s - x2) * p1, (x1 - x2) * p2);
    } else if (d != t && d == -1) {
      ans = min((pos + x2) * p1, (x2 - x1) * p2);
    } else if (d != t && d == 1) {
      ans = min((s + s - pos - x2) * p1, (x1 - x2) * p2);
    }
    printf("%d\n", ans);
  }
  return 0;
}
