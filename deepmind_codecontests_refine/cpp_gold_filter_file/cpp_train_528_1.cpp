#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (m > n) {
      swap(n, m);
    }
    long long int mnm = min(n, m) + (n - m);
    if (n == 0 && m == 0) {
      mnm = 2;
    }
    if (k < mnm) {
      cout << -1 << "\n";
    } else {
      if (n % 2 != m % 2)
        cout << k - (n % 2 != m % 2) << "\n";
      else {
        if (mnm % 2 != k % 2) {
          cout << max(0LL, k - 2) << "\n";
        } else {
          cout << k << "\n";
        }
      }
    }
  }
}
