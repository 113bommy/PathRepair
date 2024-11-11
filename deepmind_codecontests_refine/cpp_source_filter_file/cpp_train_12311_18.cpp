#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, a1 = 0, a2 = 0;
    cin >> a >> b >> c;
    if (a < c) {
      a1 = 1;
      if (b * a > c) {
        a2 = b;
      } else {
        a2 = -1;
      }
    } else {
      a1 = -1;
      a2 = 1;
    }
    cout << a1 << " " << a2 << "\n";
  }
  return 0;
}
