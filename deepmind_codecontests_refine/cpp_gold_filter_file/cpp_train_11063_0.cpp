#include <bits/stdc++.h>
using namespace std;
long long t, n, p, k1, k0;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    k1 = 0;
    k0 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> p;
      if (p == 0)
        k0++;
      else
        k1++;
    }
    if (k0 >= n / 2) {
      cout << n / 2 << endl;
      for (int i = 1; i <= n / 2; i++) cout << 0 << ' ';
      cout << endl;
    } else {
      cout << k1 - k1 % 2 << endl;
      for (int i = 1; i <= k1 - k1 % 2; i++) cout << 1 << ' ';
      cout << endl;
    }
  }
  return 0;
}
