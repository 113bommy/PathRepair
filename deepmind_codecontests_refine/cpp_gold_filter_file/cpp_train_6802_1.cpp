#include <bits/stdc++.h>
using namespace std;
int main() {
  double S, a, b, c;
  cin >> S >> a >> b >> c;
  if (a == 0 && b == 0 && c == 0)
    cout << "0 0 0";
  else {
    cout << fixed << setprecision(14) << a * S / (a + b + c) << " "
         << b * S / (a + b + c) << " " << c * S / (a + b + c);
  }
  return 0;
}
