#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, c, d, n, m, k, t1, t2, t3, ans;
  cin >> c >> d >> n >> m >> k;
  t2 = n * m - k;
  t3 = t2 - (t2 % n);
  ans = min(t3 * c / n, t3 * d);
  if (t2 % n != 0) {
    t1 = min(c, (t2 % n) * d);
    ans += t1;
  }
  cout << ans;
}
