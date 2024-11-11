#include <bits/stdc++.h>
using namespace std;
int n, k, m, t, a, b;
int main() {
  cin >> n >> m >> k >> t;
  while (t--) {
    cin >> a >> b;
    if (a == 0) {
      if (b > m) {
        n -= (n - b);
      } else {
        n -= b;
        m -= b;
      }
    } else {
      if (b > m) {
        n++;
      } else {
        n++;
        m++;
      }
    }
    cout << n << ' ' << m << endl;
  }
}
