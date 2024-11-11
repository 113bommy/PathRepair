#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, d;
  cin >> n >> d;
  std::vector<pair<long long, long long>> a(n);
  long long ans = 0;
  std::vector<long long> p(n, 0);
  for (long long i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  p[0] = a[0].second;
  for (long long i = 1; i < n; i++) p[i] += a[i].second + p[i - 1];
  for (long long i = 0; i < n; i++) {
    long long l = i, r = n, f = 0;
    while (r - l) {
      if (r - l <= 1) f = 1;
      long long m = ((unsigned long long)r + (unsigned long long)l) >> 1;
      if (a[m].first - a[i].first < d)
        l = m;
      else
        r = m;
      if (f) break;
    }
    ans = max(ans, p[l] - p[i] + a[i].second);
  }
  std::cout << ans << std::endl;
  return 0;
}
