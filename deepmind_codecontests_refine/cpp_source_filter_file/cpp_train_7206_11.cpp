#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    a++;
    b++;
    long long ans = max(max(a - 1, x - a - 1) * y, max(b - 1, y - b - 1) * x);
    cout << ans << endl;
  }
  return 0;
}
