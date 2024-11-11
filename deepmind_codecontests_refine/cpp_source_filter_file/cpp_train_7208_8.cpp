#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n / k >= m) {
      cout << m << endl;
    } else {
      int x = n / k;
      int t = (m - x) / (k - 1);
      if ((m - x) % (n - 1) == 0) {
        cout << x - t << endl;
      } else {
        cout << x - (t + 1) << endl;
      }
    }
  }
}
