#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2)
        cout << "NO" << '\n';
      else
        cout << "YES" << '\n';
    } else if (n % 2 == 1 && m % 2 == 0) {
      if ((n * m / 2 - k) >= 0 && (n * m / 2 - k) <= (n * m - m) / 2 &&
          ((n * m / 2 - k) % 2 == 0))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    } else {
      if (k >= 0 && k <= (n * m - n) / 2 && (k % 2 == 0))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
}
