#include <bits/stdc++.h>
using namespace std;
long double x, y, z;
long double num[50];
char s[15][15] = {" ",     "x^y^z",   "x^z^y",   "(x^y)^z", "(x^z)^y",
                  "y^x^z", "y^z^x",   "(y^x)^z", "(y^z)^x", "z^x^y",
                  "z^y^x", "(z^x)^y", "(z^y)^x"};
int main() {
  while (cin >> x >> y >> z) {
    long double maxn = 0;
    char ans[15];
    num[1] = pow(y, z) * log(x);
    num[2] = pow(z, y) * log(x);
    num[3] = y * z * log(x);
    num[4] = y * z * log(x);
    num[5] = pow(x, z) * log(y);
    num[6] = pow(z, x) * log(y);
    num[7] = x * z * log(y);
    num[8] = x * z * log(y);
    num[9] = pow(x, y) * log(z);
    num[10] = pow(y, x) * log(z);
    num[11] = x * y * log(z);
    num[12] = x * y * log(z);
    for (int i = 1; i <= 12; i++) {
      if (num[i] > maxn) {
        maxn = num[i];
        strcpy(ans, s[i]);
      }
    }
    cout << ans << endl;
  }
}
