#include <bits/stdc++.h>
using namespace std;
long long a[1005];
int main() {
  long long n, d, i;
  long long ans;
  scanf("%lld %lld", &n, &d);
  for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + 1 + n);
  a[0] = a[1] - 3 * d - 1;
  a[n + 1] = a[n] + 3 * d;
  ans = 0;
  for (i = 1; i <= n; i++) {
    if (a[i] - d != a[i - 1] + d) {
      if (a[i] - 2 * d >= a[i - 1]) ans++;
    }
    if (a[i] + d <= a[i + 1] - d) {
      ans++;
    }
  }
  printf("%lld\n", ans);
}
