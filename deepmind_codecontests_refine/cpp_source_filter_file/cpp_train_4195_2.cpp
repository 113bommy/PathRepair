#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b * c) {
      cout << -1 << endl;
      continue;
    }
    if (c < d) {
      cout << a << endl;
      continue;
    }
    if (c >= d) {
      cout << (a / b / d) * a + a - d * b * (a / b / d) * (a / b / d + 1)
           << endl;
    }
  }
  return 0;
}
