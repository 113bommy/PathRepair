#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n != 0 && m != 0) {
    if (n >= m) {
      if (2 * sqrt(n * n + m * m) + n <=
          sqrt(n * n + m * m) + 2 * sqrt(n * n + (m - 1) * (m - 1))) {
        cout << n << " " << m - 1 << endl;
        cout << 0 << " " << 0 << endl;
        cout << n << " " << m << endl;
        cout << 0 << " " << 1 << endl;
      } else {
        cout << n << " " << m << endl;
        cout << 0 << " " << 0 << endl;
        cout << n << " " << 0 << endl;
        cout << 0 << " " << m << endl;
      }
    } else {
      if (2 * sqrt(n * n + m * m) + n <=
          sqrt(n * n + m * m) + 2 * sqrt((n - 1) * (n - 1) + m * m)) {
        cout << n - 1 << " " << m << endl;
        cout << 0 << " " << 0 << endl;
        cout << n << " " << m << endl;
        cout << 1 << " " << 0 << endl;
      } else {
        cout << n << " " << m << endl;
        cout << 0 << " " << 0 << endl;
        cout << 0 << " " << m << endl;
        cout << n << " " << 0 << endl;
      }
    }
  } else {
    if (n == 0) {
      cout << "0 " << 1 << endl;
      cout << "0 " << m << endl;
      cout << "0 " << 0 << endl;
      cout << "0 " << m - 1 << endl;
    } else {
      cout << 1 << " 0" << endl;
      cout << n << " 0" << endl;
      cout << 0 << " 0" << endl;
      cout << n - 1 << " 0" << endl;
    }
  }
  return 0;
}
