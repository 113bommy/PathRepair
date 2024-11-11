#include <bits/stdc++.h>
using namespace std;
char name[9];
int n, h;
int main() {
  scanf("%s%d%d", name, &n, &h);
  if (name[0] == 'B') {
    printf("%d\n", n);
    return 0;
  } else {
    double ans = n, mid;
    for (int i = 1; i <= h; i++) {
      mid = 1.0;
      for (int j = 1; j < n; j++) {
        ans +=
            (1.0 / (1 << i) / (1 << i)) * mid * (n - j) *
            ((1 << i) - (1 << i - 1) * (1.0 + 1.0 * (j - 1) / ((1 << i) - 1)));
        mid *= (1.0 - 1.0 / (1 << i));
      }
    }
    printf("%.10lf\n", ans);
  }
}
