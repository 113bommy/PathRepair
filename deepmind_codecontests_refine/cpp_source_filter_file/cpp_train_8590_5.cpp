#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
void solve() {
  int n, h, d;
  cin >> n >> d >> h;
  if (d > 2 * h || h == 1 && d == 1 && n > 3) {
    cout << "-1";
    return;
  }
  int i;
  for (i = 1; i <= h; i++) {
    cout << i << " " << i + 1 << endl;
  }
  if (h == d) {
    for (int i = h + 2; i < n + 1; i++) cout << "2 " << i << endl;
  } else {
    cout << "1 " << h + 2 << endl;
    d = d - h;
    d--;
    for (int i = 0; i < d; i++) {
      cout << h + 2 + i << " " << h + 3 + i << endl;
    }
    for (int i = h + d + 3; i < n + 1; i++) cout << "1 " << i << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
