#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    int a[n];
    string s;
    cin >> s;
    if (s[0] == '0')
      a[0] = 1;
    else
      a[0] = -1;
    for (int i = 1; i < n; i++) {
      if (s[i] == '0')
        a[i] = a[i - 1] + 1;
      else
        a[i] = a[i - 1] - 1;
    }
    int rt = a[n - 1];
    if (rt == 0) {
      bool found = false;
      for (int i = 0; i < n; i++) {
        if (a[i] == x) {
          cout << "-1"
               << "\n";
          found = true;
          break;
        }
      }
      if (!found) {
        cout << "0"
             << "\n";
      }
    } else {
      int ans = 0;
      for (int i = 0; i < n; i++) {
        int mt = x - a[i];
        if ((mt <= 0 && rt <= 0) || (mt > 0 && rt > 0)) {
          if (mt % rt == 0) {
            ans += 1;
          }
        }
      }
      if (x == 0) {
        ans += 1;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
