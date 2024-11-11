#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double n, r;
    cin >> n;
    r = cos(3.141592653589793238462643383279502884197169399375105820974944592307816406286 *
            (1 / (2 * n))) /
        sin(3.141592653589793238462643383279502884197169399375105820974944592307816406286 *
            (1 / (2 * n)));
    cout << fixed << setprecision(6) << r << "\n";
  }
  return 0;
}
