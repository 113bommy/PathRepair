#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double a, b, c, d, k, p;
    cin >> a >> b >> c;
    k = a - b;
    d = ((k * k) + (c * c));
    p = sqrt(d);
    cout << p << endl;
  }
  return 0;
}
