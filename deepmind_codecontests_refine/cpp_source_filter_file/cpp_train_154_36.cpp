#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
string ans[] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
                "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
                "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
long double x, y, z;
void solve() {
  cin >> x >> y >> z;
  int index = 0;
  if (max(x, max(y, z)) < 1.0 - EPS) {
    long double maxi = powl(x, powl(y, z));
    if (powl(x, powl(z, y)) > maxi + EPS) {
      maxi = powl(x, powl(z, y));
      index = 1;
    }
    if (powl(x, y * z) > maxi + EPS) {
      maxi = powl(x, y * z);
      index = 2;
    }
    if (powl(y, powl(x, z)) > maxi + EPS) {
      maxi = powl(y, powl(x, z));
      index = 4;
    }
    if (powl(y, powl(z, x)) > maxi + EPS) {
      maxi = powl(y, powl(z, x));
      index = 5;
    }
    if (powl(y, x * z) > maxi + EPS) {
      maxi = powl(y, x * z);
      index = 6;
    }
    if (powl(z, powl(x, y)) > maxi + EPS) {
      maxi = powl(z, powl(x, y));
      index = 8;
    }
    if (powl(z, powl(y, x)) > maxi + EPS) {
      maxi = powl(z, powl(y, x));
      index = 9;
    }
    if (powl(z, x * y) > maxi + EPS) {
      index = 10;
    }
  } else {
    long double maxi = (x > 1.0 - EPS) ? z * logl(y) + logl(logl(x)) : 0.0;
    if (x > 1.0 - EPS && y * logl(z) + logl(logl(x)) > maxi + EPS) {
      maxi = y * logl(z) + logl(logl(x));
      index = 1;
    }
    if (x > 1.0 - EPS && logl(y * z) + logl(logl(x)) > maxi + EPS) {
      maxi = logl(y * z) + logl(logl(x));
      index = 2;
    }
    if (y > 1.0 - EPS && z * logl(x) + logl(logl(y)) > maxi + EPS) {
      maxi = z * logl(x) + logl(logl(y));
      index = 4;
    }
    if (y > 1.0 - EPS && x * logl(z) + logl(logl(y)) > maxi + EPS) {
      maxi = x * logl(z) + logl(logl(y));
      index = 5;
    }
    if (y > 1.0 - EPS && logl(x * z) + logl(logl(y)) > maxi + EPS) {
      maxi = logl(x * z) + logl(logl(y));
      index = 6;
    }
    if (z > 1.0 - EPS && y * logl(x) + logl(logl(z)) > maxi + EPS) {
      maxi = y * logl(x) + logl(logl(z));
      index = 8;
    }
    if (z > 1.0 - EPS && x * logl(y) + logl(logl(z)) > maxi + EPS) {
      maxi = x * logl(y) + logl(logl(z));
      index = 9;
    }
    if (z > 1.0 - EPS && logl(x * y) + logl(logl(z)) > maxi + EPS) {
      index = 10;
    }
  }
  cout << ans[index] << endl;
}
int main() {
  solve();
  return 0;
}
