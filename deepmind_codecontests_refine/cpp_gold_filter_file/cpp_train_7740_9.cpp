#include <bits/stdc++.h>
using namespace std;
int main() {
  long long xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya;
  cin >> xb >> yb;
  cin >> xc >> yc;
  long long p, q, r, s;
  p = xb - xa;
  q = yb - ya;
  r = xc - xb;
  s = yc - yb;
  long long sum = 0;
  sum = p * s - q * r;
  if (sum < 0)
    cout << "RIGHT\n";
  else if (sum > 0)
    cout << "LEFT\n";
  else
    cout << "TOWARDS\n";
}
