#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, a, b;
  cin >> x >> y;
  a = log(x) * y;
  b = log(y) * x;
  if (a > b) {
    cout << ">\n";
    return 0;
  }
  if (a < b) {
    cout << "<\n";
    return 0;
  }
  cout << "=\n";
  return 0;
}
