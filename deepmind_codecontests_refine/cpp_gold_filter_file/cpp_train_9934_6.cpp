#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  char ch, chr;
  cin >> a >> ch >> b;
  cin >> c >> chr >> d;
  if (b < d)
    b += 60, a--, d = b - d;
  else
    d = b - d;
  if (a < c)
    a += 24, c = a - c;
  else
    c = a - c;
  if (c <= 9) cout << "0";
  cout << c << ":";
  if (d <= 9) cout << "0";
  cout << d << endl;
  return 0;
}
