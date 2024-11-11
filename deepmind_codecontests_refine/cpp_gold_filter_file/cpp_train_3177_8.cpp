#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x, y, z;
  cin >> x >> y >> z;
  int d1, d2, d3;
  d1 = x - a;
  d2 = y - b;
  d3 = z - c;
  int e1, e2, e3;
  if (d1 <= 0) {
    e1 = (d1 * -1) / 2;
    d1 /= 2;
  }
  if (d2 <= 0) {
    e2 = (d2 * -1) / 2;
    d2 /= 2;
  }
  if (d3 <= 0) {
    e3 = (d3 * -1) / 2;
    d3 /= 2;
  }
  if (d1 == 0 && d2 == 0 && d3 == 0) {
    cout << "Yes\n";
    return 0;
  }
  if (d1 + d2 <= e3 && d1 + d3 <= e2 && d2 + d3 <= e1) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
  return 0;
}
