#include <bits/stdc++.h>
using namespace std;
int n, a;
int main() {
  cin >> n >> a;
  int ans = n;
  for (int i = 3; i <= n; i++) {
    long long angle = (i - 2) * 180;
    if (angle >= a * n) {
      if (i == 3 || abs(angle - a * n) <= abs(1ll * (i - 3) * 180 - a * n))
        ans = i;
      else
        ans = i - 1;
      break;
    }
  }
  cout << 2 << ' ' << 1 << ' ' << ans << endl;
  return 0;
}
