#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, x0, l = -1, r = 1003, ai, bi;
  cin >> n >> x0;
  while (n--) {
    cin >> ai >> bi;
    if (ai > bi) swap(ai, bi);
    l = max(l, ai);
    r = min(r, bi);
  }
  if (l > r)
    cout << -1 << endl;
  else if (l <= x0 && x0 <= r)
    cout << 0 << endl;
  else if (l > x0)
    cout << l - x0 << endl;
  else
    cout << x0 - r << endl;
  return 0;
}
