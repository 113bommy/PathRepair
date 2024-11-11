#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int tmp = 0; tmp < t; tmp++) {
    unsigned long long int n, k;
    cin >> n >> k;
    if (k >= n) {
      cout << 1 << "\n";
      continue;
    }
    bool fl = false;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0 && n / i <= k) {
        cout << i << "\n";
        fl = true;
        break;
      }
    }
    if (!fl) {
      for (int i = int(sqrt(n)); i >= 2; i--) {
        if (n % i == 0 && i <= k) {
          cout << n / i << "\n";
          fl = true;
          break;
        }
      }
    }
    if (!fl) {
      cout << n << "\n";
    }
  }
}
