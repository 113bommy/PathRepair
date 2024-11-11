#include <bits/stdc++.h>
using namespace std;
string S[] = {"x^y^z",   "x^z^y",   "(x^y)^z", "(x^z)^y", "y^x^z",   "y^z^x",
              "(y^x)^z", "(y^z)^x", "z^x^y",   "z^y^x",   "(z^x)^y", "(z^y)^x"};
int ans;
long double Max;
void cmp1(long double x, double y, long double z, int l) {
  long double tmp = log(x) * pow(y, z);
  if (tmp > Max) {
    Max = tmp;
    ans = l;
  }
}
void cmp2(long double x, long double y, long double z, int l) {
  long double tmp = log(x) * y * z;
  if (tmp > Max) {
    Max = tmp;
    ans = l;
  }
}
int main() {
  long double x, y, z;
  cin >> x >> y >> z;
  Max = log(x) * pow(y, z);
  cmp1(x, z, y, 1);
  cmp2(x, y, z, 2);
  cmp1(y, x, z, 4);
  cmp1(y, z, x, 5);
  cmp2(y, x, z, 6);
  cmp1(z, x, y, 8);
  cmp1(z, y, x, 9);
  cmp2(z, x, y, 10);
  cout << S[ans] << endl;
  return 0;
}
