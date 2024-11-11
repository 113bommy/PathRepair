#include <bits/stdc++.h>
using namespace std;
double n, p;
double a[100009], b[100009];
int condition(double val) {
  int i;
  double val1, val2, val3 = 0;
  for (i = 0; i < n; i++) {
    val2 = b[i] / a[i];
    if (val <= val2) {
      continue;
    }
    val1 = a[i] * val - b[i];
    val3 += val1;
  }
  if (val3 > p * val) {
    return 1;
  } else {
    return 0;
  }
}
double binary(double l, double r) {
  int i;
  double mid;
  for (i = 0; i < 220; i++) {
    mid = (l + r) / 2;
    if (condition(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return mid;
}
int main() {
  int i;
  double sum = 0;
  double ans;
  cin >> n >> p;
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    sum += a[i];
  }
  if (sum <= p) {
    cout << "-1\n";
  } else {
    ans = binary(0, 10000000009);
    printf("%.10lf", ans);
  }
  return 0;
}
