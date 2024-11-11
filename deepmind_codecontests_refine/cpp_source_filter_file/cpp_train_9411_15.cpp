#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x = (a + b + c);
  if (x % 2) {
    cout << "Impossible\n";
    return 0;
  }
  x /= 2;
  if (x < a || x < b || x < c) {
    cout << "Impossible\n";
    return 0;
  }
  cout << x - a << " " << x - b << " " << x - c;
  return 0;
}
