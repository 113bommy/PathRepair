#include <bits/stdc++.h>
using namespace std;
long long a[100010];
int n;
inline long long Pow(long long x, long long y) {
  long long num = 1, nu = x;
  while (y) {
    if (y & 1ll) num = num * nu % 1000000007;
    nu = nu * nu % 1000000007;
    y /= 2ll;
  }
  return (num);
}
int main() {
  scanf("%d", &n);
  bool pd = 0, pd1 = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    if (a[i] % 2ll == 0 && a[i] != 1) pd = 1;
    if (a[i] != 1) pd1 = 1;
  }
  if (!pd1) {
    puts("0/1");
    return (0);
  }
  long long N = 2;
  for (int i = 1; i <= n; i++) N = Pow(N, a[i]);
  N = N * 500000004 % 1000000007;
  if (pd) {
    printf("%I64d/%I64d\n", (N + 1) * 333333336 % 1000000007, N);
  } else {
    printf("%I64d/%I64d\n",
           (N - 1 + 1000000007) % 1000000007 * 333333336 % 1000000007, N);
  }
}
