#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long a[N], sum[N], n, d, b;
long long gt(long long x, long long y) {
  if (x < 1) x = 1;
  if (y > n) y = n;
  return sum[y] - sum[x - 1];
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &d, &b);
  for (long long i = 1; i <= n; i++)
    scanf("%I64d", &a[i]), sum[i] = sum[i - 1] + a[i];
  long long x1 = 0, x2 = 0;
  for (long long i = 1; i <= n / 2; i++) {
    if (gt(1, i + d * i) >= (x1 + 1) * b) x1++;
    if (gt(n - i + 1 - d * i, n) > (x2 + 1) * b) x2++;
  }
  printf("%I64d", max(n / 2 - x1, n / 2 - x2));
  return 0;
}
