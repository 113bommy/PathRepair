#include <bits/stdc++.h>
using namespace std;
int main() {
  double x, y, z;
  cin >> x >> y >> z;
  double arr[12];
  fill(arr, arr + 12, INT_MIN);
  bool flag = false;
  if (x <= 1 and y <= 1 and z <= 1) flag = 1;
  if (x >= 1) {
    if (x == 1)
      arr[0] = arr[1] = arr[2] = arr[3] = INT_MIN;
    else {
      arr[0] = log(log(x)) + z * log(y);
      arr[1] = log(log(x)) + y * log(z);
      arr[2] = log(log(x)) + log(y) + log(z);
      arr[3] = log(log(x)) + log(y) + log(z);
    }
  }
  if (x < 1 and flag) {
    arr[0] = log(log(1 / x)) + z * log(y);
    arr[1] = log(log(1 / x)) + y * log(z);
    arr[2] = log(log(1 / x)) + log(y) + log(z);
    arr[3] = log(log(1 / x)) + log(y) + log(z);
  }
  if (y >= 1) {
    if (y == 1)
      arr[4] = arr[5] = arr[6] = arr[7] = INT_MIN;
    else {
      arr[4] = log(log(y)) + z * log(x);
      arr[5] = log(log(y)) + x * log(z);
      arr[6] = log(log(y)) + log(z) + log(x);
      arr[7] = log(log(y)) + log(z) + log(x);
    }
  }
  if (y < 1 and flag) {
    arr[4] = log(log(1 / y)) + z * log(x);
    arr[5] = log(log(1 / y)) + x * log(z);
    arr[6] = log(log(1 / y)) + log(z) + log(x);
    arr[7] = log(log(1 / y)) + log(z) + log(x);
  }
  if (z >= 1) {
    if (z == 1)
      arr[8] = arr[9] = arr[10] = arr[11] = INT_MIN;
    else {
      arr[8] = log(log(z)) + y * log(x);
      arr[9] = log(log(z)) + x * log(y);
      arr[10] = log(log(z)) + log(x) + log(y);
      arr[11] = log(log(z)) + log(x) + log(y);
    }
  }
  if (z < 1 and flag) {
    arr[8] = log(log(1 / z)) + y * log(x);
    arr[9] = log(log(1 / z)) + x * log(y);
    arr[10] = log(log(1 / z)) + log(x) + log(y);
    arr[11] = log(log(1 / z)) + log(x) + log(y);
  }
  map<double, string> m;
  m[0] = "x^y^z";
  m[1] = "x^z^y";
  m[2] = "(x^y)^z";
  m[3] = "(x^z)^y";
  m[4] = "y^x^z";
  m[5] = "y^z^x";
  m[6] = "(y^x)^z";
  m[7] = "(y^z)^x";
  m[8] = "z^x^y";
  m[9] = "z^y^x";
  m[10] = "(z^x)^y";
  m[11] = "(z^y)^x";
  int ans = -1;
  double maximum = -(1e12);
  double minimum = 1e12;
  for (int i = 0; i < 12; ++i)
    if (flag) {
      if (arr[i] < minimum) {
        minimum = arr[i];
        ans = i;
      }
    } else {
      if (arr[i] > maximum) {
        maximum = arr[i];
        ans = i;
      }
    }
  cout << m[ans] << endl;
}
