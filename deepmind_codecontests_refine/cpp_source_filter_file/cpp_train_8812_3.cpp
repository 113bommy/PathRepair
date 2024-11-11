#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m, d, x, ans;
  cin >> n >> k >> m >> d;
  ans = m;
  for (int i = 2; i <= d && (k * i - k + 1) <= n; i++) {
    x = (n / ((i * k) - (k - 1)));
    x = min(x, m);
    ans = max(ans, x * i);
  }
  cout << ans << endl;
  return 0;
}
