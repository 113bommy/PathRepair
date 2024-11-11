#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e12;
long long n, m, k, q;
long long lmax[200008], rmax[200008];
long long a[200008];
long long dp[200008][2];
long long ans = 0;
long long MAXN = 0;
bool empty[200008];
long long calc(long long now, long long l, long long r) {
  if (now <= l) return r - now;
  if (now >= r) return now - l;
  return min((r - now) * 2 + r - l, r - l + (now - l) * 2);
}
void zy(long long x, long long type, long long i, long long dis, long long last,
        long long lasti) {
  if (x == 0) return;
  if (lmax[i] > rmax[i]) {
    cout << "WA" << endl;
    exit(0);
  }
  if (x >= rmax[i])
    dp[i][0] = min(dp[i][0], dp[lasti][type] + dis + last + x - lmax[i]),
    dp[i][1] = min(dp[i][1], dp[lasti][type] + dis + last + x - lmax[i] +
                                 rmax[i] - lmax[i]);
  else if (x <= lmax[i])
    dp[i][1] = min(dp[i][1], dp[lasti][type] + dis + last + rmax[i] - x),
    dp[i][0] = min(dp[i][0], dp[lasti][type] + dis + last + rmax[i] - x +
                                 rmax[i] - lmax[i]);
  else {
    dp[i][0] = min(dp[i][0], dp[lasti][type] + dis + last + (rmax[i] - x) +
                                 rmax[i] - lmax[i]);
    dp[i][1] = min(dp[i][1], dp[lasti][type] + dis + last + (x - lmax[i]) +
                                 rmax[i] - lmax[i]);
  }
}
signed main() {
  memset(lmax, 0x3f, sizeof(lmax));
  scanf("%lld%lld%lld%lld", &n, &m, &k, &q);
  for (long long i = 1; i <= k; i++) {
    long long r, c;
    scanf("%lld%lld", &r, &c);
    lmax[r] = min(lmax[r], c);
    rmax[r] = max(rmax[r], c);
    MAXN = max(MAXN, r);
  }
  for (long long i = 1; i <= k; i++)
    if (lmax[i] > rmax[i]) empty[i] = 1;
  long long MIN = 1e18;
  for (long long i = 1; i <= q; i++) scanf("%lld", &a[i]), MIN = min(MIN, a[i]);
  sort(a + 1, a + 1 + q);
  long long i = 1;
  long long last = 0;
  while (empty[i]) last++, i++;
  if (i != 1) {
    if (MIN <= lmax[i])
      dp[i][1] = rmax[i] - 1, dp[i][0] = rmax[i] - 1 + rmax[i] - lmax[i];
    else if (MIN >= rmax[i])
      dp[i][0] = MIN - lmax[i] + MIN - 1,
      dp[i][1] = MIN - lmax[i] + MIN - 1 + rmax[i] - lmax[i];
    else {
      dp[i][0] = MIN - 1 + (rmax[i] - MIN) + rmax[i] - lmax[i];
      dp[i][1] = MIN - 1 + (MIN - lmax[i]) + rmax[i] - lmax[i];
    }
  } else {
    dp[i][1] = rmax[i] - 1;
    dp[i][0] = rmax[i] - 1 + rmax[i] - lmax[i];
  }
  long long lasti = i;
  if (MAXN == i) {
    printf("%lld\n", min(dp[i][1] + last, dp[i][0] + last));
    return 0;
  }
  i++;
  last++;
  for (; i <= MAXN; i++) {
    while (empty[i]) last++, i++;
    dp[i][0] = dp[i][1] = inf;
    long long l = lmax[lasti], r = rmax[lasti];
    long long now1 = lower_bound(a + 1, a + 1 + q, l) - a;
    long long now2 = lower_bound(a + 1, a + 1 + q, r) - a;
    zy(a[now1 - 1], 0, i, l - a[now1 - 1], last, lasti);
    zy(a[now1], 0, i, a[now1] - l, last, lasti);
    zy(a[now2 - 1], 1, i, r - a[now2 - 1], last, lasti);
    zy(a[now2], 1, i, a[now2] - r, last, lasti);
    last = 1;
    lasti = i;
  }
  printf("%lld\n", min(dp[MAXN][0], dp[MAXN][1]));
  return 0;
}
