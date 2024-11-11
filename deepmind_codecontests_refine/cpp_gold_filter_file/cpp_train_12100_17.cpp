#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long mxi = 1000000;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    if ((y - x) % (a + b) == 0) {
      cout << (y - x) / (a + b) << "\n";
    } else
      cout << -1 << "\n";
  }
}
