#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (a >= c && b != 1) {
      cout << -1 << ' ';
    } else {
      cout << 1 << ' ';
    }
    if (c > b * a) {
      cout << -1 << endl;
    } else {
      cout << b << endl;
    }
  }
  return 0;
}
