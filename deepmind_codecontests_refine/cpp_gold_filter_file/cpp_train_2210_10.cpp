#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, n, i, x[20], y[20];
  cin >> n;
  for (i = 0; i <= 10; i++) {
    x[i] = 0;
    y[i] = 0;
  }
  for (i = 0; i < n; i++) {
    cin >> k;
    if (k > -1) {
      x[k]++;
    } else {
      k = k * -1;
      y[k]++;
    }
  }
  long long z1, z, val = 0;
  z = x[0];
  if (z > 1) {
    if (z % 2 == 0) {
      z1 = z / 2;
      val += z1 * (z - 1);
    } else {
      z1 = (z - 1) / 2;
      val += z * z1;
    }
  }
  for (i = 1; i <= 10; i++) {
    val += x[i] * y[i];
  }
  cout << val << endl;
  return 0;
}
