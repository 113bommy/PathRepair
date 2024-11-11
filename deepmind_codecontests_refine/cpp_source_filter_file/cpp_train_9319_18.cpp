#include <bits/stdc++.h>
using namespace std;
double polar(double a, double b) {
  double res;
  res = atan2(a, b);
  if (res < 0) res += 2 * 3.14159265358979323846;
  return res;
}
double vec2(double x, double y, double x1, double y1) {
  x = atan2(y, x);
  x1 = atan2(y1, x1);
  x = fabs(x - x1);
  if (x > 3.14159265358979323846) x = 2 * 3.14159265358979323846 - x;
  return x;
}
long long A[1005], B[10005];
int main() {
  long long n, max = -1;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  for (int i = 0; i < n; ++i) cin >> B[i];
  for (int i = 1; i < n; ++i) {
    long long tempA = 0;
    long long tempB = 0;
    for (int j = 0; j <= i; ++j) {
      tempA |= A[j];
      tempB |= B[j];
      if (tempA + tempB > max) max = tempA + tempB;
    }
  }
  cout << max;
  return 0;
}
