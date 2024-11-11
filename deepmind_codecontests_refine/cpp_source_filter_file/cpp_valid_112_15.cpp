#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a[3], m;
  cin >> a[0] >> a[1] >> a[2] >> m;
  sort(a, a + 3);
  int minsum = 0, maxsum = 0;
  maxsum = a[0] + a[1] + a[2] - 3;
  minsum = a[0] - a[1] - a[2] - 1;
  if (m >= minsum && m <= maxsum)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t = 0;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
