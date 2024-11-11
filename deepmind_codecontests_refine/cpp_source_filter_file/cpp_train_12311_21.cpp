#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, x, p = -1, q = -1;
    double r;
    cin >> a >> b >> x;
    if (a < x) {
      p = b - 1;
    }
    r = (double)x / b;
    if (r < a) {
      q = b;
    }
    cout << p << " " << q << endl;
  }
  return 0;
}
