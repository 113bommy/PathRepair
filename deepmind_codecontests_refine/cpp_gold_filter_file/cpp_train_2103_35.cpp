#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    if (a >= c && b >= d) {
      if ((ceil(a * 1.00 / c) + ceil(b * 1.00 / d)) > k)
        cout << "-1" << endl;
      else
        cout << ceil(a * 1.00 / c) << " " << ceil(b * 1.00 / d) << endl;
    } else {
      if (a < c && b < d) {
        if (2 > k)
          cout << "-1" << endl;
        else
          cout << "1"
               << " "
               << "1" << endl;
      } else if (a < c) {
        if ((1 + ceil(b * 1.00 / d)) <= k)
          cout << "1"
               << " " << ceil(b * 1.00 / d) << endl;
        else
          cout << "-1" << endl;
      } else {
        if ((ceil(a * 1.00 / c) + 1) <= k)
          cout << ceil(a * 1.00 / c) << " "
               << "1" << endl;
        else
          cout << "-1" << endl;
      }
    }
  }
  return 0;
}
