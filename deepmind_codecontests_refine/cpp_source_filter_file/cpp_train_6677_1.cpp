#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    if (2 * a < b) {
      long long ans = n * a;
      cout << ans << endl;
    } else {
      long long cou = n % 2;
      int ans = (n / 2) * b;
      if (cou == 1) {
        ans += a;
      }
      cout << ans << endl;
    }
  }
}
