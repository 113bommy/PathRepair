#include <bits/stdc++.h>
using namespace std;
char str[12][10] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
                    "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
                    "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
bool cmp(complex<long double> x, complex<long double> y) {
  if (imag(x) == 0 && imag(y) == 0) {
    return real(x) > real(y);
  } else if (imag(x) == 0 && imag(y) != 0) {
    return true;
  } else if (imag(x) != 0 && imag(y) == 0) {
    return false;
  } else {
    return real(x) < real(y);
  }
}
complex<long double> arr[12];
int main() {
  long double a, b, c;
  cin >> a >> b >> c;
  complex<long double> x(a, 0.0L);
  complex<long double> y(b, 0.0L);
  complex<long double> z(c, 0.0L);
  arr[0] = z * log(y) + log(log(x));
  arr[1] = y * log(z) + log(log(x));
  arr[2] = log(y * z) + log(log(x));
  arr[3] = arr[2];
  arr[4] = z * log(x) + log(log(y));
  arr[5] = x * log(z) + log(log(y));
  arr[6] = log(x * z) + log(log(y));
  arr[7] = arr[6];
  arr[8] = log(z * x) + log(log(y));
  arr[9] = x * log(y) + log(log(z));
  arr[10] = log(x * y) + log(log(z));
  arr[11] = arr[10];
  int idx = 0;
  for (int i = 1; i < 12; i++) {
    if (cmp(arr[i], arr[idx])) {
      idx = i;
    }
  }
  printf("%s\n", str[idx]);
  return 0;
}
