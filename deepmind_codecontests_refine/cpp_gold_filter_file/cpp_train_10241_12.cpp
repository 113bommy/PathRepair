#include <bits/stdc++.h>
const long double PI = acos(-1);
const long double eps = 1e-10;
const long long INF = 0x3fffffffffffffff;
std::pair<long long, long long> p[500005];
long long n;
long double ans = INF;
bool check(long long l, long long r, long double t) {
  long double L = +INF, R = -INF;
  for (long long i = l; i <= r; ++i)
    if (p[i].second < 0)
      L = std::min(L, p[i].first + p[i].second * t);
    else
      R = std::max(R, p[i].first + p[i].second * t);
  return L <= R;
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  for (long long i = 1; i <= n; ++i) std::cin >> p[i].first >> p[i].second;
  for (long long i = 1; i <= n; ++i) {
    long long j = i;
    while (p[j].second > 0) ++j;
    while (p[j].second < 0) ++j;
    --j;
    long double l = 0, r = p[j].first - p[i].first;
    while (l + eps < r) {
      long double mid = (l + r) / 2;
      if (check(i, j, mid))
        r = mid;
      else
        l = mid;
    }
    if (check(i, j, r)) ans = std::min(ans, r);
    i = j;
  }
  std::cout << std::fixed << std::setprecision(10) << (ans >= INF ? -1 : ans)
            << std::endl;
  return 0;
}
