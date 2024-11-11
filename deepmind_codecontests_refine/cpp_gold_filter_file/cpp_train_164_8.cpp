#include <bits/stdc++.h>
using namespace std;
long long xa, xb, xc, ya, yb, yc;
int main() {
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  if (xc + xa == 2 * xb && ya + yc == 2 * yb)
    cout << "No";
  else if ((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb) ==
           (xc - xb) * (xc - xb) + (yc - yb) * (yc - yb))
    cout << "Yes";
  else
    cout << "No";
}
