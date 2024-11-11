#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int main() {
  cin >> n >> m >> a >> b;
  int k = 3;
  if (a == b || m == 1) {
    cout << 1 << endl;
    return 0;
  }
  if ((a + m - 1) / m == (b + m - 1) / m) {
    cout << 1 << endl;
    return 0;
  }
  if (a % m == 1 && b % m == 0) {
    cout << 1 << endl;
    return 0;
  }
  if (a % m == 1 && b == n) {
    cout << 1 << endl;
    return 0;
  }
  bool b = true;
  if (a % m == 1) {
    k--;
    b = false;
  }
  if (b % m == 0 || b == n) {
    k--;
    b = false;
  }
  if ((b % m + 1 == a % m && b % m != 0 && a % m != 0) ||
      (a % m == 0 && b % m == m - 1)) {
    cout << 2 << endl;
    return 0;
  }
  if ((b + m - 1) / m - (a + m - 1) / m == 1 &&
      (a % m > b % m || (a % m == 0 && b % m != 0))) {
    cout << 2 << endl;
    return 0;
  }
  if ((b + m - 1) / m - (a + m - 1) / m <= 1 && !(a % m == 1 && b % m == 0) &&
      b) {
    k--;
  }
  cout << k << endl;
  return 0;
}
