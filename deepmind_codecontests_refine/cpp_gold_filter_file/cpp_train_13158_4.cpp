#include <bits/stdc++.h>
using namespace std;
long long a[1000000], sum[1000000], mx[1000000], mxb[1000000];
long long strt[1000000], strtb[1000000];
int main() {
  long long n, m, i, j, k, l;
  scanf("%I64d", &n);
  scanf("%I64d", &k);
  for (i = 1; i <= (n); i++) {
    scanf("%I64d", &a[i]);
  }
  for (i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  for (i = 1; i < k; i++) mx[i] = -1000000000000000000;
  mx[k] = sum[k];
  strt[k] = 1;
  for (i = k + 1; i <= n; i++) {
    if (mx[i - 1] >= sum[i] - sum[i - k]) {
      mx[i] = mx[i - 1];
      strt[i] = strt[i - 1];
    } else {
      mx[i] = sum[i] - sum[i - k];
      strt[i] = i - k + 1;
    }
  }
  for (i = n; i > n - k + 1; i--) mxb[i] = -1000000000000000000;
  mxb[n - k + 1] = sum[n] - sum[n - k];
  strtb[n - k + 1] = n - k + 1;
  for (i = n - k; i > 0; i--) {
    if (mxb[i + 1] > sum[i + k - 1] - sum[i - 1]) {
      mxb[i] = mxb[i + 1];
      strtb[i] = strtb[i + 1];
    } else {
      mxb[i] = sum[i + k - 1] - sum[i - 1];
      strtb[i] = i;
    }
  }
  long long ans = 0, a, b;
  for (i = k; i <= n - k; i++) {
    if (mx[i] + mxb[i + 1] > ans) {
      ans = mx[i] + mxb[i + 1];
      a = strt[i];
      b = strtb[i + 1];
    }
  }
  printf("%I64d\n", a);
  printf("%I64d\n", b);
  return 0;
}
