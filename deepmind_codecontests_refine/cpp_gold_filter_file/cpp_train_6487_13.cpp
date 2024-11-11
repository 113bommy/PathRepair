#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  const long long p = 1000000007;
  if (k == n) {
    long long prod = 1;
    for (int i = 0; i < max(n / 2, 1); i++) {
      prod *= m;
      prod %= p;
    }
    if (n % 2 == 1) {
      prod *= m;
      prod %= p;
    }
    cout << prod << endl;
  } else if (k > n) {
    long long prod = 1;
    for (int i = 0; i < n; i++) {
      prod *= m;
      prod %= p;
    }
    cout << prod << endl;
  } else {
    if (k == 1) {
      long long prod = 1;
      for (int i = 0; i < n; i++) {
        prod *= m;
        prod %= p;
      }
      cout << prod << endl;
    } else {
      if (k % 2 == 0) {
        cout << m << endl;
      } else {
        cout << m * m << endl;
      }
    }
  }
  return 0;
}
