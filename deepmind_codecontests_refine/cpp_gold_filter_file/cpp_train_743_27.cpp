#include <bits/stdc++.h>
using namespace std;
int n, k, m, t, a, b;
int main() {
  cin >> n >> k >> m >> t;
  while (t--) {
    cin >> a >> b;
    if (a == 0) {
      if (b >= k) {
        n -= (n - b);
      } else {
        n -= b;
        k -= b;
      }
    } else {
      if (b > k) {
        n++;
      } else {
        n++;
        k++;
      }
    }
    cout << n << ' ' << k << endl;
  }
}
