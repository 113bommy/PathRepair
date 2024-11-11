#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n && m) {
    float x = n, y = m;
    float length1 =
        sqrt(x * x + y * y) +
        sqrt((min(x, y) - 1) * (min(x, y) - 1) + max(x, y) * max(x, y)) * 2;
    float length2 = sqrt(x * x + y * y) * 2 + max(x, y);
    if (length1 > length2) {
      if (n < m) {
        cout << n - 1 << ' ' << m << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << n << ' ' << m << endl;
        cout << 1 << ' ' << 0 << endl;
      } else {
        cout << n << ' ' << m - 1 << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << n << ' ' << m << endl;
        cout << 0 << ' ' << 1 << endl;
      }
    } else {
      cout << n << ' ' << m << endl;
      cout << 0 << ' ' << 0 << endl;
      if (n > m) {
        cout << n << ' ' << 0 << endl;
        cout << 0 << ' ' << m << endl;
      } else {
        cout << 0 << ' ' << m << endl;
        cout << n << ' ' << 0 << endl;
      }
    }
  } else {
    if (n) {
      cout << 1 << ' ' << 0 << endl;
      cout << n << ' ' << 0 << endl;
      cout << 0 << ' ' << 0 << endl;
      cout << n - 1 << ' ' << 0 << endl;
    }
    if (m) {
      cout << 0 << ' ' << 1 << endl;
      cout << 0 << ' ' << m << endl;
      cout << 0 << ' ' << 0 << endl;
      cout << 0 << ' ' << m - 1 << endl;
    }
  }
  return 0;
}
