#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
int main() {
  int s, x1, x2;
  int t1, t2;
  int p, d;
  scanf("%d%d%d", &s, &x1, &x2);
  scanf("%d%d", &t1, &t2);
  scanf("%d%d", &p, &d);
  int ans = abs(x1 - x2) * t2;
  if (x1 < x2) {
    if (d == -1)
      ans = min(ans, (p + x2) * t1);
    else if (d == 1) {
      if (p <= x1)
        ans = min(ans, (x2 - p) * t1);
      else
        ans = min(ans, ((s - p) + s + x2) * t1);
    }
  } else {
    if (d == 1)
      ans = min(ans, (s - p + s - x2) * t1);
    else if (d == -1) {
      if (p >= x1)
        ans = min(ans, (p - x2) * t1);
      else
        ans = min(ans, (p + s + s - x2) * t1);
    }
  }
  printf("%d", ans);
}
