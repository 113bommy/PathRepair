#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
int main() {
  long long n, ch = 0, nch = 0, ans = -1e18, sum = 0;
  cin >> n;
  vector<long long> v(n);
  for (auto& x : v) cin >> x;
  sum = accumulate(v.begin(), v.end(), 0ll);
  for (int i = 0; i < n; i += 2) ch += v[i];
  for (int i = 1; i < n; i += 2) nch += v[i];
  sort(v.begin(), v.end());
  if (n % 3 == 1) ans = sum;
  for (int i = 0; i < n; ++i) {
    sum -= 2 * v[i];
    if ((n + i) % 3 == 0) {
      if (sum == ch - nch || sum == nch - ch)
        ans = max(ans, sum + 2 * (v[i] - v[i + 1]));
      else
        ans = max(ans, sum);
    }
  }
  cout << ans;
}
