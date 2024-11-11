#include <bits/stdc++.h>
using namespace std;
double n, k, x, tot, a[200001], d[200001];
int main() {
  scanf("%lf%lf", &n, &k);
  for (long long i = 1; i <= n; ++i) scanf("%ld", &a[i]);
  for (long long i = 2; i <= n; ++i) {
    if (d[i - 1] - a[i] * (n - i) * (i - 1 - x) < k) {
      ++x, printf("%lld\n", i), d[i] = d[i - 1];
    } else {
      d[i] = d[i - 1] + a[i] * (i - 1 - x);
    }
  }
  return 0;
}
