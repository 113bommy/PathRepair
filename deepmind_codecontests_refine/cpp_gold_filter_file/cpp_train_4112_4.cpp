#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k = 0, c = -1, x, z;
  cin >> n;
  while (true) {
    c += 1;
    x = pow(10, c);
    z = 9 * x;
    if (n - z > 0) {
      n -= z;
      k += (z * (c + 1));
    } else {
      n *= (c + 1);
      k += n;
      break;
    }
  }
  cout << k;
  return 0;
}
