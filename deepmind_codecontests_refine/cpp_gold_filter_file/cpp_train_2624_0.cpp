#include <bits/stdc++.h>
using namespace std;
long long i, j, k, n, x, y, m[600000], a, b, z;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    x = 0;
    y = 0;
    if (b <= a) {
      cout << b << endl;
      continue;
    }
    x = b % a;
    z = b / a;
    for (j = 0; j < x; j++) {
      y += (z + 1) * (z + 1);
    }
    for (j = 0; j < a - x; j++) {
      y += z * z;
    }
    cout << y << endl;
  }
}
