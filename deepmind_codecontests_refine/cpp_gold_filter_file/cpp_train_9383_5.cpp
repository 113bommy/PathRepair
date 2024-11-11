#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 20;
long long a[maxn];
double ans;
int main() {
  long long i, j, k, n, m, sum;
  while (scanf("%lld%lld%lld", &n, &k, &m) != EOF) {
    sum = 0;
    for (i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      sum += a[i];
    }
    double ans = 0.0;
    sort(a + 1, a + 1 + n);
    for (i = 1; i <= min(n, m + 1); i++) {
      ans =
          max(ans, double(sum + min(m - i + 1, (n - i + 1) * k)) / (n - i + 1));
      sum -= a[i];
    }
    printf("%.8lf\n", ans);
  }
}
