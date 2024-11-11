#include <bits/stdc++.h>
using namespace std;
long long n, k;
int m;
long long a[400005], b[400005];
long long L0, R0;
void init() {
  L0 = R0 = -1;
  long long l = 1, r = n;
  while (l <= r) {
    long long mid = l + r >> 1, s = 0;
    for (int i = 0; i <= m; ++i) s += (((b[i]) + (mid)-1) / (mid)) - 1;
    if (s <= k)
      r = (R0 = mid) - 1;
    else
      l = mid + 1;
  }
  l = 1, r = n;
  while (l <= r) {
    long long mid = l + r >> 1, s = 0;
    bool bz = 1;
    for (int i = 0; i <= m && bz; ++i) {
      if (b[i] / mid == 0) bz = 0;
      s += b[i] / mid - 1;
    }
    if (bz && s >= k)
      l = (L0 = mid) + 1;
    else
      r = mid - 1;
  }
}
pair<long long, long long> p[400005];
multiset<long long> s;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%d%lld", &n, &m, &k);
    for (int i = 1; i <= m; ++i) scanf("%lld", &a[i]);
    a[m + 1] = n;
    for (int i = 0; i <= m; ++i) b[i] = a[i + 1] - a[i];
    init();
    long long ans;
    if (L0 <= R0) {
      bool bz = 1;
      for (int i = 0; i <= m; ++i) bz &= ((b[i] + R0 - 1) / R0 <= b[i] / L0);
      if (bz)
        ans = R0 - L0;
      else {
        s.clear();
        s.insert(L0), s.insert(R0);
        int k = 0;
        for (int i = 0; i <= m; ++i)
          if ((((b[i]) + (R0)-1) / (R0)) > b[i] / L0) {
            p[++k] = {b[i] / (((b[i]) + (R0)-1) / (R0)),
                      (((b[i]) + (b[i] / L0) - 1) / (b[i] / L0))};
            s.insert(p[k].first);
          }
        sort(p + 1, p + k + 1);
        ans = *s.rbegin() - *s.begin();
        for (int i = 1; i <= k; ++i) {
          s.erase(s.find(p[i].first));
          s.insert(p[i].second);
          ans = min(ans, *s.rbegin() - *s.begin());
        }
      }
    } else
      ans = 0;
    printf("%lld\n", ans);
  }
  return 0;
}
