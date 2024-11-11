#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
const long long INF = 1e18 + 10;
long long n, t, a[N], x[N];
long long l[N], r[N];
int main() {
  scanf("%lld%lld", &n, &t);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    l[i] = a[i] + t;
    r[i] = INF;
  }
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &x[i]);
    if (x[i] < x[i - 1] || x[i] < i) {
      printf("No");
      return 0;
    }
  }
  for (long long i = 1; i <= n; i++)
    if (x[i] > i) {
      l[i] = max(l[i], a[i + 1] + t);
      if (x[i] < n) r[x[i]] = min(r[x[i]], a[x[i] + 1] + t - 1);
    }
  for (long long i = 2; i <= n; i++) {
    l[i] = max(l[i], l[i - 1] + 1);
    if (l[i] > r[i]) {
      printf("No");
      return 0;
    }
  }
  printf("Yes\n");
  for (long long i = 1; i <= n; i++) printf("%lld ", l[i]);
  return 0;
}
