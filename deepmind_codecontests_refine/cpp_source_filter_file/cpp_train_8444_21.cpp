#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, a, b, c;
int main() {
  cin >> a >> b >> c;
  if (c <= a + 2 || c <= b + 1) {
    cout << (3 * c) - 3;
    return 0;
  }
  if (b <= a + 1) {
    cout << 3 * b;
    return 0;
  }
  cout << (3 * a) + 3;
  return 0;
}
