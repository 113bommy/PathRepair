#include <bits/stdc++.h>
using namespace std;
long long int M = 1000000007;
long long int gcd(long long int a, long long int b) {
  return (b == 0) ? a : gcd(b, a % b);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    long long int n, x;
    cin >> n >> x;
    long long int ans = 0;
    long long int a[n], b[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      if (a[i] > b[i]) swap(a[i], b[i]);
    }
    long long int l = *max_element(a, a + n);
    long long int r = *min_element(b, b + n);
    if (r < l) {
      cout << -1;
    } else {
      if (x < l)
        ans = l - x;
      else if (x > r)
        ans = x - r;
      else
        ans = 0;
      cout << ans;
    }
  }
  return 0;
}
