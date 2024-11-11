#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 4e6 + 10, inf = 1e9 + 10, mod = 1e9 + 7;
const long long INF = 1e18 + 10, MOD = 1e9 + 7;
double a[110], b[110], pre[N];
double dp[110];
int flag[N];
int cmp(double a, double b) { return a > b; }
int main() {
  pre[0] = 1.0;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) b[i] = 1.0 - a[i], pre[i] = pre[i - 1] * b[i];
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    double sum = a[1];
    for (int j = 2; j <= i; j++) {
      sum = b[j] * sum + a[j] * pre[j - 1];
    }
    ans = max(ans, sum);
  }
  printf("%.12f\n", ans);
  return 0;
}
