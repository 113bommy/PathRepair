#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O2")
const int LIM = 5e5 + 5, MOD = 1e9 + 7;
int t, n, m, k, x, y;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  int max = 0;
  bool flag = true;
  cin >> x;
  if (x != 0) {
    cout << 1;
    flag = false;
  }
  for (int i = 2; i <= n; i++) {
    cin >> x;
    if (!flag) continue;
    if (x <= max + 1 && x >= 0) {
      if (x > max) max = x;
    } else {
      cout << i;
      flag = false;
    }
  }
  if (flag) cout << -1;
}
