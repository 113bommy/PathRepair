#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long cntl = 0, cntr = 0;
  while (n--) {
    long long x, y;
    cin >> x >> y;
    if ((x >= 0 && y >= 0) || (x >= 0 && y < 0))
      cntr++;
    else
      cntl++;
  }
  if (cntl <= 1 || cntr <= 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
int32_t main() {
  solve();
  return 0;
}
