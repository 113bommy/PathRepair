#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, x1, x2, t1, t2, p, d;
  scanf("%d%d%d%d%d%d%d", &s, &x1, &x2, &t1, &t2, &p, &d);
  int foottime = abs(x2 - x1) * t2;
  int tramtime;
  int dd = x2 > x1 ? 1 : -1;
  int td = d;
  while (p != x1 || td != dd) {
    if (td == 1) {
      if (x1 <= p) {
        td = -td;
        tramtime += (s - p) * t1;
        p = s;
      } else {
        tramtime += (x1 - p) * t1;
        p = x1;
      }
    } else {
      if (x1 >= p) {
        td = -td;
        tramtime += (p)*t1;
        p = 0;
      } else {
        tramtime += (p - x1) * t1;
        p = x1;
      }
    }
  }
  tramtime += abs(x2 - x1) * t1;
  printf("%d\n", min(tramtime, foottime));
  return 0;
}
