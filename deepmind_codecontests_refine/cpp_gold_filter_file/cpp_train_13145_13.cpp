#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int x, y;
  cin >> x >> y;
  long long int c[10], i;
  for (i = 1; i <= 6; i++) {
    cin >> c[i];
  }
  c[0] = c[6];
  c[7] = c[1];
  for (i = 1; i <= 6; i++) {
    c[i] = min(c[i - 1] + c[i + 1], c[i]);
  }
  long long int ans = 0;
  if (x >= 0) {
    if (y >= x) {
      ans = (y - x) * c[2] + x * c[1];
    } else if (y <= 0) {
      ans = abs(y) * c[5] + x * c[6];
    } else {
      ans = y * c[1] + (x - y) * c[6];
    }
  } else {
    if (x >= y) {
      ans = ((x - y) * c[5]) + abs(x) * c[4];
    } else if (y >= 0) {
      ans = abs(x) * c[3] + y * c[2];
    } else {
      ans = abs(y) * c[4] + abs(x - y) * c[3];
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
