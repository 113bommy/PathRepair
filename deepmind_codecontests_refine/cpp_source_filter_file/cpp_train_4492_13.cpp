#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  while (cin >> n >> x >> y) {
    long long m = y - n + 1;
    if (m * m + n - 1 < x || m < 0) {
      cout << -1 << endl;
      continue;
    } else {
      cout << m << endl;
      for (int i = 1; i < n; i++) {
        cout << 1 << endl;
      }
    }
  }
  return 0;
}
