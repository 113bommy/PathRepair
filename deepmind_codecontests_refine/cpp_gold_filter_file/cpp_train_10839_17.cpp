#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, k = 0;
  long long x, y, z = 0;
  long long hsl[1002];
  cin >> a;
  for (int i = 1; i <= a; i++) {
    y = 0;
    z = 0;
    cin >> b >> k >> x;
    if (x % 2 == 0) {
      y = x / 2;
      z = x / 2;
    } else {
      z = x / 2 + 1;
      y = x / 2;
    }
    z = z * b;
    y = y * k;
    z = z - y;
    hsl[i] = z;
  }
  for (int i = 1; i <= a; i++) {
    cout << hsl[i] << endl;
  }
}
