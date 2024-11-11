#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using std::bitset;
using namespace std;
double ans;
int m, r;
const double g = 2.0 * sin(3.14159265358979323846 / 4.0);
int main() {
  int i, j, tem;
  while (scanf("%d%d", &m, &r) != EOF) {
    ans = 0;
    for (i = 1; i <= m; i++) {
      if (i - 2 > 0) {
        ans += (i - 2) * (2.0 * r + 2 * g * r) + 1.0 * (i - 3) * (i - 2) * r;
      }
      if (i - 1 > 0) ans += 2.0 * r + g * r;
      ans += 2.0 * r;
      if (i + 1 <= m) ans += 2.0 * r + g * r;
      if (i + 2 <= m) {
        ans += (m - i - 1) * (2.0 * r + 2 * g * r) +
               (m - i - 1) * (m - i - 2.0) * r;
      }
    }
    printf("%.10lf\n", ans / m / m);
  }
  return 0;
}
