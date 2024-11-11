#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  vector<long long> p(n);
  p[0] = v[0];
  for (long long i = 1; i < n; ++i) {
    p[i] = v[i] + p[i - 1];
  }
  long long m;
  cin >> m;
  for (long long i = 0; i < m; ++i) {
    long long x, y;
    cin >> x >> y;
    auto it = lower_bound(v.begin(), v.end(), x);
    if (it == v.end()) {
      cout << max(0LL, x - v[n - 1]) + max(0LL, y - p[n - 2]) << "\n";
    } else {
      long long idx = it - v.begin();
      long long sum1 =
          max(0LL, y - ((idx ? p[idx - 1] : 0LL) + (p[n - 1] - p[idx])));
      idx--;
      long long sum2 = (idx == -1 ? INT_MAX
                                  : max(0LL, x - v[idx]) +
                                        max(0LL, y - ((idx ? p[idx - 1] : 0LL) +
                                                      (p[n - 1] - p[idx]))));
      cout << min(sum1, sum2) << "\n";
    }
  }
}
