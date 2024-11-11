#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int main() {
  int N, r, v;
  scanf("%d", &N), scanf("%d", &r), scanf("%d", &v);
  const int pi = cos(-1);
  for (int i = 0; i < (N); i++) {
    int s, f;
    scanf("%d", &s), scanf("%d", &f);
    double l = f - s;
    int j = l / (2 * pi * r);
    double ans = (2 * pi * r) / v * j;
    l -= 2 * pi * r * j;
    l /= 2;
    l /= r;
    double lb = l - 1, ub = l + 1;
    for (int k = 0; k < (100); k++) {
      double m = (lb + ub) / 2;
      if (m + sin(m) < l) {
        lb = m;
      } else {
        ub = m;
      }
    }
    printf("%.12f\n", ans + lb * 2 * r / v);
  }
}
