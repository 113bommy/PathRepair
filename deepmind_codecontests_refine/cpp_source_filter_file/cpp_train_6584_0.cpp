#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long solve(long long n, long long k) {
  if (k == 1) return n;
  if (k == 2) return n % 2 == 0 ? n / 2 : n;
  if (k >= n) return 1;
  long long m = n, sqt = sqrt(n);
  for (long long a = 1; a <= sqt && a <= k; a++) {
    if (n % a == 0) {
      m = min(m, n / a);
      if (n / a <= k) return a;
    }
  }
  return m;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    cout << solve(n, k);
  }
  return 0;
}
