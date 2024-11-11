#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  int a, b, c, d, k, x, y;
  while (t--) {
    cin >> a >> b >> c >> d >> k;
    x = (a / c) + ((a % c) == 0 ? 0 : 1);
    y = (b / d) + ((b % d) == 0 ? 0 : 1);
    if (x + y > k) {
      cout << -1 << endl;
    } else {
      cout << x << ' ' << y << endl;
    }
  }
}
