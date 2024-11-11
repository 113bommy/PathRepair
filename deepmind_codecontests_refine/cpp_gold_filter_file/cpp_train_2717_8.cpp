#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main() {
  int n;
  int t1 = 0, t2 = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] > 0)
      t1++;
    else
      t2++;
  }
  long long ans = 0;
  if (t1 + t2 == 1)
    printf("%lld\n", a[0]);
  else {
    if (t1 && t2) {
      for (int i = 0; i < n; i++) {
        if (a[i] >= 0)
          ans += a[i];
        else
          ans -= a[i];
      }
    } else if (t1 && !t2) {
      long long minx = 1000000005;
      for (int i = 0; i < n; i++) {
        minx = min(minx, a[i]);
        ans += a[i];
      }
      ans = ans - 2 * minx;
    } else {
      long long maxn = -1000000005;
      for (int i = 0; i < n; i++) {
        maxn = max(maxn, a[i]);
        ans -= a[i];
      }
      ans = ans + 2 * maxn;
    }
    printf("%lld\n", ans);
  }
}
