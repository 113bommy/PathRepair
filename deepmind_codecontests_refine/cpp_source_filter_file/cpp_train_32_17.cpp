#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  double sum, t;
  int ans;
  while (scanf("%d%d%d", &n, &x, &y) == 3) {
    if (x * 1.0 * 100 / sum > y) {
      printf("0\n");
      continue;
    }
    sum = n * y * 1.0 / 100;
    t = sum - x;
    ans = int(t);
    t -= ans;
    if (t > 0) ans++;
    printf("%d\n", ans);
  }
  return 0;
}
