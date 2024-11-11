#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int i, j, k, l, a, b, c, minn = 1000000009, A, B, C, x, y, z,
                                       sum = 0;
    cin >> a >> b >> c;
    for (i = 1; i <= 10000; i++) {
      for (j = i; j <= 10000; j += i) {
        for (k = j; k <= 10000; k += j) {
          sum = abs(c - k) + abs(b - j) + abs(a - i);
          if (sum < minn) {
            minn = sum;
            A = i;
            B = j;
            C = k;
          }
        }
      }
    }
    cout << minn << endl;
    cout << A << " " << B << " " << C << endl;
  }
  return 0;
}
