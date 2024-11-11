#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r;
  cin >> n;
  int ans = 1;
  int minl, maxr;
  cin >> minl >> maxr;
  for (int i = 2; i <= n; i++) {
    cin >> l >> r;
    if (l <= minl && r >= maxr)
      ans = i;
    else if (l < minl || r > maxr)
      ans = -1;
    minl = min(minl, l);
    maxr = max(maxr, r);
  }
  cout << ans << '\n';
  return 0;
}
