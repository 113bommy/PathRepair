#include <bits/stdc++.h>
using namespace std;
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j;
  long long n;
  cin >> n;
  vector<pair<long long, long long> > arr(n);
  for (i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
  long long ans = 0;
  long long remove1 = 0;
  long long remove2 = 0;
  for (i = 0; i < n; i++) {
    if (arr[remove1].first < arr[i].first) remove1 = i;
    if (arr[remove2].second > arr[i].second) remove2 = i;
  }
  pair<long long, long long> intersection = {LONG_LONG_MIN, LONG_LONG_MAX};
  for (long long x = 0; x < n; x++) {
    if (x == remove1) continue;
    pair<long long, long long> i = arr[x];
    intersection.first = max(intersection.first, i.first);
    intersection.second = min(intersection.second, i.second);
  }
  long long res = ((intersection.second - intersection.first) > 0)
                      ? intersection.second - intersection.first
                      : 0;
  ans = max(ans, res);
  intersection = {LONG_LONG_MIN, LONG_LONG_MAX};
  for (long long x = 0; x < n; x++) {
    if (x == remove2) continue;
    pair<long long, long long> i = arr[x];
    intersection.first = max(intersection.first, i.first);
    intersection.second = min(intersection.second, i.second);
  }
  res = ((intersection.second - intersection.first) > 0)
            ? intersection.second - intersection.first
            : 0;
  ans = max(ans, res);
  cout << ans << "\n";
  return 0;
}
