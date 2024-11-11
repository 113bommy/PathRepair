#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  a--;
  b--;
  if (a / m == b / m) {
    cout << 1;
    return 0;
  }
  if (a == 1 && b == n - 1) {
    cout << 1;
    return 0;
  }
  if (a % m == 0 && b % m == m - 1) {
    cout << 1;
    return 0;
  }
  if (a / m + 1 == b / m) {
    cout << 2;
    return 0;
  }
  if (a % m == 0 || b % m == m - 1) {
    cout << 2;
    return 0;
  }
  if (a % m == b % m + 1) {
    cout << 2;
    return 0;
  }
  if (b == n - 1) {
    cout << 2;
    return 0;
  }
  cout << 3;
  return 0;
}
