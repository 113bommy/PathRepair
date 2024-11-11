#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
double dp[maxn], p[maxn];
int main() {
  int n;
  scanf("%d", &n);
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p[i]);
    ans += p[i];
  }
  for (int i = 2; i <= n; i++) {
    dp[i] = (dp[i - 1] + p[i - 1] * p[i]);
    ans += 2 * dp[i];
  }
  printf("%.10f\n", ans);
  return 0;
}
