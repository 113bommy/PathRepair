#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
template <class Z>
inline bool checkmax(Z &a, Z b) {
  if (a == -1 || a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class Z>
inline bool checkmin(Z &a, Z b) {
  if (a == -1 || a > b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  double x1, y1, r1, x2, y2, r2;
  while (cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2) {
    double x, y, r;
    double dis1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    double dis2 = r1 + r2;
    dis1 = sqrt(dis1);
    double maxi = max(r1, r2);
    double mini = min(r1, r2);
    if (dis1 < maxi - mini) {
      printf("%.6f\n", (maxi - dis1 - mini) / 2);
    } else if (dis1 > maxi + mini) {
      printf("%.6f\n", (dis1 - dis2) / 2);
    } else
      printf("0\n");
  }
}
