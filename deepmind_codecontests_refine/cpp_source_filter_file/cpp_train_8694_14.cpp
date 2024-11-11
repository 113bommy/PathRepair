#include <bits/stdc++.h>
using namespace std;
int main() {
  long double a, b, c;
  long double disk;
  cin >> a >> b >> c;
  disk = (b * b) - (4 * a * c);
  long double x1, x2;
  x1 = (-b - sqrt(disk)) / (2 * a);
  x2 = (-b + sqrt(disk)) / (2 * a);
  if (x1 < x2) {
    swap(x1, x2);
  }
  cout.precision(6);
  cout << x1 << endl << x2 << endl;
}
