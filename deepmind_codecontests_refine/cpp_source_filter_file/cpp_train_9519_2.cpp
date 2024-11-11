#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, c, d;
  cin >> c >> d;
  cin >> n >> m;
  cin >> k;
  int t = n * m - k, ans = 0;
  while (t > 0) {
    if (t >= n) {
      ans += min(n * d, c);
      t -= n;
    } else {
      ans += min(t, c);
      t = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
