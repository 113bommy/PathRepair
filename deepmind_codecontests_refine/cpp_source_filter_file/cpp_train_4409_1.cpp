#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 5;
void solve() {
  long long int n, k;
  cin >> n >> k;
  char a[n][k];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < k; j++) cin >> a[i][j];
  }
  long long int x0 = -1, y0 = -1, x1 = -1, y1 = -1, x2 = -1, y2 = -1;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < k; j++) {
      if (x0 < 0 and a[i][j] == '*') {
        x0 = i + 1;
        y0 = j + 1;
      } else if (x1 < 0 and a[i][j] == '*') {
        x1 = i + 1;
        y1 = j + 1;
      } else if (x2 < 0 and a[i][j] == '*') {
        x2 = i + 1;
        y2 = j + 1;
      }
    }
  }
  if (y0 == y2 and x1 == x2)
    cout << x0 << " " << y1 << "\n";
  else if (x0 == x1 and y0 == y2)
    cout << x2 << " " << y1 << "\n";
  else if (x0 == x1 and y1 == y2)
    cout << x0 << " " << y2 << "\n";
  else if (y0 == y1 and x1 == x2)
    cout << x0 << " " << y2 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) solve();
  return 0;
}
