#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long a, b, c, num, mo, tot = 1;
  cin >> a >> b >> c;
  if ((a - 1) * b < c || b > c)
    return cout << "NO", 0;
  else {
    cout << "YES" << endl;
    num = c / b;
    mo = c % b;
    for (long long i = 0; i < b; i++) {
      if (mo == 0) {
        if (tot + num > a) {
          tot -= num;
          cout << tot << " ";
        } else {
          tot += num;
          cout << tot << " ";
        }
      } else {
        if (tot + num + 1 > a) {
          tot -= num;
          cout << tot << " ";
        } else {
          tot += num + 1;
          cout << tot << " ";
        }
        mo--;
      }
    }
    cout << endl;
  }
  return 0;
}
