#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int rem = n % k;
    long long int x = k / 2;
    long long int ans;
    if (rem != 0)
      ans = n - (rem - x);
    else
      ans = n;
    cout << ans << "\n";
  }
  return 0;
}
