#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, x, cnt, mn, mx;
int main() {
  cin >> n;
  cin >> x;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  mn = mx = x;
  for (int i = 1; i < n; i++) {
    cin >> x;
    if (x < mn || x > mx) {
      cnt++;
      mn = min(mn, x);
      mx = max(mx, x);
    }
  }
  cout << cnt << endl;
  return 0;
}
