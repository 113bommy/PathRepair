#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, x, y, z;
  cin >> a >> b >> c >> x >> y >> z;
  long long int a1, b1, c1;
  a1 = a - x;
  b1 = b - y;
  c1 = c - z;
  long long int pol = 0, otr = 0;
  pol += max(a1 / 2, (long long)0) + max(b1 / 2, (long long)0) +
         max(c1 / 2, (long long)0);
  otr += min(a1, (long long)0) + min(b1, (long long)0) + min(c1, (long long)0);
  if (pol + otr >= 0)
    cout << "Yes";
  else
    cout << "No";
  cin.get();
  cin.get();
  return 0;
}
