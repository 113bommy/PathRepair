#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int n, k, m, t;
  cin >> m >> k >> n >> t;
  while (t--) {
    int i, l;
    cin >> i >> l;
    if (i) {
      m++;
      if (l <= k) k++;
      cout << m << ' ' << k << endl;
    } else {
      if (l >= k) {
        m = l;
      } else {
        m = m - l;
        k -= l;
      }
      cout << m << ' ' << k << endl;
    }
  }
}
