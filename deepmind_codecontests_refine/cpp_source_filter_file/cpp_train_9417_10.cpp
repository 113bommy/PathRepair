#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n, ans = 0, a[N];
vector<long long> v;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (long long i = 1; i <= n; ++i)
    if (a[i] > a[i - 1]) v.push_back(a[i]);
  long long M = v.back();
  for (long long i = 0; i < v.size(); ++i) {
    for (long long x = 2 * v[i]; x <= M + v[i]; x += v[i]) {
      long long j = lower_bound(v.begin(), v.end(), x) - v.begin() - 1;
      ans = max(ans, v[j] + v[i] - x);
    }
  }
  cout << ans;
}
