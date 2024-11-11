#include <bits/stdc++.h>
using namespace std;
const int UNDEF = -1;
const int INF = 2000000000;
const long long INF64 = 4000000000000000000;
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
template <typename T>
T sqr(const T &x) {
  return x * x;
}
template <typename T>
const string GetString(const T &val) {
  ostringstream sout;
  sout << val;
  return sout.str();
}
double s;
double a, b, c;
int main() {
  double s;
  double a, b, c;
  cin >> s;
  cin >> a >> b >> c;
  if (fabs(a) < EPS && fabs(b) < EPS && fabs(c) < EPS) {
    cout << "0 0 0" << endl;
    return 0;
  }
  double sum = a + b + c;
  double x = s * a / sum;
  double y = s * b / sum;
  double z = s * c / sum;
  printf("%.12f %.12f %.12f\n", x, y, z);
  return 0;
}
