#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long double pi = 2 * acos(0.0);
  while (t--) {
    int n;
    cin >> n;
    n *= 2;
    long double res = 1 / tan(pi / n);
    cout.precision(10);
    cout << res / 7 << endl;
  }
  return 0;
}
