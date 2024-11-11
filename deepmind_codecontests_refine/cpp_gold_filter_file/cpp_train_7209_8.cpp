#include <bits/stdc++.h>
using namespace std;
long long t, n, m, s[111111];
pair<long long, long long> a[111111];
bool cmp(const pair<long long, long long> &a,
         const pair<long long, long long> &b) {
  return a.first < b.first;
}
signed main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= m; i++)
      scanf("%lld%lld", &a[i].first, &a[i].second);
    sort(a + 1, a + 1 + m);
    for (long long i = 1; i <= m; i++) s[i] = s[i - 1] + a[i].first;
    long long ans;
    if (m - n >= 0)
      ans = s[m] - s[m - n];
    else
      ans = s[m];
    for (long long i = 1; i <= m; i++) {
      long long itr =
          lower_bound(a + 1, a + 1 + m, make_pair(a[i].second, 0), cmp) - a;
      if (m - itr + 1 > n) continue;
      long long now = s[m] - s[itr - 1];
      if (itr > i) now += a[i].first, itr--;
      now += (n - (m - (itr - 1))) * a[i].second;
      ans = max(ans, now);
    }
    printf("%lld\n", ans);
  }
  long long aaa;
  cin >> aaa;
  return 0;
}
