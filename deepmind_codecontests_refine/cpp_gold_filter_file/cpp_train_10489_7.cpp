#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  if (a + b > n + c) {
    cout << -1;
    return 0;
  }
  if ((c > a) || (c > b) || (n == 0)) {
    cout << -1;
    return 0;
  }
  if ((a == 0) && (b == 0) && (c == 0)) {
    cout << n;
    return 0;
  }
  a -= c;
  b -= c;
  int q = n - (a + b + c);
  if ((q < n) && (q != 0)) {
    cout << q;
  } else
    cout << -1;
  return 0;
}
