#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double rez = (1.0 / 24) * (5 + sqrt(5)) * (c * c * c);
  rez += sqrt(2) * (1.0 / 6) * b * b * b;
  rez += (a * a * a) / (6 * sqrt(2));
  cout << setprecision(12) << fixed << rez;
  return 0;
}
