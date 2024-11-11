#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const double eps = 1e-6;
int a[N];
int num[N];
double dp[N];
int main() {
  int n, k;
  scanf("%d %d", &k, &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  sort(a + 1, a + 1 + n);
  for (int i = n; i >= 2; i--) a[i] = a[i] - a[i - 1];
  double l = -1e9, r = 0;
  double mid;
  while (r - l > eps) {
    mid = (l + r) / 2;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1];
      num[i] = num[i - 1];
      if (dp[i - 2] + a[i] + mid < dp[i]) {
        dp[i] = dp[i - 2] + a[i] + mid;
        num[i] = num[i - 2] + 1;
      }
    }
    if (num[n] == k) {
      printf("%lld\n", (long long)(dp[n] - mid * k + 1500 * eps));
      return 0;
    }
    if (num[n] > k)
      l = mid;
    else
      r = mid;
  }
  for (int i = 5; i >= -5; i--) {
    double x = mid + i * eps;
    for (int j = 2; j <= n; j++) {
      dp[j] = dp[j - 1];
      num[j] = num[j - 1];
      if (dp[j - 2] + a[j] + x < dp[j]) {
        dp[j] = dp[j - 2] + a[j] + x;
        num[j] = num[j - 2] + 1;
      }
    }
    if (num[n] == k || i == -5) {
      for (int j = 2; j <= n; j++) {
        dp[j] = dp[j - 1];
        num[j] = num[j - 1];
        if (dp[j - 2] + a[j] + x < dp[j]) {
          dp[j] = dp[j - 2] + a[j] + x;
          num[j] = num[j - 2] + 1;
        }
      }
      printf("%lld\n", (long long)(dp[n] - x * k + 1500 * eps));
      return 0;
    }
  }
}
