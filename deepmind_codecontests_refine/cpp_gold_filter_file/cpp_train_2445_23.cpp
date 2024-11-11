#include <bits/stdc++.h>
using namespace std;
int main() {
  long long A, B, n;
  cin >> A >> B >> n;
  for (int i = 0; i < n; i++) {
    long long l, t, m;
    cin >> l >> t >> m;
    long long z;
    long long t1 = A + (l - 1) * B;
    long long left = 1, right = 1500000;
    long long sol;
    while (left <= right) {
      z = (left + right) / 2;
      sol = z - 1;
      if ((z * t1 + ((z * (z - 1)) / 2) * B > min(m, z) * t ||
           t1 + (z - 1) * B > t) &&
          sol * t1 + ((sol * (sol - 1)) / 2) * B <= min(m, sol) * t &&
          t1 + (sol - 1) * B <= t)
        break;
      else if (z * t1 + ((z * (z - 1)) / 2) * B <= min(m, z) * t &&
               t1 + (z - 1) * B <= t)
        left = z + 1;
      else
        right = z - 1;
    }
    if (sol == 0)
      cout << -1 << endl;
    else
      cout << sol + l - 1 << endl;
  }
  return 0;
}
