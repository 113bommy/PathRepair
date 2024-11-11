#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e10;
long long n, m, k;
int run() {
  long long ans = 0;
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  if (n + m - 2 < k) {
    puts("-1");
    return 0;
  }
  if (n > k) ans = max(ans, n / (k + 1) * m);
  if (m > k) ans = max(ans, m / (k + 1) * n);
  if (m <= k) ans = max(ans, n / (k - m + 2));
  if (n <= k) ans = max(ans, m / (k - n + 2));
  printf("%I64d\n", ans);
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  return run();
}
