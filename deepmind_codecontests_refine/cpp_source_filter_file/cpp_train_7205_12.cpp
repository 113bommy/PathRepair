#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n = 0, a[3];
    cin >> a[0] >> a[1] >> a[2] >> n;
    sort(a, a + 3);
    if (a[2] - a[0] < n) {
      n = n - (a[2] - a[0]);
      a[0] = a[0] + (a[2] - a[0]);
      if ((a[2] - a[1]) <= n) {
        n = n - (a[2] - a[1]);
        a[1] = a[1] + (a[2] - a[1]);
        if (n % 3 == 0) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
