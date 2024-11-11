#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, s = 0, x = 0, c;
  cin >> n;
  while (n > 0) {
    c = n % 10;
    x++;
    if (x == 1)
      s = s + c * 100;
    else if (x == 2)
      s = s + c * 10;
    else if (x == 3)
      s = s + c * 1000;
    else if (x == 4)
      s = s + c * 1;
    else
      s = s + c * 10000;
    n = n / 10;
  }
  s = s * s % 100000 * s % 100000 * s % 100000 * s % 100000;
  if (s == 0)
    cout << 00000;
  else
    cout << s << endl;
  return 0;
}
