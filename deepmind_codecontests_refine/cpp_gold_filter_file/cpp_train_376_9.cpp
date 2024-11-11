#include <bits/stdc++.h>
const long long mxn = 1e5 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, b, frt = 0, cnt = 0, cnt1 = 0, ans = 0, ans1 = 0;
  cin >> a >> b;
  frt = abs(a - b);
  cnt = frt / 2;
  cnt1 = frt - frt / 2;
  ans = cnt * (cnt + 1) / 2;
  ans1 = cnt1 * (cnt1 + 1) / 2;
  cout << ans + ans1;
  return 0;
}
