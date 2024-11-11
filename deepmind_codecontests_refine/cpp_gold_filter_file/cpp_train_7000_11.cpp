#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long power(long long a, long long n) {
  a %= 998244353;
  if (n == 1) return a;
  if (n == 0) return 1;
  if (n % 2)
    return (a * (power((a * a) % 998244353, n / 2) % 998244353)) % 998244353;
  return power((a * a) % 998244353, n / 2) % 998244353;
}
const long long inf = (long long)1e18;
long long inverse(long long x) { return power(x, 998244353 - 2) % 998244353; }
void solve() {
  long long n, x, ts = 0;
  cin >> n;
  vector<long long> v(n + 5);
  for (long long i = 1; i < (n + 1) / 2 + 1; ++i) cin >> v[i], ts += v[i];
  cin >> x;
  for (long long i = (n + 1) / 2 + 1; i < n + 1; ++i) v[i] = x, ts += x;
  if (x > 0 || ts > 0) {
    if (ts > 0)
      cout << n << "\n";
    else
      cout << "-1\n";
    return;
  }
  vector<long long> ps(n + 5), minl(n + 5), pmin(n + 5);
  for (long long i = 1; i < n + 1; ++i) ps[i] = ps[i - 1] + v[i];
  for (long long i = (n + 1) / 2; i > 0; --i) {
    long long lo = n / 2, hi = n - i + 1;
    while (lo < hi) {
      long long mid = (lo + hi + 1) / 2;
      if (ps[i + mid - 1] - ps[i - 1] > 0)
        lo = mid;
      else
        hi = mid - 1;
    }
    minl[i] = lo;
  }
  pmin[1] = minl[1];
  for (long long i = 2; i < (n + 1) / 2 + 1; ++i) {
    pmin[i] = min(pmin[i - 1], minl[i]);
  }
  for (long long k = n / 2 + 1; k < n + 1; ++k) {
    if (pmin[n - k + 1] >= k) {
      cout << k << "\n";
      return;
    }
  }
  cout << "-1\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long T = 1;
  for (long long t = 1; t < T + 1; ++t) {
    solve();
  }
  return 0;
}
