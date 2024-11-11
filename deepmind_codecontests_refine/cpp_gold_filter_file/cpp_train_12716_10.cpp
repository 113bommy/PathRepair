#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, x, y;
  cin >> a >> b >> c;
  if (a > b)
    x = 2 * b + 1;
  else if (b > a)
    x = 2 * a + 1;
  else if (a == b)
    x = 2 * a;
  y = 2 * c;
  cout << x + y;
}
