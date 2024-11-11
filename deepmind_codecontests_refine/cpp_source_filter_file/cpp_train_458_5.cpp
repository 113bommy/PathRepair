#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l;
  cin >> n >> m >> l;
  n = n - 2 * (l - 1);
  m = m - 2 * (l - 1);
  if (n <= 0 || m <= 0) {
    cout << 0;
    return 0;
  }
  int x = 0;
  if (n == 1) {
    cout << (m + 1) / 2;
    return 0;
  }
  if (m == 1) {
    cout << (n + 1) / 2;
    return 0;
  }
  if (n % 2 == 0 && m % 2 == 0) {
    cout << m + n;
  }
  if (n % 2 == 1 && m % 2 == 0) {
    cout << m + n - 2;
  }
  if (n % 2 == 0 && m % 2 == 1) {
    cout << m + n - 2;
  }
  if (n % 2 == 1 && m % 2 == 1) {
    cout << m + 1 + n - 3;
  }
  return 0;
}
