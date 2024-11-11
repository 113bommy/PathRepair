#include <bits/stdc++.h>
using namespace std;
int main() {
  long int x, y, z, a, b, c;
  long long int s1, s;
  int f1 = 0, f2 = 0, f3 = 0;
  cin >> x >> y >> z >> a >> b >> c;
  if (x <= a) {
    a -= x;
    f1 = 1;
  }
  s1 = a + b;
  if (y <= s1) {
    f2 = 1;
    s1 -= y;
  }
  s = s1 + c;
  if (z <= s) {
    f3 = 1;
  }
  if ((f1 == 1) && (f2 == 1) && (f3 == 1))
    cout << "\nYES";
  else
    cout << "\nNO";
  return 0;
}
