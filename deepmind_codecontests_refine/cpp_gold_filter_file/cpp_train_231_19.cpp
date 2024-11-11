#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = -1;
    long long p2 = 0, p3 = 0;
    while (n % 2 == 0) {
      n /= 2;
      p2++;
    }
    while (n % 3 == 0) {
      n /= 3;
      p3++;
    }
    if (n == 1 && p2 <= p3) {
      ans = 2 * p3 - p2;
    }
    cout << ans << "\n";
  }
  return 0;
}
