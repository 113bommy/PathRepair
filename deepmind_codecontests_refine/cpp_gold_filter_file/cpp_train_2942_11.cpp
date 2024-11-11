#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 3) {
      cout << 2 << endl;
    } else if (n == 1)
      cout << 1 << endl;
    else if (n == 2)
      cout << 1 << endl;
    else if (n % 2 == 0)
      cout << n / 2 << endl;
    else {
      cout << 1 + n / 2 << endl;
    }
  }
}
