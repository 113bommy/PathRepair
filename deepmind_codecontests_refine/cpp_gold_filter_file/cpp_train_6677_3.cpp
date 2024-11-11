#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (2 * b <= c) {
      cout << a * b << endl;
    } else {
      if (a % 2 == 0) {
        cout << ((a)*c) / 2 << endl;
      } else {
        cout << ((a - 1) * c) / 2 + b << endl;
      }
    }
  }
}
