#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d;
  while (cin >> n >> a >> b >> c >> d) {
    int mx = max(a + b, max(a + c, max(d + b, d + c)));
    int mn = min(a + b, min(a + c, min(d + b, d + c)));
    long long int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += n - (mx + 1 - mn) + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
