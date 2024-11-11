#include <bits/stdc++.h>
using namespace std;
const long long MAX = 10000000000000000LL;
const long long MOD = 1e9 + 7;
const long double EPS = 1e-5;
const long double PI = 3.14159265358979323846;
int n, m;
bool solve(long long mid) {
  if (mid <= 2) return (n >= mid);
  if (mid % 2LL != 0)
    return (n >= (mid * (mid - 1LL)) / 2LL + 1LL);
  else
    return (n > (mid * (mid - 1LL)) / 2LL + (mid / 2LL - 1LL));
}
int main() {
  cin >> n >> m;
  vector<long long> q(m), w(m);
  for (long long i = 0; i < m; ++i) cin >> q[i] >> w[i];
  sort(w.rbegin(), w.rend());
  long long l = 0, r = m + 1;
  long long a = 0;
  while (l < r) {
    long long mid = (l + r) / 2LL;
    if (solve(mid)) {
      l = mid + 1;
      a = mid;
    } else {
      r = mid;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < a; ++i) {
    ans += w[i];
  }
  cout << ans << endl;
  return 0;
}
