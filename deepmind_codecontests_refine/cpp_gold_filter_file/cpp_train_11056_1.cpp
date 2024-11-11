#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    if (y <= x) {
      cout << "YES\n";
      continue;
    }
    long long t = y % 3 == 0 ? y : y + (3 - y % 3);
    t = (2 * t) / 3;
    if (x < 4 && t > x)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
