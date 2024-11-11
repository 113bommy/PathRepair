#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a;
  cin >> b;
  if ((a > 0) && (b > 0))
    cout << 0 << " " << a + b << " " << a + b << " " << 0;
  else if ((a < 0) && (b > 0))
    cout << -a + b << " " << 0 << " " << 0 << " " << a - b;
  else if ((a > 0) && (b < 0))
    cout << 0 << " " << b - a << " " << -b + a << " " << 0;
  else
    cout << a + b << " " << 0 << " " << 0 << " " << a + b;
  return 0;
}
