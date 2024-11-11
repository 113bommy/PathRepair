#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int T = 0; T < t; T++) {
    int x, y, n;
    cin >> x >> y >> n;
    int m = n / x;
    if (x * m + y > n) m--;
    cout << x * m + y;
  }
  return 0;
}
