#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = INF;
    if (n == 1) {
      cout << 0 << endl;
    } else {
      for (int i = 2; i <= sqrt(n) + 1; i++) {
        if (n % i == 0) {
          ans = min(ans, n / i + i - 2);
        } else {
          ans = min(ans, n / i + i - 1);
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
