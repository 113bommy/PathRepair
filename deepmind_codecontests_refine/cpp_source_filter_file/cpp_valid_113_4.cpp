#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
int main() {
  long long T, n, sum = 0, x, y, p;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  cin >> T;
  sort(a, a + n);
  while (T--) {
    scanf("%lld%lld", &x, &y);
    long long p;
    p = lower_bound(a, a + n, x) - a;
    if (p == n) {
      printf("%lld\n", max((long long)0, x - a[n - 1]) +
                           max((long long)0, y - sum + a[n - 1]));
    } else if (p == 0) {
      printf("%lld\n",
             max((long long)0, x - a[0]) + max((long long)0, y - sum + a[0]));
    } else {
      printf("%lld\n", min(min((long long)0, x - a[p]) +
                               max((long long)0, y - sum + a[p]),
                           max((long long)0, x - a[p - 1]) +
                               max((long long)0, y - sum + a[p - 1])));
    }
  }
  return 0;
}
