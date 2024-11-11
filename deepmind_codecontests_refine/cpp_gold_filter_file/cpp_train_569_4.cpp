#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
const long long INF = 1e9;
long long n, ans[maxn], fen[maxn], dp[maxn], a[maxn];
vector<pair<pair<long long, long long>, long long> > poi;
long long ask(long long l, long long r) {
  if (r < l) return 0;
  if (l > n - 1 || l < 0 || r < 0 || r > n - 1) return 0;
  r++;
  l++;
  long long anss = 0;
  while (r >= l) {
    if ((r - (r & -r) + 1) >= l) {
      anss = max(anss, fen[r]);
      r -= (r & -r);
      continue;
    }
    anss = max(anss, a[r]);
    r--;
  }
  return anss;
}
void asg(long long idx, long long va) {
  for (++idx; idx <= n; idx += (idx & -idx)) fen[idx] = max(va, fen[idx]);
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x, h;
    cin >> x >> h;
    poi.push_back({{x, h}, i});
  }
  sort(poi.begin(), poi.end());
  for (long long i = n - 1; i >= 0; i--) {
    long long x = poi[i].first.first, h = poi[i].first.second,
              ii = poi[i].second;
    long long ind1 = lower_bound(poi.begin(), poi.end(),
                                 make_pair(make_pair(x + 1, -INF), -INF)) -
                     poi.begin();
    long long ind2 = lower_bound(poi.begin(), poi.end(),
                                 make_pair(make_pair(x + h, -INF), -INF)) -
                     poi.begin();
    ind2--;
    dp[ii] = max(i, ask(ind1, ind2));
    ans[ii] = dp[ii] - i + 1;
    a[i + 1] = dp[ii];
    asg(i, dp[ii]);
  }
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
