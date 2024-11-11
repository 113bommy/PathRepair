#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const long long INF = (long long)1e18;
int sign(long double x) { return x < -eps ? -1 : x > eps; }
bool bigger(const complex<long double> &a, const complex<long double> &b) {
  if (sign(imag(a)) == 0 && sign(imag(b)) == 0)
    return sign(real(a) - real(b)) > 0;
  if (sign(imag(a)) == 1 && sign(imag(b)) == 1)
    return sign(real(a) - real(b)) < 0;
  return sign(imag(a) - imag(b)) < 0;
}
complex<long double> x, y, z, maxn;
string s = "x^y^z";
int main() {
  cin >> x >> y >> z;
  maxn = z * log(y) + log(log(x));
  if (bigger(y * log(z) + log(log(x)), maxn)) {
    maxn = y * log(z) + log(log(x));
    s = "x^z^y";
  }
  if (bigger(log(y * z) + log(log(x)), maxn)) {
    maxn = log(y * z) + log(log(x));
    s = "(x^y)^z";
  }
  if (bigger(z * log(x) + log(log(y)), maxn)) {
    maxn = z * log(x) + log(log(y));
    s = "y^x^z";
  }
  if (bigger(x * log(z) + log(log(y)), maxn)) {
    maxn = x * log(z) + log(log(y));
    s = "y^z^x";
  }
  if (bigger(log(x * z) + log(log(y)), maxn)) {
    maxn = log(x * z) + log(log(y));
    s = "(y^x)^z";
  }
  if (bigger(y * log(x) + log(log(z)), maxn)) {
    maxn = y * log(x) + log(log(z));
    s = "z^x^y";
  }
  if (bigger(x * log(y) + log(log(z)), maxn)) {
    maxn = x * log(y) + log(log(z));
    s = "z^y^x";
  }
  if (bigger(log(x * y) + log(log(z)), maxn)) {
    maxn = log(x * y) + log(log(z));
    s = "(z^x)^y";
  }
  cout << s << endl;
  return 0;
}
