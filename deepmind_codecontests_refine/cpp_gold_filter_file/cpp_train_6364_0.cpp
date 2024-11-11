#include <bits/stdc++.h>
using namespace std;
int n, a[1005];
int main() {
  int i, t, mini = 1000000, s, val, tfin;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (t = 1; t <= 105; t++) {
    s = 0;
    for (i = 1; i <= n; i++) {
      val = abs(t + 1 - a[i]);
      val = min(val, abs(t - a[i]));
      val = min(val, abs(t - 1 - a[i]));
      s += val;
    }
    if (mini > s) {
      mini = s;
      tfin = t;
    }
  }
  cout << tfin << ' ' << mini;
  return 0;
}
