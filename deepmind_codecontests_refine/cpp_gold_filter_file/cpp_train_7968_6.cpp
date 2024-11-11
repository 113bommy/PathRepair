#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  long long m, k;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << -1;
    return 0;
  } else {
    if (n % 2 == 1) {
      m = n * n / 2;
      k = n * n / 2 + 1;
    } else {
      if (n % 2 == 0) {
        n /= 2;
        if (n % 2 == 1) {
          m = n * n / 2 * 2;
          k = (n * n / 2 + 1) * 2;
        } else {
          m = 3 * n / 2;
          k = 5 * n / 2;
        }
      }
    }
  }
  cout << m << " " << k;
}
