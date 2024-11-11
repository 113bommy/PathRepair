#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  int c;
  cin >> a >> b;
  c = abs(a) + abs(b);
  if (a >= 0 && b >= 0)
    cout << 0 << " " << c << " " << c << " " << 0 << endl;
  else if (a < 0 && b > 0)
    cout << -c << " " << 0 << " " << 0 << " " << c << endl;
  else if (a >= 0 && b < 0)
    cout << 0 << " " << c << " " << -c << " " << 0 << endl;
  else
    cout << -c << " " << 0 << " " << 0 << " " << -c << endl;
  return 0;
}
