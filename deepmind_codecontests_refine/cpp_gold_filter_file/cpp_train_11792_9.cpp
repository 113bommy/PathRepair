#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tt, n, k, l1, r1, l2, r2, steps, intersec, ans, req, temp, pre;
  cin >> tt;
  while (tt--) {
    ans = 0;
    cin >> n >> k;
    cin >> l1 >> r1 >> l2 >> r2;
    steps = abs(l1 - l2) + abs(r2 - r1);
    intersec = abs(min(l1, l2) - max(r2, r1));
    pre = min(r1, r2) - max(l2, l1);
    if (pre > 0) {
      k -= (pre * n);
      intersec -= pre;
    }
    if (k <= 0) {
      cout << "0\n";
      continue;
    }
    if (intersec == 0) {
      cout << k * 2 << endl;
      continue;
    }
    if (k % intersec == 0)
      req = k / intersec;
    else
      req = (k / intersec) + 1;
    if (req > n) {
      ans += n * steps;
      ans += (k - (n * intersec)) * 2;
    } else if (req <= n) {
      temp = k / intersec;
      ans += temp * steps;
      k -= (temp * intersec);
      if (pre < 0) {
        if (temp >= 1)
          ans += min(k - pre, k * 2);
        else
          ans += k - pre;
      } else
        ans += min(k, k * 2);
    }
    cout << ans << endl;
  }
}
