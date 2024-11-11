#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, x, y, d;
    long long ans = INT_MAX;
    cin >> n >> x >> y >> d;
    if ((abs(y - x)) % d == 0)
      ans = abs(y - x) / d;
    else {
      if (abs(y - 1) % d == 0) {
        long long tmp = abs(y - 1) / d + abs(x - 1) / d + 1;
        ans = min(ans, tmp);
      }
      if (abs(y - n) % d == 0) {
        long long tmp2 = abs(y - n) / d + abs(x - n) / d + 1;
        ans = min(ans, tmp2);
      }
    }
    if (ans == INT_MAX)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}
