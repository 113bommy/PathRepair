#include <bits/stdc++.h>
using namespace std;
int main() {
  long long xa, ya, xb, yb, xc, yc, a, A, b;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  if ((xa == xb) && (ya == yb))
    cout << "YES";
  else if ((xb == ya) && (yb == -xa))
    cout << "YES";
  else if ((xb == -xa) && (yb == -ya))
    cout << "YES";
  else if ((xb == -ya) && (yb == xa))
    cout << "YES";
  else if (((xc * xc) + (yc * yc)) == 0)
    cout << "NO";
  else {
    A = (xc * xc) + (yc * yc);
    a = (((xb - xa) * xc) + ((yb - ya) * yc));
    b = (((xb - xa) * (-yc)) + ((yb - ya) * xc));
    if ((a % A == 0) && (b % A == 0)) {
      cout << "YES";
      return 0;
    }
    a = (((xb + ya) * xc) + ((yb - xa) * yc));
    b = (((xb + ya) * (-yc)) + ((yb - xa) * xc));
    if ((a % A == 0) && (b % A == 0)) {
      cout << "YES";
      return 0;
    }
    a = (((xb + xa) * xc) + ((yb + ya) * yc));
    b = (((xb + xa) * (-yc)) + ((yb + ya) * xc));
    if ((a % A == 0) && (b % A == 0)) {
      cout << "YES";
      return 0;
    }
    a = (((xb - ya) * xc) + ((yb + xa) * yc));
    b = (((xb - ya) * (-yc)) + ((yb + xa) * xc));
    if ((a % A == 0) && (b % A == 0)) {
      cout << "YES";
      return 0;
    }
    cout << "NO";
  }
  return 0;
}
