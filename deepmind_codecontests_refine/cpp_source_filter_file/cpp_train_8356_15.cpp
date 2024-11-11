#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long cnt3 = 0, cnt5 = 0, cnt7 = 0;
  long long md = n % 3;
  cnt3 = n / 3;
  if (md == 0) {
    cout << cnt3 << " " << 0 << " " << 0 << "\n";
    ;
    return;
  } else if (md == 1) {
    cnt3 -= 2;
    cnt7 = 7;
    if (cnt3 < 0) {
      cout << -1 << "\n";
      ;
      return;
    }
    cout << cnt3 << " " << cnt5 << " " << cnt7 << "\n";
    ;
  } else {
    cnt3 -= 4;
    cnt7 = 2;
    if (cnt3 < 0) {
      cout << -1 << "\n";
      ;
      return;
    }
    cout << cnt3 << " " << cnt5 << " " << cnt7 << "\n";
    ;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1, p;
  cin >> t;
  p = t;
  t = 1;
  while (p--) {
    solve();
    t++;
  }
  return 0;
}
