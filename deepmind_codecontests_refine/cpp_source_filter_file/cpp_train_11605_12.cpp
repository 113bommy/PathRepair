#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long a, m;
  cin >> a >> m;
  long long x = a % m;
  long long z = a + x;
  long long flag = 0;
  if (z % m == 0) {
    flag = 1;
  } else {
    while (z < 2 * m) {
      x = z % m;
      z += x;
      if (z % m == 0) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1) {
    cout << "Yes"
         << "\n";
  } else {
    cout << "No"
         << "\n";
  }
  return 0;
}
