#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n)))
    cin >> a[i];
  if (n <= 2) {
    cout << 0;
  } else {
    long long int ans = 0;
    for (__typeof(n - 1) i = (1) - ((1) > (n - 1));
         i != (n - 1) - ((1) > (n - 1)); i += 1 - 2 * ((1) > (n - 1))) {
      if ((a[i] > a[i - 1] && a[i] > a[i + 1]) ||
          (a[i] < a[i - 1] && a[i] < a[i + 1]))
        ans++;
    }
    cout << ans;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int test;
  test = 1;
  while (test--) {
    solve();
    cout << '\n';
  }
  return 0;
}
