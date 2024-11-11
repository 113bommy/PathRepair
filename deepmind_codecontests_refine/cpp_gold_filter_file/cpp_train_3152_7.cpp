#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long int t;
  cin >> t;
  while (t--) {
    long long int a, b, x, y, n, ans = 1e18;
    cin >> a >> b >> x >> y >> n;
    for (int i = 0; i < 2; i++) {
      int da = min(n, a - x);
      int db = min(n - da, b - y);
      ans = min(ans, (a - da) * (b - db));
      swap(a, b);
      swap(x, y);
    }
    cout << ans << "\n";
  }
}
