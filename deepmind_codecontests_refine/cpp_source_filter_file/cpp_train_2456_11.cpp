#include <bits/stdc++.h>
long long int mx = 1e18;
long long int mn = -1e18;
using namespace std;
long long int a[100010];
int main() {
  long long int p, q, r, s, t, n, ans, m, k;
  cin >> n >> k;
  m = INT_MAX;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    m = min(m, a[i]);
  }
  if (m % k != 0) {
    cout << "-1" << endl;
    return 0;
  }
  ans = 0;
  for (long long i = 0; i < n; i++) {
    p = a[i] - m;
    if (p % k != 0) {
      cout << "-1" << endl;
      return 0;
    }
    ans += p;
  }
  ans /= k;
  cout << ans << endl;
}
