#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (d > 2 * c || d >= b || d >= a || 2 * d < c) {
    cout << "-1";
    return 0;
  }
  cout << max(2 * a, 2 * d + 2) << endl;
  cout << max(2 * b, 2 * d + 1) << endl;
  cout << max(c, d) << endl;
  return 0;
}
