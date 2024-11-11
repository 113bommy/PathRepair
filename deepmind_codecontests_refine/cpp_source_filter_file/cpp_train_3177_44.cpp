#include <bits/stdc++.h>
using namespace std;
int a, b, c, x, y, z;
int main() {
  cin >> a >> b >> c >> x >> y >> z;
  a -= x;
  b -= y;
  c -= z;
  int _a = a / 2, _b = b / 2, _c = c / 2;
  if (a >= 0 && b >= 0 && c >= 0)
    puts("Yes");
  else if (a <= 0 && b >= 0 && c >= 0 && _b + _c + a + 1)
    puts("Yes");
  else if (a >= 0 && b <= 0 && c >= 0 && _a + _c + b + 1)
    puts("Yes");
  else if (a >= 0 && b >= 0 && c <= 0 && _a + _b + c + 1)
    puts("Yes");
  else if (a <= 0 && b <= 0 && c >= 0 && _c + a + b + 1)
    puts("Yes");
  else if (a <= 0 && b >= 0 && c <= 0 && _b + a + c + 1)
    puts("Yes");
  else if (a >= 0 && b <= 0 && c <= 0 && _c + b + c + 1)
    puts("Yes");
  else
    cout << "No";
}
