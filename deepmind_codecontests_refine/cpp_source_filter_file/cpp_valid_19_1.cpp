#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int a[20], n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long x = 1;
    for (int i = 0; i < n; i++) x *= 3;
    bool ans = 0;
    for (int i = 1; i < x; i++) {
      int sum = 0;
      long long y = i;
      for (int j = 0; j < n; j++) {
        if (y % 3 == 2)
          sum -= a[i];
        else if (y % 3)
          sum += a[i];
        y /= 3;
      }
      if (!sum) {
        ans = 1;
        break;
      }
    }
    if (ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
