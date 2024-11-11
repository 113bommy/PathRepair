#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long ans = 0;
    if (n == 1)
      cout << ans << '\n';
    else {
      for (long i = 1; i <= n / 2; i++) {
        ans += ((2 * i) + 1) * 2 * i;
        ans += (2 * i - 1) * i * 2;
      }
      cout << ans << '\n';
      ans = 0;
    }
  }
  return 0;
}
