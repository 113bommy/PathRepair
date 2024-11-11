#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 100;
long long n, m;
pair<long long, long long> ter[N];
pair<pair<long long, long long>, long long> cyc[N];
long long ans[N];
bool inrange(long long d, pair<long long, long long> a,
             pair<long long, long long> b) {
  double dbl;
  dbl = (a.first - b.first) * (a.first - b.first);
  dbl += (0 - b.second) * (0 - b.second);
  return ((d * d) >= dbl);
}
long long bin(long long x) {
  long long l = 0, r = n + 1, md;
  while (r - l > 1) {
    md = (l + r) / 2;
    if (cyc[md].first.first <= x)
      l = md;
    else
      r = md;
  }
  return l;
}
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    ans[i] = 1e6;
    cin >> cyc[i].first.first >> cyc[i].first.second;
    cyc[i].second = i;
  }
  cin >> m;
  for (long long i = 1; i <= m; i++) cin >> ter[i].first >> ter[i].second;
  sort(cyc + 1, cyc + 1 + n);
  for (long long i = 1; i <= m; i++) {
    long long tmp = bin(ter[i].first);
    if (inrange(cyc[tmp].first.second, {cyc[tmp].first.first, 0}, ter[i])) {
      ans[cyc[tmp].second] = min(ans[cyc[tmp].second], i);
    }
    if (inrange(cyc[tmp + 1].first.second, {cyc[tmp + 1].first.first, 0},
                ter[i])) {
      ans[cyc[tmp + 1].second] = min(ans[cyc[tmp + 1].second], i);
    }
  }
  long long tmp = 0;
  for (long long i = 1; i <= n; i++) {
    if (ans[i] != 1e6) tmp++;
  }
  cout << tmp << endl;
  for (long long i = 1; i <= n; i++) {
    if (ans[i] == 1e6)
      cout << -1 << " ";
    else
      cout << ans[i] << " ";
  }
  return 0;
}
