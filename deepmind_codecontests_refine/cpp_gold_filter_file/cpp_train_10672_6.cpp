#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e5 + 10;
double p[maxm];
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    for (int i = 0; i < n; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      int x = (r / k - (l - 1) / k);
      p[i] = (double)x / (r - l + 1);
    }
    p[n] = p[0];
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (p[i] + p[i + 1] - p[i] * p[i + 1]) * 2000.0;
    }
    printf("%lf\n", ans);
  }
  return 0;
}
