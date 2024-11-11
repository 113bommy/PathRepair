#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int ans = 0;
    if (n % 2 == 0)
      ans = n + (2 * k);
    else {
      for (long long int j = 2; j * j <= n; j++) {
        if (n % j == 0) {
          ans = j;
          break;
        }
      }
      if (ans == 0) ans = n;
      n += n;
      k--;
      n += 2 * k;
      ans = n;
    }
    cout << ans << endl;
  }
}
