#include <bits/stdc++.h>
using namespace std;
long long int prod(long long int a, long long int b) {
  long long int x, d;
  if (b == 0)
    return 1;
  else {
    d = prod(a, b / 2);
    x = (d * d) % 1000000007;
    if (b % 2 == 0)
      return x;
    else
      return (x * (a % 1000000007)) % 1000000007;
  }
}
int main() {
  long long int n, m, i, j, ans, a[100005], b[100005];
  scanf("%lld", &n), scanf("%lld", &m);
  for (i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (i = 0; i < m; i++) scanf("%lld", &b[i]);
  j = 0;
  ans = -1;
  for (i = 0; i < n; i++) {
    while (j + 1 < m && abs(b[j + 1] - a[i]) < abs(b[j] - a[i])) j++;
    ans = max(ans, abs(b[j] - a[i]));
  }
  printf("%lld\n", ans);
  return 0;
}
