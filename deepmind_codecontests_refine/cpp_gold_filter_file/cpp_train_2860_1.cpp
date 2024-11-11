#include <bits/stdc++.h>
using namespace std;
long long n, m, k, p, h[100007], a[100007], cnt[100007], l = 0, r = 1e18;
priority_queue<pair<long long, long long> > q;
long long read() {
  long long num = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') num = num * 10 + c - '0', c = getchar();
  return num;
}
long long check(long long mid) {
  while (!q.empty()) q.pop();
  memset(cnt, 0, sizeof cnt);
  for (long long i = 1; i <= n; i++)
    if (h[i] + m * a[i] > mid) q.push(make_pair(-(mid / a[i]), i));
  long long tot = 0;
  for (long long i = 1; i <= m && !q.empty(); i++)
    for (long long j = 1; j <= k && !q.empty(); j++) {
      if (-q.top().first < i) return 0;
      long long x = q.top().second;
      q.pop();
      cnt[x]++;
      long long v = (mid + p * cnt[x]) / a[x];
      if (v < m) q.push(make_pair(-v, x));
      tot++;
    }
  for (long long i = 1; i <= n; i++)
    if (h[i] > mid + cnt[i] * p - m * a[i]) {
      long long add = (h[i] - (mid + cnt[i] * p - m * a[i]) - 1) / p + 1;
      if (tot + add > m * k) return 0;
      tot += add;
    }
  return 1;
}
signed main() {
  n = read();
  m = read();
  k = read();
  p = read();
  for (long long i = 1; i <= n; i++) {
    h[i] = read();
    a[i] = read();
  }
  while (l < r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
  return 0;
}
