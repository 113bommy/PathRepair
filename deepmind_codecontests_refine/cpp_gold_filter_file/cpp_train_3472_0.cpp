#include <bits/stdc++.h>
using namespace std;
double calculr2(double p1, double p2, double r1, double A, double B) {
  double r2 = 0;
  r2 = sqrt(((double)B * p1 * r1 * r1) / ((double)A * p2 + B * p1));
  return (r2);
}
int main() {
  int n;
  cin >> n;
  double max1 = 0;
  double r1;
  for (int i = 0; i < n; ++i) {
    cin >> r1;
    if (r1 > max1) max1 = r1;
  }
  int m;
  cin >> m;
  double p1;
  double max2 = 0;
  for (int i = 0; i < m; ++i) {
    cin >> p1;
    if (p1 > max2) max2 = p1;
  }
  int k;
  cin >> k;
  double p2;
  double min1 = 99999;
  for (int i = 0; i < k; ++i) {
    cin >> p2;
    if (p2 < min1) min1 = p2;
  }
  double A, B;
  cin >> A >> B;
  double r2;
  r2 = calculr2(max2, min1, max1, A, B);
  cout << fixed << setprecision(12) << r2;
  return 0;
}
