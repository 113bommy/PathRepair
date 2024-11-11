#include <bits/stdc++.h>
using namespace std;
string s[12] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
                "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
                "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
long double ans[15];
int main() {
  long double x, y, z;
  cin >> x >> y >> z;
  long double xx = logl(x);
  long double yy = logl(y);
  long double zz = logl(z);
  ans[1] = xx * powl(y, z);
  ans[2] = xx * powl(z, y);
  ans[3] = xx * y * z;
  ans[4] = xx * y * z;
  ans[5] = yy * powl(x, z);
  ans[6] = yy * powl(z, x);
  ans[7] = yy * x * z;
  ans[8] = yy * x * z;
  ans[9] = zz * powl(x, y);
  ans[10] = zz * powl(y, x);
  ans[11] = zz * x * y;
  ans[12] = zz * y * x;
  int j = 1;
  long double sum = ans[1];
  for (int i = 1; i <= 12; i++) {
    if (sum < ans[i]) {
      sum = ans[i];
      j = i;
    }
  }
  cout << s[j - 1] << endl;
}
