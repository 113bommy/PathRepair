#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long pow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x);
    x = (x * x);
    n >>= 1;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    long long i = 0;
    for (i = 1; i <= 10000; ++i) {
      long long lb = n - (lower_bound(a.begin(), a.end(), i) - a.begin());
      if (lb < i) break;
    }
    cout << i - 1 << '\n';
  }
  return 0;
}
