#include <bits/stdc++.h>
using namespace std;
int n;
long long k, sum, maxn, a[150], ans;
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
    maxn = max(maxn, a[i]);
    a[i]--;
  }
  k = k + sum;
  long long l, r;
  for (l = 1; l <= maxn;) {
    r = maxn * n;
    for (int i = 1; i <= n; ++i)
      if (a[i] >= l) r = min(r, a[i] / (a[i] / l));
    long long tot = n;
    for (int i = 1; i <= n; ++i) tot += a[i] / l;
    tot = k / tot;
    if (tot >= l && tot <= r) ans = max(ans, tot);
    l = r + 1;
  }
  printf("%lld\n", ans);
}
