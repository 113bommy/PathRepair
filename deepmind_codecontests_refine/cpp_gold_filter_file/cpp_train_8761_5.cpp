#include <bits/stdc++.h>
using namespace std;
int n, k, a[100050], sum[100050];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%1d", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= n - k + 1; i++) {
    if (sum[i - 1] + (sum[n] - sum[i + k - 1]) == 0)
      return printf("tokitsukaze"), 0;
    if (sum[i - 1] + (sum[n] - sum[i + k - 1]) == n - k)
      return printf("tokitsukaze"), 0;
  }
  if (k * 2 < n) return printf("once again"), 0;
  int l = n - k - 1;
  if (sum[l] == l && sum[n] - sum[n - l] == 0) return printf("quailty"), 0;
  if (sum[l] == 0 && sum[n] - sum[n - l] == l) return printf("quailty"), 0;
  return printf("once again"), 0;
}
