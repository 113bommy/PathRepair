#include <bits/stdc++.h>
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
using namespace std;
pair<int, int> p[N];
multiset<int> s;
int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &p[i].first, &p[i].second);
  sort(p + 1, p + 1 + n);
  long long ans = (x + 1LL * y * (p[1].second - p[1].first)) % mod;
  s.insert(p[1].second);
  for (int i = 2; i <= n; ++i) {
    long long w = (x + y * 1LL * (p[i].second - p[i].first));
    auto e = s.lower_bound(p[i].first);
    if (e == s.begin()) {
      ans = (ans + w) % mod;
      s.insert(p[i].second);
    } else {
      e--;
      long long ww = 1LL * y * (p[i].second - *e);
      if (w <= ww) {
        ans = (ans + w) % mod;
        s.insert(p[i].second);
      } else {
        ans = (ans + ww) % mod;
        s.erase(e);
        s.insert(p[i].second);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
