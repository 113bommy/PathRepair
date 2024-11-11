#include <bits/stdc++.h>
using namespace std;
int n, m;
int k;
bool debug = false;
double p[105], dp[105 * 3];
double check(double M) {
  for (int i = 0; i < n * 2 + 1; i++) dp[i] = -1;
  dp[0] = 0;
  for (int y = 0; y < 2 * n + 10; y++) {
    for (int s = 0; s <= 2 * n; s++)
      for (int i = 0; i <= n; i++) {
        int ns = s - n + 2 * i;
        if (ns >= 0 && ns <= 2 * n) {
          dp[ns] = max(dp[ns], dp[s] + p[i] - M);
        }
      }
  }
  return dp[0];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    scanf("%lf", p + i);
  }
  double l = 0, r = 1, mid = 0.5;
  while (abs(l - r) > 1e-8) {
    mid = (l + r) / 2;
    if (check(mid) > 0)
      l = mid;
    else
      r = mid;
  }
  printf("%.10lf\n", mid);
  return 0;
}
