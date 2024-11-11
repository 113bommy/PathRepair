#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int maxn = 1e6 + 10;
double a[maxn];
double dp[maxn];
double sum[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  sum[0] = 0;
  double Max = 0;
  for (int i = m; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      Max = max<double>(Max, (sum[j] - sum[j - i]) / ((i)*1.0));
    }
  }
  printf("%.12lf\n", Max);
  return 0;
}
