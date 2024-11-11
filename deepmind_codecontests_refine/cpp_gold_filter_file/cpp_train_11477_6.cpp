#include <bits/stdc++.h>
using namespace std;
long long num[500005];
long long check1(int n, long long d) {
  long long s = 0;
  for (int i = 1; i <= n; i++) s += num[i] / d - 1;
  return s;
}
long long check2(int n, long long d) {
  long long s = 0;
  for (int i = 1; i <= n; i++) s += (num[i] + d - 1) / d - 1;
  return s;
}
pair<long long, long long> a[500005];
int main() {
  int cases;
  scanf("%d", &cases);
  for (; cases; cases--) {
    long long m, k;
    int n;
    scanf("%lld%d%lld", &m, &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &num[i]);
    num[++n] = m;
    long long minn = 0x3f3f3f3f3f3f3f3fLL, maxn = 0;
    for (int i = n; i > 0; i--) {
      num[i] -= num[i - 1];
      minn = min(minn, num[i]);
      maxn = max(maxn, num[i]);
    }
    long long l = 1, r = minn;
    while (l < r) {
      long long mid = ((l + r) >> 1) + 1;
      if (check1(n, mid) >= k)
        l = mid;
      else
        r = mid - 1;
    }
    long long nl = l;
    l = 1;
    r = maxn;
    while (l < r) {
      long long mid = ((l + r) >> 1);
      if (check2(n, mid) <= k)
        r = mid;
      else
        l = mid + 1;
    }
    long long nr = l;
    if (nl >= nr) {
      puts("0");
      continue;
    }
    int sz = 0;
    for (int i = 1; i <= n; i++)
      if (num[i] / nl < (num[i] + nr - 1) / nr) {
        long long t1 = num[i] / nl, t2 = (num[i] + nr - 1) / nr;
        a[++sz] = pair<long long, long long>((num[i] + t1 + 1) / (t1 + 1),
                                             (num[i] - 1) / (t2 - 1));
      }
    a[++sz] = pair<long long, long long>(1, nr - 1);
    sort(a + 1, a + sz + 1);
    a[sz + 1] = pair<long long, long long>(nl + 1, 0);
    long long ans = 0x3f3f3f3f3f3f3f3fLL;
    maxn = 0;
    for (int i = 1; i <= sz; i++) {
      maxn = max(maxn, a[i].second);
      if (a[i].first < a[i + 1].first)
        ans = min(ans, (maxn + 1) - (a[i + 1].first - 1));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
