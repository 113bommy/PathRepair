#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long mod = 1e9 + 7;
const long long N = 3e5 + 1;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (auto &it : v) {
    cin >> it;
  }
  sort(v.begin(), v.end());
  long long l = n / 2, r = n - 1, opt = l, opt_req = 0;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    bool OK = 1;
    long long req = 0;
    for (long long i = n / 2 + 1; i < mid + 1; i++)
      req += (i - n / 2) * (v[i] - v[i - 1]);
    if (req > k) OK = 0;
    if (OK)
      l = mid + 1, opt = mid, opt_req = req;
    else
      r = mid - 1;
  }
  cout << v[opt] + (k - opt_req) / (opt - n / 2 + 1);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) solve();
  return 0;
}
