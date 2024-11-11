#include <bits/stdc++.h>
using namespace std;
const int maxn = 2100;
int n, a[maxn], b[maxn];
int main() {
  while (scanf("%d", &n) != EOF) {
    int cnta = 0, cntb = 0, sum = 0;
    for (int i = 0; i < 2 * n; i++) {
      scanf("%d.%d", &a[i], &b[i]);
      if (b[i]) {
        sum += b[i];
        cntb++;
      } else
        cnta++;
    }
    int ans = 1 << 29;
    for (int i = 0; i <= min(n, cnta); i++) {
      if (i + cnta < n) continue;
      ans = min(ans, abs(i * 1000 - sum));
    }
    printf("%.3f\n", fabs(ans * 1.0 / 1000));
  }
  return 0;
}
