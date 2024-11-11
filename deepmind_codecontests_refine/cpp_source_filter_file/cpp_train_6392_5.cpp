#include <bits/stdc++.h>
using namespace std;
double fer(double a) {
  if (a <= 0) return 0;
  if (a == 1) return 2;
  return a * (a + 1) + fer(a - 1);
}
int main() {
  double m, r, dia;
  cin >> m >> r;
  dia = sqrt(r * r * 2);
  double tot = 0;
  tot += (2 * r) / m;
  tot += ((m - 1) * (2 * r + dia) / (m * m)) * 2;
  double n = m - 2, R = 2 * r;
  tot += (dia * (n * m - ((n * (n + 1)) / 2 + n))) / (m * m) * 2;
  tot += (R * (((n * (n + 1) / 2) * m - fer(n)))) / (m * m) * 2;
  printf("%.10f", tot);
  cout << endl;
  cin >> m;
}
