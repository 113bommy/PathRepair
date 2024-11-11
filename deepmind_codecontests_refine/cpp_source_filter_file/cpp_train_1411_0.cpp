#include <bits/stdc++.h>
using namespace std;
int n, k;
double p[20];
double dp[(1 << 20)];
double ans[20];
int main() {
  int M = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &p[i]);
    if (p[i] < 0.0001) M++;
  }
  dp[0] = 1.0;
  for (int state = 0; state < (1 << n); ++state) {
    double P_change = 0.0;
    int onCache = 0;
    for (int i = 0; i < n; ++i) {
      if ((1 << i) & state) {
        onCache++;
      } else {
        P_change += p[i];
      }
    }
    if (onCache == k - M) {
      for (int i = 0; i < n; ++i) {
        if ((1 << i) & state) {
          ans[i] += dp[state];
        }
      }
      continue;
    }
    if (P_change < 1e-17) continue;
    for (int i = 0; i < n; ++i) {
      if (!((1 << i) & state)) {
        if (((p[i] / P_change)) > 1e-17)
          dp[state | (1 << i)] += dp[state] * (p[i] / P_change);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%.11lf ", ans[i]);
  }
  puts("");
  return 0;
}
