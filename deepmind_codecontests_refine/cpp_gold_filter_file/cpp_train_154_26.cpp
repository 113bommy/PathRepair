#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 15;
string ans[MAXN] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
                    "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
                    "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
long double x, y, z, a[MAXN], ma;
int flag;
int main(int argc, char const *argv[]) {
  cin >> x >> y >> z;
  ma = a[0] = pow(y, z) * log(x);
  a[1] = pow(z, y) * log(x);
  a[2] = a[3] = z * y * log(x);
  a[4] = pow(x, z) * log(y);
  a[5] = pow(z, x) * log(y);
  a[6] = a[7] = x * z * log(y);
  a[8] = pow(x, y) * log(z);
  a[9] = pow(y, x) * log(z);
  a[10] = a[11] = x * y * log(z);
  for (int i = 1; i < 12; ++i)
    if (a[i] > ma) {
      ma = a[i];
      flag = i;
    }
  cout << ans[flag] << endl;
  return 0;
}
