#include <bits/stdc++.h>
const int SZ = 1e5 + 5;
using namespace std;
int main() {
  long double x, y, z;
  cin >> x >> y >> z;
  string s[12];
  vector<long double> v;
  v.push_back(pow(y, z) * log(x));
  s[0] = "x^y^z";
  v.push_back(pow(z, y) * log(x));
  s[1] = "x^z^y";
  v.push_back(z * log(pow(x, y)));
  s[2] = "(x^y)^z";
  v.push_back(y * log(pow(x, z)));
  s[3] = "(x^z)^y";
  v.push_back(pow(x, z) * log(y));
  s[4] = "y^x^z";
  v.push_back(pow(z, x) * log(y));
  s[5] = "y^z^x";
  v.push_back(z * log(pow(y, x)));
  s[6] = "(y^x)^z";
  v.push_back(x * log(pow(y, z)));
  s[7] = "(y^z)^x";
  v.push_back(pow(x, y) * log(z));
  s[8] = "z^x^y";
  v.push_back(pow(y, x) * log(z));
  s[9] = "z^y^x";
  v.push_back(y * log(pow(z, x)));
  s[10] = "(z^x)^y";
  v.push_back(x * log(pow(z, y)));
  s[11] = "(z^y)^x";
  int idx = 0;
  for (int i = 1; i < 12; i++)
    if (v[i] - v[idx] > 1e-9) idx = i;
  cout << s[idx];
}
