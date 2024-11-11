#include <bits/stdc++.h>
using namespace std;
double n, r;
int main() {
  cin >> n >> r;
  double a = M_PI / n, b = 3 * M_PI / (2 * n);
  cout << setprecision(50)
       << n * r * r * (cos(a) * sin(a) - sin(a) * sin(a) / tan(b)) << endl;
  return 0;
}
