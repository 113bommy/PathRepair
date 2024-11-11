#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, n;
  cin >> q;
  while (q--) {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    string ans = "YES";
    bool clock;
    if (n > 1) {
      clock = ((a[0] + 1) % n == a[1]) ? 1 : 0;
      int i = 0;
      if (clock) {
        while (i < n - 1) {
          if ((a[i] + 1) % n != a[i + 1] % n) {
            ans = "NO";
            break;
          }
          i++;
        }
      } else {
        while (i < n - 1) {
          if ((a[i] - 1) % n != a[i + 1] % n) {
            ans = "NO";
            break;
          }
          i++;
        }
      }
    }
    cout << ans << "\n";
  }
}
