#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    if (ceil(a / c) + ceil(b / d) > k) {
      cout << -1 << endl;
    } else {
      cout << ceil(a / c) << " " << ceil(b / d);
    }
  }
}
