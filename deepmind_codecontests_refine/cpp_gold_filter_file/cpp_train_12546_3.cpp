#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int cnt = 0;
  int n;
  cin >> n;
  long long ans = 0;
  int mx = 1e9;
  while (n--) {
    int first;
    cin >> first;
    if (first & 1) cnt += 1, mx = min(mx, first);
    ans += first;
  }
  cnt &= 1;
  ans -= cnt * mx;
  return cout << ans << '\n', 0;
}
