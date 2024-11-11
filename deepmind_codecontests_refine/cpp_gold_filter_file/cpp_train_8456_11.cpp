#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n;
    for (k = 2; k <= 29; k++) {
      long long int val;
      long long int m = pow(2, k) - 1;
      val = n % m;
      if (val == 0) {
        cout << n / m << "\n";
        break;
      }
    }
  }
  return 0;
}
