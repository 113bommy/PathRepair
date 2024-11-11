#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d = 0, m, ans;
    cin >> n;
    m = n % 10;
    while (n > 0) {
      n /= 10;
      d++;
    }
    ans = 10 * (m - 1) + (d * (d + 1)) / 2;
    cout << ans << "\n";
  }
}
