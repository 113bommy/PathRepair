#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  long long sum, a, b, a1, b1;
  while (t--) {
    cin >> a >> b;
    a1 = a;
    b1 = b;
    int x = 0, j = 0;
    while (a || b) {
      if ((a & 1) && (b & 1)) {
        x += (1 << j);
      }
      a >>= 1;
      b >>= 1;
      j += 1;
    }
    sum = ((a1 ^ x) + (b1 ^ x));
    cout << sum << endl;
  }
  return 0;
}
