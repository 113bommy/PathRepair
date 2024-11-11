#include <bits/stdc++.h>
using namespace std;
double Pi = 3.1415;
double rad(double deg) { return Pi * deg / 180; }
int main() {
  cout.setf(ios::fixed);
  cout.precision(9);
  double n, r;
  cin >> n >> r;
  double R = sin(rad(180 / n)) * r / (1 - sin(rad(180 / n)));
  cout << R;
  return 0;
}
