#include <bits/stdc++.h>
const int N = 1234567;
long long a[N], b[N], i, j;
using namespace std;
int main() {
  long long n, m;
  while (scanf("%lld %lld", &n, &m) == 2) {
    for (i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (i = 0; i < m; i++) scanf("%lld", &b[i]);
    long long cnt = 0, sum1 = 0, sum2 = 0;
    long long x = max(n, m);
    for (i = 0, j = 0; i < x;) {
      if (sum1 <= sum2) {
        sum1 += a[i];
        i++;
      }
      if (sum1 > sum2) {
        sum2 += b[j];
        j++;
      }
      if (sum1 == sum2) {
        cnt++;
        sum1 = 0, sum2 = 0;
      }
      if (j == m && sum1 == 0) break;
      if (i == n && sum2 == 0) break;
    }
    printf("%lld\n", cnt);
  }
  return 0;
}
