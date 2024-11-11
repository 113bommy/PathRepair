#include <bits/stdc++.h>
using namespace std;
long long a[200005], cnt[26];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long sum = 0;
  long long mx = 1e9;
  for (long long i = n - 1; i >= 0; i--) {
    if (a[i] < mx) {
      mx = a[i];
      sum += a[i];
    } else {
      sum += mx - 1;
      mx = mx - 1;
      if (mx == 0) break;
    }
  }
  cout << sum << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
