#include <bits/stdc++.h>
using namespace std;
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << '=' << h << '\n';
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
const long long N = 2e5 + 7;
long long n, a[N], pre[N];
long double sum(long long l, long long r) {
  return pre[r] - (l > 0 ? pre[l - 1] : 0);
}
long double f(long long len, long long idx) {
  long double mean =
      (sum(idx - len, idx) + sum(n - len, n - 1)) / (2 * len + 1);
  long double ret = mean - a[idx];
  return ret;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (long long i = 0; i < n; i++) pre[i] = a[i] + (i > 0 ? pre[i - 1] : 0);
  long long len = -1, idx = -1;
  long double ans = -1e9;
  for (long long i = 0; i < n; i++) {
    long long cnt = min(i, n - 1 - i);
    long long lo = 0, hi = cnt;
    while (hi - lo > 3) {
      long long m1 = (2 * lo + hi) / 3, m2 = (lo + 2 * hi) / 3;
      if (f(m1, i) < f(m2, i))
        lo = m1;
      else
        hi = m1;
    }
    long long cc = 0;
    long double curans = 0;
    for (long long k = lo; k <= hi; k++)
      if (f(k, i) > curans) curans = f(k, i), cc = k;
    if (curans > ans) {
      ans = curans;
      idx = i;
      len = cc;
    }
  }
  cout << 2 * len + 1 << '\n';
  for (long long i = idx - len; i <= idx; i++) cout << a[i] << " ";
  for (long long i = n - len; i <= n - 1; i++) cout << a[i] << " ";
  return 0;
}
