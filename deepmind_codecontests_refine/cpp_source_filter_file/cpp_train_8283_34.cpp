#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, a1 = 0, b1 = 0, c1 = 0, d1 = 0;
  cin >> a >> b >> c >> d;
  if (a != b) a1 = 1;
  if (c != d) b1 = 1;
  if (b && c) c1 = 1;
  if (a != d) d1 = 1;
  if (a1 && b1)
    a1 = 1;
  else
    a1 = 0;
  if (c1 != d1)
    c1 = 1;
  else
    c1 = 0;
  a1 != c1 ? cout << 1 : cout << 0;
  cout << endl;
  return 0;
}
