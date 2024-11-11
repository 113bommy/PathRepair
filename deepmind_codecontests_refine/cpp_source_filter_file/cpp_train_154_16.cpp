#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-10;
int cmp(long double x) {
  if (x < -eps) return -1;
  return x > eps;
}
string s[9] = {"x^y^z",   "x^z^y", "(x^y)^z", "y^x^z",  "y^z^x",
               "(y^x)^z", "z^x^y", "z^y^x",   "(z^x)^y"};
int main() {
  long double x, y, z, ans = 1e100, l[10];
  cin >> x >> y >> z;
  for (int i = 0; i < 9; i++) l[i] = -1e100;
  if (cmp(x - 1) == 1) {
    l[0] = z * log(y) + log(log(x));
    l[1] = y * log(z) + log(log(x));
    l[2] = log(y * z * log(x));
  }
  if (cmp(y - 1) == 1) {
    l[3] = z * log(x) + log(log(y));
    l[4] = x * log(z) + log(log(y));
    l[5] = log(x * z * log(y));
  }
  if (cmp(z - 1) == 1) {
    l[6] = y * log(x) + log(log(z));
    l[7] = x * log(y) + log(log(z));
    l[8] = log(y * x * log(z));
  }
  for (int i = 0; i < 9; i++) ans = max(ans, l[i]);
  if (cmp(ans + 1e100) == 1) {
    for (int i = 0; i < 9; i++)
      if (cmp(l[i] - ans) != -1) {
        cout << s[i] << endl;
        return 0;
      }
  }
  if (cmp(x - 1) == 0) {
    cout << s[0] << endl;
    return 0;
  }
  if (cmp(y - 1) == 0) {
    cout << s[3] << endl;
    return 0;
  }
  if (cmp(z - 1) == 0) {
    cout << s[6] << endl;
    return 0;
  }
  l[0] = z * log(y) + log(-log(x));
  l[1] = y * log(z) + log(-log(x));
  l[2] = log(-y * z * log(x));
  l[3] = z * log(x) + log(-log(y));
  l[4] = x * log(z) + log(-log(y));
  l[5] = log(-x * z * log(y));
  l[6] = y * log(x) + log(-log(z));
  l[7] = x * log(y) + log(-log(z));
  l[8] = log(-y * x * log(z));
  ans = 1e100;
  for (int i = 0; i < 9; i++) ans = min(ans, l[i]);
  for (int i = 0; i < 9; i++)
    if (cmp(l[i] - ans) != 1) {
      cout << s[i] << endl;
      return 0;
    }
}
