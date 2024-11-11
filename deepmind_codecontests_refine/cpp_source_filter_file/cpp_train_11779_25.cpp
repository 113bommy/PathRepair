#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int x, y, z;
int main() {
  cin >> x >> y >> z;
  cin >> a >> b >> c;
  if (a < x) {
    cout << "NO";
    return 0;
  }
  x -= a;
  if (a + b < y) {
    cout << "NO";
    return 0;
  }
  c += a + b - y;
  if (c < z) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
