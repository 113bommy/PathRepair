#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> a[200005];
long long n, x[200005], y[200005], f[200005][3], cnt, l[200005], r[200005];
bool cmp(pair<long long, long long> xx, pair<long long, long long> yy) {
  if (xx.first == yy.first) {
    long long a = xx.second, b = yy.second;
    if (x[a] == x[b]) return (y[a] < y[b]);
    return (x[a] < x[b]);
  }
  return (xx.first < yy.first);
}
long long lui(long long i, long long p) {
  if (f[i][p] != -1) return f[i][p];
  if (i > cnt) return 0;
  long long id, ii, xx, yy;
  if (p == 1)
    id = a[r[i - 1]].second;
  else
    id = a[l[i - 1]].second;
  xx = x[id];
  yy = y[id];
  long long ans = 0, kq = 1e15;
  for (long long j = (l[i]); j <= (r[i]); ++j) {
    ii = a[j].second;
    ans += abs(xx - x[ii]) + abs(yy - y[ii]);
    xx = x[ii];
    yy = y[ii];
  }
  kq = min(kq, lui(i + 1, 1) + ans);
  ans = 0;
  xx = x[id];
  yy = y[id];
  for (long long j = (r[i]); j >= (l[i]); --j) {
    ii = a[j].second;
    ans += abs(xx - x[ii]) + abs(yy - y[ii]);
    xx = x[ii];
    yy = y[ii];
  }
  kq = min(kq, lui(i + 1, 0) + ans);
  return f[i][p] = kq;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = (1); i <= (n); ++i) {
    cin >> x[i] >> y[i];
    a[i] = pair<long long, long long>(max(x[i], y[i]), i);
  }
  sort(a + 1, a + n + 1, cmp);
  a[0].first = 0;
  a[n + 1].first = 0;
  for (long long i = (1); i <= (n + 1); ++i)
    if (a[i].first != a[i - 1].first) {
      cnt++;
      l[cnt] = i;
      r[cnt - 1] = i - 1;
    }
  cnt--;
  memset(f, -1, sizeof(f));
  long long xx, yy, ans = 0, kq = 1e15;
  xx = 0;
  yy = 0;
  for (long long j = (l[1]); j <= (r[1]); ++j) {
    long long id = a[j].second;
    ans += abs(xx - x[id]) + abs(yy - y[id]);
    xx = x[id];
    yy = y[id];
  }
  kq = min(kq, ans + lui(2, 1));
  xx = 0;
  yy = 0;
  ans = 0;
  for (long long j = (r[1]); j >= (l[1]); --j) {
    long long id = a[j].second;
    ans += abs(xx - x[id]) + abs(yy - y[id]);
    xx = x[id];
    yy = y[id];
  }
  kq = min(kq, ans + lui(2, 0));
  cout << kq;
  return 0;
}
