#include <bits/stdc++.h>
using namespace std;
int x, y;
const int inf = 2000 * 1000 * 1000;
void get(double &ans, int val) {
  int l = 1, r = 1, m;
  while (val / (r * 2) >= y) {
    r *= 2;
  }
  while (r - l > 1) {
    m = (r + l) / 2;
    if (val / (m * 2) >= y) {
      l = m;
    } else {
      r = m;
    }
  }
  ans = (val + 0.0) / (l * 2);
}
int main() {
  scanf("%d %d", &x, &y);
  if (x < y) {
    printf("-1");
    return 0;
  }
  double ans1, ans2 = inf;
  get(ans1, x + y);
  if ((x - y) >= y * 2) {
    get(ans2, x - y);
  }
  printf("%.11f", min(ans1, ans2));
  return 0;
}
