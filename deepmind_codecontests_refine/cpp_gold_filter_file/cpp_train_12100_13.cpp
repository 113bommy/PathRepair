#include <bits/stdc++.h>
using namespace std;
void solve() {
  double x, y, a, b;
  cin >> x >> y >> a >> b;
  if (floor((y - x) / (a + b)) == ceil((y - x) / (a + b)))
    cout << int((y - x) / (a + b)) << endl;
  else
    cout << -1 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
