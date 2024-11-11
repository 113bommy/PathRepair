#include <bits/stdc++.h>
using namespace std;
long long a[1005];
int main() {
  long long n, k, s = 0;
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    s += a[i];
  }
  if (k > s) {
    printf("-1\n");
    return 0;
  }
  if (n == 1) {
    printf("%lld\n", a[0] - k);
    return 0;
  }
  sort(a, a + n);
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    ans += a[i] - a[0];
  }
  if (ans < k) {
    ans = (k - ans) / n + ((k - ans) % n == 0 ? 0 : 1);
    printf("%lld\n", a[0] - ans);
    return 0;
  } else {
    printf("%lld\n", a[0]);
    return 0;
  }
  return 0;
}
