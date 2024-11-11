#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 100;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, q;
  cin >> n >> q;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    if (y & 1) {
      if (x & 1) {
        long long prev = (x / 2) * n;
        cout << prev + ((y + 1) / 2) << endl;
      } else {
        long long prev = ((x - 1) / 2) * n + (n * n + 1) / 2 + n / 2;
        cout << prev + ((y + 1) / 2) << endl;
      }
    } else {
      if (x & 1) {
        long long prev = (x / 2) * n + (n * n + 1) / 2;
        cout << prev + ((y + 1) / 2) << endl;
      } else {
        long long prev = ((x - 1) / 2) * n + ((n + 1) / 2);
        cout << prev + ((y + 1) / 2) << endl;
      }
    }
  }
  return 0;
}
