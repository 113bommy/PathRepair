#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = (int)1e9 + 7;
const int logN = 17;
const int inf = 1e9;
const int N = 2e5 + 5;
long long n, A, cf, cm, m, p[N];
pair<long long, long long> a[N], b[N];
long long get(long long m) { return upper_bound(p + 1, p + n + 1, m) - p - 1; }
int main() {
  scanf("%lld %lld %lld %lld %lld", &n, &A, &cf, &cm, &m);
  long long all = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i].first);
    a[i].second = i;
    all += A - a[i].second;
  }
  if (all <= m) {
    cout << n * cf + cm * A << '\n';
    for (int i = 1; i <= n; i++) printf("%lld ", A);
    cout << '\n';
    return 0;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    p[i] = p[i - 1] + (a[i].first - a[i - 1].first) * (i - 1);
  long long ans = -1, wm = m;
  for (int i = n; i >= 0; i--) {
    if (m < 0) break;
    long long t = min(get(m), (long long)i);
    long long ccc = (t) ? ((m - p[t]) / (t)) : 0;
    ccc += a[t].first;
    ccc = min(ccc, A);
    long long cans = ccc * cm + (n - i) * cf;
    if (cans >= ans) ans = cans;
    m -= A - a[i].first;
  }
  m = wm;
  cout << ans << '\n';
  for (int i = n; i >= 0; i--) {
    if (m < 0) break;
    long long t = min(get(m), (long long)i);
    long long ccc = (t) ? ((m - p[t]) / (t)) : 0;
    ccc += a[t].first;
    ccc = min(ccc, A);
    long long cans = ccc * cm + (n - i) * cf;
    if (cans == ans) {
      for (int j = 1; j <= n; j++) {
        if (j > i)
          b[j] = make_pair(a[j].second, A);
        else if (j <= t)
          b[j] = make_pair(a[j].second, ccc);
        else
          b[j] = make_pair(a[j].second, a[j].first);
      }
      sort(b + 1, b + n + 1);
      for (int i = 1; i <= n; i++) printf("%lld ", b[i].second);
      cout << '\n';
      return 0;
    }
    m -= A - a[i].first;
  }
  return 0;
}
