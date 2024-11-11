#include <bits/stdc++.h>
using namespace std;
bool check(long long mid, vector<pair<long long, long long> > v, long long n) {
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    if (mid + sum >= v[i].first) {
      sum += v[i].second;
    } else {
      return 0;
    }
  }
  return 1;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, ki, ai;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<long long, long long> > v(n);
    for (long long i = 0; i < n; i++) {
      cin >> ki;
      v[i].second = ki;
      v[i].first = 0;
      for (long long j = 0; j < ki; j++) {
        cin >> ai;
        v[i].first = max(ai + 1 - j, v[i].first);
      }
    }
    sort(v.begin(), v.end());
    long long ans = INT64_MAX;
    long long prev = ans;
    long long lo = 0;
    long long hi = v[n - 1].first;
    long long mid;
    while (lo <= hi) {
      mid = (lo + hi) / 2;
      if (check(mid, v, n)) {
        prev = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
      ans = min(ans, prev);
    }
    cout << ans << '\n';
  }
}
