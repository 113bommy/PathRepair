#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int tc = 1;
  while (tc--) {
    long long int n;
    cin >> n;
    if (n % 2) {
      cout << 0;
      return 0;
    }
    long long int ans = pow(2, n / 2);
    cout << ans;
  }
}
