#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = a / c + a % c > 0;
    int y = b / d + b % d > 0;
    if (x + y > k) {
      cout << -1 << endl;
      continue;
    }
    cout << x << ' ' << y << endl;
  }
}
