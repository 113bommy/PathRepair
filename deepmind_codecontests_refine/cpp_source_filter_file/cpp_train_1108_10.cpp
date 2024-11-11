#include <bits/stdc++.h>
using namespace std;
long long n, r, k;
vector<long long int> a(500005), s(500005);
long long check(long long x) {
  vector<pair<long long int, long long int> > b;
  long long sum = 0, cur = 0, m = k;
  for (long long int i = 1; i < n + 1; i++) {
    while (cur < (long long int)b.size() && b[cur].first < i - r)
      sum -= b[cur].second, cur++;
    long long c = s[min(i + r, n)] - s[max(i - r - 1, 0LL)] + sum;
    if (c >= x) continue;
    b.push_back({min(i + r, n), x - c});
    sum += x - c;
    m -= x - c;
    if (m < 0) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    cin >> n >> r >> k;
    for (long long int i = 1; i < n + 1; i++) cin >> a[i];
    for (long long int i = 1; i < n + 1; i++) s[i] = s[i - 1] + a[i];
    long long lo = 0, hi = 1e18, mid = (lo + hi) / 2;
    while (hi - lo > 1) {
      if (check(mid))
        lo = mid;
      else
        hi = mid;
      mid = (lo + hi) / 2;
    }
    if (check(mid + 1))
      cout << mid + 1;
    else
      cout << mid;
  }
  return 0;
}
