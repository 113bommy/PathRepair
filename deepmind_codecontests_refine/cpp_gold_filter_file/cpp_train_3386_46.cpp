#include <bits/stdc++.h>
using namespace std;
const long long inf = 1LL << 60;
const long long md = 1e9 + 7;
const long double eps = 1e-14;
const long double pi = acos(-1);
long long f(long long a, int bb, vector<long long> &sum, vector<long long> &as,
            vector<long long> &hull) {
  long long b = hull[bb];
  return sum[a] - sum[b] + (b - a) * as[a];
}
int main() {
  int n;
  scanf("%d", &n);
  vector<long long> as(n);
  for (int i = (0); i < int(n); ++i) scanf("%lld", &as[i]);
  vector<long long> sm(n + 1);
  sm[0] = 0;
  for (int i = (0); i < int(n); ++i) sm[i + 1] = sm[i] + as[i];
  vector<long long> hull;
  for (int i = (0); i < int(n + 1); ++i) {
    while (hull.size() >= 2) {
      long long sz = hull.size();
      long long k = hull[sz - 2], j = hull[sz - 1];
      if ((sm[j] - sm[k]) * (i - j) >= (sm[i] - sm[j]) * (j - k)) {
        hull.pop_back();
      } else {
        break;
      }
    }
    hull.push_back(i);
  }
  long long ans = 0;
  long long def = 0;
  for (int i = (0); i < int(n); ++i) def += (i + 1) * as[i];
  for (int i = (0); i < int(n); ++i) {
    int a = -1, b = hull.size() - 1;
    while (a + 1 < b) {
      int m = (a + b) / 2;
      if (f(i, m, sm, as, hull) < f(i, m + 1, sm, as, hull))
        a = m;
      else
        b = m;
    }
    ans = max(ans, f(i, a + 1, sm, as, hull));
  }
  printf("%lld\n", ans + def);
}
