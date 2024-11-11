#include <bits/stdc++.h>
using namespace std;
const int MM = 1e9 + 7;
const int INF = INT_MAX;
const long double PI = 3.1415926535897;
const long double EPS = 1e-12;
int n, c;
long double x, y, z, res = -1e100;
bool ls;
string M[] = {"",      "x^y^z",   "x^z^y",   "(x^y)^z", "(x^y)^z",
              "y^x^z", "y^z^x",   "(y^x)^z", "(y^x)^z", "z^x^y",
              "z^y^x", "(z^x)^y", "(z^x)^y", ""};
void f1(long double xx, long double yy, long double zz, int num) {
  long double tmp;
  if (!ls) {
    tmp = log(log(xx)) + zz * log(yy);
  } else {
    tmp = pow(xx, pow(yy, zz));
  }
  if (tmp - res >= EPS) {
    res = tmp;
    c = num;
  }
}
void f2(long double x, long double y, long double z, int num) {
  long double tmp;
  if (!ls) {
    tmp = log(y * z * log(x));
  } else {
    tmp = pow(x, y * z);
  }
  if (tmp - res >= EPS) {
    res = tmp;
    c = num;
  }
}
int main() {
  cin >> x >> y >> z;
  ls = x < 1 && y < 1 && z < 1;
  f1(x, y, z, 1);
  f1(x, z, y, 2);
  f2(x, y, z, 3);
  f1(y, x, z, 5);
  f1(y, z, x, 6);
  f2(y, x, z, 7);
  f1(z, x, y, 9);
  f1(z, y, x, 10);
  f2(z, x, y, 11);
  cout << M[c] << endl;
  return 0;
}
