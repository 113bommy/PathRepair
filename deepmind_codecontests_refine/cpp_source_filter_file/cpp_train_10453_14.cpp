#include <bits/stdc++.h>
using namespace std;
long long w[111111], ww[111111];
long long sum[111111];
int main() {
  long long n, l, r, ql, qr;
  scanf("%I64d%I64d%I64d%I64d%I64d", &n, &l, &r, &ql, &qr);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &w[i]);
    sum[i] = sum[i - 1] + w[i];
  }
  long long ans = 111111111111111ll;
  for (int i = 1; i <= n; i++) {
    int t = 0;
    if (i > n - i)
      t = (2 * i - n - 1) * ql;
    else if (i < n - i)
      t = (n - 2 * i - 1) * qr;
    ans = min(ans, sum[i] * l + (sum[n] - sum[i]) * r + t);
  }
  printf("%I64d", ans);
  return 0;
}
