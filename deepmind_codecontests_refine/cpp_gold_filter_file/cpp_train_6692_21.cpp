#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, a, b, c, d, k;
  cin >> t;
  for (long long j = 0; j < t; j++) {
    cin >> n;
    int x;
    if (n > 1000) {
      x = n / 1000 * 10;
    } else if (n > 100) {
      x = (n / 100 - 1) * 10 + 6;
    } else if (n > 10) {
      x = (n / 10 - 1) * 10 + 3;
    } else {
      x = (n - 1) * 10 + 1;
    }
    cout << x << endl;
  }
  return 0;
}
