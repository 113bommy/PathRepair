#include <bits/stdc++.h>
using namespace std;
long long n, k, i, j, b[2010], a[2010], ans[2010];
long long p(long long b, long long e) {
  long long ret = 1;
  while (e) {
    if (e & 1) ret = (ret * b) % 1000000007;
    b = (b * b) % 1000000007;
    e >>= 1;
  }
  return ret;
}
int main() {
  scanf("%I64d%I64d", &n, &k);
  b[1] = 1;
  k--;
  for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (i = 2; i <= n; i++)
    b[i] =
        (((b[i - 1] * (k + i - 1)) % 1000000007) * p(i - 1, 1000000007 - 2)) %
        1000000007;
  for (i = 1; i <= n; i++)
    for (j = i; j <= n; j++)
      ans[j] = (ans[j] + a[i] * b[j - i + 1]) % 1000000007;
  for (i = 1; i <= n; i++) printf("%I64d ", ans[i]);
  return 0;
}
