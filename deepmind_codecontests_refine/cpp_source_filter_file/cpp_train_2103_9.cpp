#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a, b, c, d, k;
  while (t--) {
    int cnt1 = 0, cnt2 = 0;
    cin >> a >> b >> c >> d >> k;
    if (a % c == 0)
      cnt1 += a / c;
    else
      cnt1 += (a / c) + 1;
    if (b % d == 0)
      cnt2 += b / d;
    else
      cnt2 += (b / d) + 1;
    if ((cnt1 + cnt2) <= k)
      cout << cnt1 << " " << cnt2 << endl;
    else
      cout << -1;
  }
}
