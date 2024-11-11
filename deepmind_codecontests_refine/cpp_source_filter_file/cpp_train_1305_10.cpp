#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, n;
  cin >> a >> b >> c;
  if (c > 0 || c < 0)
    n = (b - a) / c;
  else
    n = b - a;
  if (b == a + (n * c) && n >= 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
